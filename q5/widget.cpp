#include "widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    button = new QPushButton("点我",this);
    int a = 10;
    connect(button,&QPushButton::clicked,this,[=](){
        qDebug() << "push me!!!  ";
        qDebug() << a;
    });
}

Widget::~Widget() {}
