#ifndef SMTPCLIENT_H
#define SMTPCLIENT_H

#include <QObject>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QSslSocket>

class SmtpClient : public QObject
{
    Q_OBJECT
public:
    enum ConnectionType {
        TcpConnection = 0,
        SslConnection = 1,
        TlsConnection = 2
    };

    enum ClientStat {
        UnconnectedState = 0,
        ConnectingState  = 1,
        ConnectedState   = 2,
        ReadyState       = 3,

        /* Internal States */
        _EHLO_State      = 50,
        _TLS_State       = 51,

        /* TLS State */
        _TLS_0_STARTTLS  = 60,
        _TLS_1_ENCRYPT   = 61,
        _TLS_2_EHLO      = 62
    };

    SmtpClient(int port,ConnectionType ctype);
    bool connectToHost();
    void changeState(ClientStat state);
    void read_new_data(void);
    void sendMessage(const QString &text);
    void processResponse(void);
    bool waitForReadyConnected(int mesc = 30000);

signals:
    void readyConnected();
    void encrypted();

private slots:
    void socketEncrypted(void);

private:
    QString name;
    QTcpSocket *_socket;
    ClientStat state;

    QString _host;
    int _port;
    ConnectionType _ctype;
    int responseCode;
    bool isConnected;

    void waitForEvent(int mesc,const char *successSignal);
};

#endif // SMTPCLIENT_H
