#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mouseevent.h"
#include <stdio.h>
#include <unistd.h>
#include <QHostAddress>
#include <QDebug>
#include <QMouseEvent>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , _server(NULL)
    , _socket(NULL)
{
    ui->setupUi(this);
    _server = new QTcpServer(this);
    connect(MouseEvent::getInstance(),&MouseEvent::mouseEvent,this,&MainWindow::handle_mouseEvent);
    connect(ui->inMouseButton,&QPushButton::clicked,MouseEvent::getInstance(),&MouseEvent::installMouseEvent);
    connect(ui->rmMouseButton,&QPushButton::clicked,MouseEvent::getInstance(),&MouseEvent::removeMouseEvent);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_listenButton_clicked()
{
    _server->listen(QHostAddress::Any,12345);
    connect(_server,SIGNAL(newConnection()),this,SLOT(handle_new_connection()));
    log(QString("开始监听 %1 %2")
        .arg(_server->serverAddress().toString())
        .arg(_server->serverPort()));
}

void MainWindow::handle_new_connection()
{
    /* 终止上个连接 */
    if (_socket != NULL)
    {
        if (_socket->state() == QAbstractSocket::SocketState::ConnectedState)
            _socket->abort();
        delete _socket;
        _socket = NULL;
    }

    /* 建立新连接 */
    _socket = _server->nextPendingConnection();
    connect(_socket,SIGNAL(readyRead()),this,SLOT(read_new_data()));
    qDebug() << _socket->peerAddress().toString();
    log(QString("new connection from  [IpAddr:%1 Port:%2]")
        .arg(_socket->peerAddress().toString())
        .arg(_socket->peerPort()));
}

void MainWindow::read_new_data()
{
    if (!_socket->isOpen()) {
        qDebug() << "socket is not open";
        return ;
    }
    QString data = _socket->readAll();
    log(data);
    exe_command(data.toUtf8());
}

void MainWindow::log(QString text)
{
    ui->textBrowser->append(text);
}


void MainWindow::on_sendButton_clicked()
{
    QString message = ui->sendLine->text();
    sendMsg(message);
}

void MainWindow::sendMsg(QString text)
{
    _socket->write(text.toUtf8());
    _socket->flush();
}

void MainWindow::handle_mouseEvent(QMouseEvent *event)
{
    switch(event->type())
    {
        case QEvent::MouseButtonPress:
        {
            qDebug() << "MouseButtonPress";
            QString btn;
            switch(event->button())
            {
            case Qt::LeftButton:
                btn = "leftButton";
                break;
            case Qt::MiddleButton:
                btn = "MiddleButton";
                break;
            case Qt::RightButton:
                qDebug() << "right";
                btn = "RightButton";
                break;
            default:
                break;
            }
            qDebug() << btn;
            QString str = QString("press %1 at (x:%2, y:%3)").arg(btn).arg(event->x()).arg(event->y());
            sendMsg(str);
            break;
        }
        case QEvent::MouseMove:     // 鼠标移动
        {
            qDebug()<<"MouseMove";
            QString str = QString("Mouse at (x:%1, y:%2)").arg(event->x()).arg(event->y());
            sendMsg(str);
            break;
        }
        default:
            qDebug()<<"default";
            break;
    }
}


void MainWindow::exe_command(QString command)
{
    FILE *fp;
    char cmd[128];
    strncpy(cmd,command.toUtf8(),sizeof(cmd));
    if (command.startsWith("cd")) {
        QString dir = command.mid(command.indexOf(" ")+1);
        chdir(dir.trimmed().toUtf8());
        return ;
    } else {
        fp = popen(cmd,"r");
    }
    QString msg;
    if (fp == NULL)
    {
        msg = "Failed to execute command";
        sendMsg(msg);
    }
    else
    {
        char buffer[1024] = {0};
        while (fgets(buffer,sizeof(buffer),fp) != NULL) {
            msg += QString::fromLocal8Bit(buffer,strlen(buffer));
            qDebug() << msg;
            memset(buffer,0,sizeof(buffer));
        }
        sendMsg(msg);
        pclose(fp);
    }
}
