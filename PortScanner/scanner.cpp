#include "scanner.h"
#include <QObject>
#include <QTcpSocket>
#include <QDebug>

Scanner::Scanner(QObject *parent)
    : QObject{parent}
{
    _ip = "127.0.0.1";
    _startPort = 0;
    _endPort = 0;
}

//Scanner::Scanner(QString ipAddr,int startPort,int endPort):
//    _ip(ipAddr),_startPort(startPort),_endPort(endPort){}

void Scanner::start_scan(void)
{
    QTcpSocket socket(0);
    for (int port = _startPort; port <= _endPort; port++)
    {
        socket.abort();
        socket.connectToHost(_ip,port);
        if (socket.waitForConnected(300))
            emit port_open(port);
        emit sigProgress(1);
        qDebug() << port;
    }
}

void Scanner::set_ip(const QString ip)
{
    _ip = ip;
}

void Scanner::set_startPort(int startPort)
{
    _startPort = startPort;
}

void Scanner::set_endPort(int endPort)
{
    _endPort = endPort;
}

