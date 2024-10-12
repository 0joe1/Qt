#include "sonwidget.h"

Sonwidget::Sonwidget(QWidget *parent)
    : QWidget{parent}
{
    button2 = new QPushButton("隐藏子窗口，显示父窗口",this);
    connect(button2,&QPushButton::clicked,this,&Sonwidget::emit_signal);
}

void Sonwidget::emit_signal(void)
{
    emit show_hide_signal();
}
