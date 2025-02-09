#include "smtpclient.h"
#include <QEventLoop>

SmtpClient::SmtpClient(int port,ConnectionType ctype) :
    name("localhost"),
    state(UnconnectedState),
    isConnected(false)
{
    _ctype = ctype;
    if (ctype == TcpConnection)
        _socket = new QTcpSocket(this);
    else
        _socket = new QSslSocket;
    this->_port = port;
}

bool SmtpClient::connectToHost()
{
    if (state != UnconnectedState)
        return false;
    changeState(ConnectingState);
    return true;
}

void SmtpClient::changeState(SmtpClient::ClientStat state)
{
    this->state = state;
    switch(state)
    {
    case ConnectingState:
        switch(_ctype)
        {
        case TcpConnection:
            _socket->connectToHost(_host,_port);
            break;
        case SslConnection:
        case TlsConnection:
            ((QSslSocket*) _socket)->connectToHost(_host,_port);
            connect(_socket,SIGNAL(encrypted()),this,SLOT(socketEncrypted()));
            break;
        }
        break;
    case _EHLO_State:
        sendMessage("EHLO " + name);
        break;

    /* TLS */
    case _TLS_State:
        changeState(_TLS_0_STARTTLS);
        break;
    case _TLS_1_ENCRYPT:
        ((QSslSocket*) _socket)->startClientEncryption();
        break;
    case _TLS_2_EHLO:
        sendMessage("EHLO " + name);
        break;
    default:
        break;
    }

}

void SmtpClient::read_new_data()
{
    QString responseLine;
    if (!_socket->isOpen()) {
        qDebug() << "socket is not open";
        return ;
    }

    while (_socket->canReadLine()) {
        responseLine = _socket->readLine();

        responseCode = responseLine.left(3).toInt();
        if (responseCode/100 == 4) {
            qDebug() << "read data:Server Error";
            return ;
        }

        if (responseCode/100 == 5) {
            qDebug() << "read data:Server Error";
            return ;
        }
    }
}

void SmtpClient::sendMessage(const QString &text)
{
    _socket->write(text.toUtf8() + "\r\n");
    _socket->flush();
}
/*
 * Normal TCP:
 * connectToHost => get 220 => EHLO => get 250 -> Connected
 *
 * Ssl:
 * connectToHostEncrypted => get 220 => EHLO => get 250
 * STARTTLS => get 220 => encrypt message =>
 * EHLO => get 250 -> Connected
 *
 */

void SmtpClient::processResponse()
{
    /* SMTP 返回状态码
     * 211 系统状态或系统帮助响应
     * 214 帮助信息
     * 220 ＜domain＞服务就绪
     * 221 ＜domain＞服务关闭
     * 421 ＜domain＞服务未就绪，关闭传输信道
     * 250 要求的邮件操作完成
     * 251 用户非本地，将转发向＜forward-path＞
    */
    switch (state)
    {
    case ConnectedState:
        if (responseCode != 220) {
            qDebug() << "service not ready";
            return ;
        }
        changeState(_EHLO_State);
        break;
    case _EHLO_State:
        if (responseCode != 250) {
            qDebug() << "Wrong EHLO response";
            return ;
        }
        if (_ctype == TlsConnection) {
            changeState(_TLS_State);
        } else {
            changeState(ReadyState);
            isConnected = true;
            emit readyConnected();
        }
        break;
    case _TLS_0_STARTTLS:
        if (responseCode != 220) {
            qDebug() << "TLS: service not ready";
            return ;
        }
        changeState(_TLS_1_ENCRYPT);
        break;
    case _TLS_2_EHLO:
        if (responseCode != 250) {
            qDebug() << "Wrong TLS EHLO response";
            return ;
        }
        changeState(ReadyState);
        isConnected = true;
        emit readyConnected();
        break;
    default:
        break;
    }
}

bool SmtpClient::waitForReadyConnected(int mesc)
{
    if (state ==  UnconnectedState)
        return false;
    if (isConnected)
        return true;

    waitForEvent(mesc,SIGNAL(readyConnected()));

    return isConnected;
}

void SmtpClient::socketEncrypted()
{
    if (state == _TLS_1_ENCRYPT) {
        changeState(_TLS_2_EHLO);
    }
}

void SmtpClient::waitForEvent(int mesc, const char *successSignal)
{
    QEventLoop loop;
}
