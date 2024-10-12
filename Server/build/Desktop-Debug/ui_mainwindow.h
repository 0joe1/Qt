/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.15
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *listenButton;
    QTextBrowser *textBrowser;
    QLineEdit *sendLine;
    QPushButton *sendButton;
    QPushButton *inMouseButton;
    QPushButton *rmMouseButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        listenButton = new QPushButton(centralwidget);
        listenButton->setObjectName(QString::fromUtf8("listenButton"));
        listenButton->setGeometry(QRect(120, 400, 141, 41));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(60, 40, 301, 311));
        sendLine = new QLineEdit(centralwidget);
        sendLine->setObjectName(QString::fromUtf8("sendLine"));
        sendLine->setGeometry(QRect(460, 120, 241, 31));
        sendButton = new QPushButton(centralwidget);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));
        sendButton->setGeometry(QRect(530, 160, 91, 31));
        inMouseButton = new QPushButton(centralwidget);
        inMouseButton->setObjectName(QString::fromUtf8("inMouseButton"));
        inMouseButton->setGeometry(QRect(430, 310, 101, 81));
        rmMouseButton = new QPushButton(centralwidget);
        rmMouseButton->setObjectName(QString::fromUtf8("rmMouseButton"));
        rmMouseButton->setGeometry(QRect(610, 310, 101, 81));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        listenButton->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213\347\233\221\345\220\254", nullptr));
        sendButton->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201\346\225\260\346\215\256", nullptr));
        inMouseButton->setText(QCoreApplication::translate("MainWindow", "\345\256\211\350\243\205\351\274\240\346\240\207\347\233\221\345\220\254\345\231\250", nullptr));
        rmMouseButton->setText(QCoreApplication::translate("MainWindow", "\345\215\270\350\275\275\351\274\240\346\240\207\347\233\221\345\220\254\345\231\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
