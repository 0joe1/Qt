#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include "sonwidget.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    QPushButton *button;
    QPushButton *button1;
    Sonwidget *sonwindow;
public slots:
    void print(void);
    void button_hs(void);
    void sonbutton_cb(void);
};
#endif // WIDGET_H
