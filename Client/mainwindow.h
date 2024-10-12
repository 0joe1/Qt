#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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
    void on_connectButton_clicked();
    void read_new_data();

    void on_sendButton_clicked();

private:
    Ui::MainWindow *ui;
    QTcpSocket *_socket;
    void log(QString text);
    void sendMsg(QString text);
};
#endif // MAINWINDOW_H
