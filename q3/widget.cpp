#include "widget.h"
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowTitle("I'm a window");
    this->setFixedSize(600,400);
    button = new QPushButton("登入",this);
    button->show();
    button->resize(200,100);
    button->move(100,100);

    QPushButton *p = new QPushButton("X",this);
    p->resize(30,30);
    p->move(570,0);
    p->show();
    connect(p,&QPushButton::clicked,this,&QWidget::close);
}

Widget::~Widget() {}
