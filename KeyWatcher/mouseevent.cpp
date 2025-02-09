#include "mouseevent.h"
#include <QDebug>
#include <QCursor>
#include <QtConcurrent>
#include <X11/Xlib.h>
#include <X11/extensions/record.h>
#include <X11/Xproto.h>

static XRecordContext context;
static Display *display = nullptr;

static void callback(XPointer p,XRecordInterceptData *data)
{
    if (data->category != XRecordFromServer) {
        return ;
    }

    xEvent * event  = reinterpret_cast<xEvent*>(data->data);
    QPoint point = QCursor::pos();
    switch(event->u.u.type)
    {
    case ButtonPress:
    {
        switch(event->u.u.detail)
        {
        case Button1:     // 左键按下
        {
        emit MouseEvent::getInstance()->mouseEvent(new QMouseEvent(QEvent::MouseButtonPress, point, Qt::LeftButton, Qt::LeftButton, Qt::NoModifier));
        break;
        }
        case Button2:     // 中键按下
        {
        emit MouseEvent::getInstance()->mouseEvent(new QMouseEvent(QEvent::MouseButtonPress, point, Qt::MiddleButton, Qt::MiddleButton, Qt::NoModifier));
        break;
        }
        case Button3:     // 右键按下
        {
        emit MouseEvent::getInstance()->mouseEvent(new QMouseEvent(QEvent::MouseButtonPress, point, Qt::RightButton, Qt::RightButton, Qt::NoModifier));
        break;
        }
        default:
            break;
        }
    }
    case MotionNotify:
        qDebug() << "emit MotionNotify";
        emit MouseEvent::getInstance()->mouseEvent(new QMouseEvent(QEvent::MouseMove, QCursor::pos(), Qt::NoButton, Qt::NoButton, Qt::NoModifier));
        break;
    }
}

static void enableContext()
{
    XRecordEnableContext(display,context,callback,nullptr);
    XCloseDisplay(display);
    qDebug() << "退出事件监听";
}

MouseEvent::MouseEvent(QObject *parent)
    : QObject{parent}
{
    //从环境变量获取DISPLAY
    display = XOpenDisplay(nullptr);
    if (!display) {
        qDebug() << "Failed to connect to X server";
        return ;
    }

    //about XRecord, see https://www.x.org/releases/X11R7.7/doc/libXtst/recordlib.html#Record_Extension_Overview
    XRecordClientSpec clients = XRecordAllClients;
    XRecordRange *range = XRecordAllocRange();
    if (!range) {
        qDebug() << "Failed to alloc XRecordRange";
        return ;
    }

    memset(range,0,sizeof(XRecordRange));
    range->device_events.first = ButtonPress;
    range->device_events.last  = MotionNotify;

    context = XRecordCreateContext(display,0,&clients,1,&range,1);
    if (!context) {
        qDebug("Failed to create context");
    }
    XFree(range);
    XSync(display,false);

    QtConcurrent::run(enableContext);
}
