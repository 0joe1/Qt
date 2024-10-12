#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "scanner.h"
#include <QString>
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void startAnalyzing(void);
    void updateProgress(void);
    void updateOutput(int portnum);

private:
    Ui::MainWindow *ui;
    std::vector<Scanner*> netScanners;
    bool checkIP(void);
};
#endif // MAINWINDOW_H
