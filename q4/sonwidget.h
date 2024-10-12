#ifndef SONWIDGET_H
#define SONWIDGET_H

#include <QWidget>
#include <QPushButton>

class Sonwidget : public QWidget
{
    Q_OBJECT
public:
    explicit Sonwidget(QWidget *parent = nullptr);
    QPushButton *button2;

public slots:
    void emit_signal(void);

signals:
    void show_hide_signal();
};

#endif // SONWIDGET_H
