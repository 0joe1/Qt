#ifndef SCANNER_H
#define SCANNER_H

#include <QObject>

class Scanner : public QObject
{
    Q_OBJECT
public:
    explicit Scanner(QObject *parent = nullptr);
    //Scanner(QString ipAddr,int startPort,int endPort);
    //~Scanner();
    void set_ip(const QString ip);
    void set_startPort(int startPort);
    void set_endPort(int endPort);

protected slots:
    void start_scan(void);

signals:
    void port_open(int portnum);
    void sigProgress(int progress);

private:
    QString _ip;
    int _startPort;
    int _endPort;
};

#endif // SCANNER_H
