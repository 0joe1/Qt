#ifndef MOUSEEVENT_H
#define MOUSEEVENT_H

#include <QObject>
#include <QMouseEvent>

class MouseEvent : public QObject
{
    Q_OBJECT
public:
    explicit MouseEvent(QObject *parent = nullptr);
    static MouseEvent *getInstance()
    {
        static MouseEvent mouseEvent;
        return &mouseEvent;
    }

public slots:
    bool installMouseEvent(void);
    bool removeMouseEvent(void);

signals:
    void mouseEvent(QMouseEvent *event);
};

#endif // MOUSEEVENT_H
