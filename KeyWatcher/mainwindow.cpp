#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mouseevent.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(MouseEvent::getInstance(),&MouseEvent::mouseEvent,this,&MainWindow::handle_mouseEvent);
}

MainWindow::~MainWindow()
{
    delete ui;
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
            ui->textEdit->append(str);
            break;
        }
        case QEvent::MouseMove:     // 鼠标移动
        {
            qDebug()<<"MouseMove";
            QString str = QString("Mouse at (x:%1, y:%2)").arg(event->x()).arg(event->y());
            ui->textEdit->append(str);
            break;
        }
        default:
            qDebug()<<"default";
            break;
    }
}

