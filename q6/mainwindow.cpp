#include "mainwindow.h"
#include <QDebug>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QToolBar>
#include <QStatusBar>
#include <QLabel>
#include <QTextEdit>
#include <QIcon>
#include <QString>
#include <QFileDialog>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QMenuBar *menubar = this->menuBar();
    QMenu *filemenu = menubar->addMenu("文件");
    QMenu *editmenu = menubar->addMenu("编辑");
    QAction *openaction = filemenu->addAction("打开");
    QAction *saveaction = filemenu->addAction("保存");

    QToolBar *toolbar = this->addToolBar("工具栏");
    toolbar->addAction(openaction);
    toolbar->addAction(saveaction);

    QStatusBar *status = this->statusBar();
    status->addWidget(new QLabel("状态"));

    QTextEdit *edit = new QTextEdit("文本编辑器",this);
    this->setCentralWidget(edit);

    QPixmap picopen,picsave;
    picopen.load("://open.png");
    openaction->setIcon(QIcon(picopen));
    picsave.load("://image/save.png");
    saveaction->setIcon(QIcon(picsave));

    qDebug()<< "hello~";
    connect(openaction,&QAction::triggered,[](){
        QString str = QFileDialog::getOpenFileName();
        qDebug()<< str;
    });

    button1 = new QPushButton("模态对话框",this);
    button1->move(250,200);
    connect(button1,&QPushButton::clicked,[](){
        QDialog dialog;
        dialog.exec();
    });

    button2 = new QPushButton("非模态对话框",this);
    button2->move(400,200);
    connect(button2,&QPushButton::clicked,[](){
        QDialog *dialog = new QDialog;
        dialog->setAttribute(Qt::WA_DeleteOnClose);
        dialog->show();
    });
}

MainWindow::~MainWindow() {}
