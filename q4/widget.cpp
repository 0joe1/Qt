#include "widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    button = new QPushButton("其实也就一般",this);
    button->move(200,200);
    button1 = new QPushButton("隐藏父窗口，显示子窗口",this);
    connect(button,&QPushButton::pressed,this,&Widget::print);
    connect(button1,&QPushButton::clicked,this,&Widget::button_hs);

    sonwindow = new Sonwidget;
    sonwindow->show();
    connect(sonwindow,&Sonwidget::show_hide_signal,this,&Widget::sonbutton_cb);
}

void Widget::print()
{
    qDebug() << "123456";
}

void Widget::button_hs()
{
    this->hide();
    this->sonwindow->show();
}

void Widget::sonbutton_cb()
{
    sonwindow->hide();
    this->show();
}

Widget::~Widget() {}
