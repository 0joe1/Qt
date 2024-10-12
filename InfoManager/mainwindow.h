#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <cdatasourcesqlite.h>
#include <QStandardItemModel>
#include <addinfodialog.h>

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

    bool appendToModel(CHumanInfo &humanInfo);

private slots:
    void on_addButton_clicked();
    bool slot_addInfo(CHumanInfo &humanInfo);
    bool slot_updateInfo(CHumanInfo &humanInfo);
    void on_checkAllButton_clicked(bool checked);
    bool slot_itemChanged(QStandardItem *item);
    void on_delButton_clicked();
    bool slot_popMenu(const QPoint &pos);
    bool slot_actUpdate(void);
    bool slot_actDelete(void);

private:
    void initUI();

private:
    Ui::MainWindow *ui;
    CDataSourceSQLite  *m_dataSource;
    QStandardItemModel *m_standardModel;
    AddInfoDialog *m_addInfo;
    QMenu *m_menu;
    QAction *m_actUpdate;
    QAction *m_actDelete;
};
#endif // MAINWINDOW_H
