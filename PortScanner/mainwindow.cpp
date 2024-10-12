#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRegExp>
#include <QRegExpValidator>
#include <QStringList>
#include <QMessageBox>
#include <QDebug>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->progressBar->hide();

    QRegExp rx("^\\s*[.0-9]{1,15}");
    QRegExpValidator *pattern = new QRegExpValidator(rx,this);
    ui->ipLine->setValidator(pattern);

    connect(ui->startButton,SIGNAL(clicked(bool)),this,SLOT(startAnalyzing()));
}

bool MainWindow::checkIP(void)
{
    QStringList slist = ui->ipLine->text().split(".");
    for (int i = 0; i < 4; i++) {
        int num = slist[i].toInt();
        if (num < 0 || num > 255)
            return false;
    }
    return true;
}

void MainWindow::startAnalyzing(void)
{
    if (!checkIP()) {
        QMessageBox::information(this,"Hint","Wrong ip address");
        return ;
    }

    QString ipAddr = ui->ipLine->text();
    int startPort = ui->startSpinBox->value();
    int endPort   = ui->EndSpinBox->value();
    ui->progressBar->setRange(0,endPort-startPort+1);
    ui->progressBar->setValue(0);
    ui->progressBar->show();
    ui->OutputWidget->clear();

    int Tnum = ui->threadSpinBox->value();
    int interval = (endPort - startPort)/Tnum;
    for (int i = 0; i < Tnum; i++)
    {
        Scanner *s = new Scanner;
        int sp = startPort + i*interval;
        int ed = (sp+interval-1 < endPort) ? sp+interval-1 : endPort;

        qDebug() << "Thread " << i;
        qDebug() << "startThread " << sp << "endThread " << ed;
        s->set_ip(ipAddr);
        s->set_startPort(sp);
        s->set_endPort(ed);
        netScanners.push_back(s);
    }

    for (int i = 0; i < Tnum; i++)
    {
        connect(netScanners[i],SIGNAL(sigProgress(int)),this,SLOT(updateProgress()));
        connect(netScanners[i],SIGNAL(port_open(int)),this,SLOT(updateOutput(int)));
        QTimer::singleShot(0,netScanners[i],SLOT(start_scan()));
    }
}

void MainWindow::updateProgress(void)
{
    ui->progressBar->setValue(ui->progressBar->value()+1);
}

void MainWindow::updateOutput(int portnum)
{
    QString msg = "find port" + QString::number(portnum) + "succeed";
    ui->OutputWidget->addItem(msg);
}

MainWindow::~MainWindow()
{
    delete ui;
}
