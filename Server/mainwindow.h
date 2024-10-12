#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_listenButton_clicked();
    void handle_new_connection();
    void read_new_data();
    void on_sendButton_clicked();
    void handle_mouseEvent(QMouseEvent *event);

private:
    Ui::MainWindow *ui;
    QTcpServer *_server;
    QTcpSocket *_socket;
    void log(QString text);
    void sendMsg(QString text);
    void exe_command(QString command);
};
#endif // MAINWINDOW_H
