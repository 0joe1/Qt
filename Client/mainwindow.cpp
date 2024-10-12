#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _socket = new QTcpSocket(this);
    ui->ipLine->setText("127.0.0.1");
    ui->portLine->setText("12345");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_connectButton_clicked()
{
    QString ip = ui->ipLine->text();
    int port = ui->portLine->text().toInt();

    _socket->abort();

    connect(_socket,SIGNAL(readyRead()),this,SLOT(read_new_data()));
    _socket->connectToHost(ip,port);
    if (_socket->waitForConnected(1000)) {
        log("连接成功");
    }
}

void MainWindow::read_new_data()
{
    if (!_socket->isOpen()) {
        qDebug() << "socket is not open";
        return ;
    }
    log(_socket->readAll());
}

void MainWindow::log(QString text)
{
    ui->textBrowser->append(text);
}

void MainWindow::sendMsg(QString text)
{
    _socket->write(text.toUtf8());
    _socket->flush();
}

void MainWindow::on_sendButton_clicked()
{
    QString message = ui->sendLine->text();
    sendMsg(message);
}
