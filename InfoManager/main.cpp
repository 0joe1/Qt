#include "mainwindow.h"
#include <cdatasourcesqlite.h>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CDataSourceSQLite datasource;
    MainWindow w;
    w.show();

    return a.exec();
}
