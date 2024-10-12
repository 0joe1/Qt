#include "dialog.h"

#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    QLabel label(&w);
    w.resize(1500,500);
    label.setText("hi world!!!!!");
    w.show();
    return a.exec();
}
