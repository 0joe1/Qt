#ifndef ADDINFODIALOG_H
#define ADDINFODIALOG_H

#include <QDialog>
#include <QMetaType>
#include "chumaninfo.h"

namespace Ui {
class AddInfoDialog;
}

class AddInfoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddInfoDialog(QWidget *parent = nullptr);
    ~AddInfoDialog();

    void clearData();

    void setIsUpdateDlg(bool newIsUpdateDlg);

    bool display(int id,QString name,QString Sex);

signals:
    void sig_addInfo(CHumanInfo &humanInfo);
    void sig_updateInfo(CHumanInfo &HumanInfo);

private slots:
    void on_confirmButton_clicked();
    void on_cancelButton_clicked();

private:
    bool isUpdateDlg; //是否修改窗口
    Ui::AddInfoDialog *ui;
    void initUI();
};
Q_DECLARE_METATYPE(CHumanInfo);

#endif // ADDINFODIALOG_H
