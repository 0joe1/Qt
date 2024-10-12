#include "addinfodialog.h"
#include "ui_addinfodialog.h"
#include"chumaninfo.h"
#include <QRegExp>
#include <QDebug>
#include <QMessageBox>

AddInfoDialog::AddInfoDialog(QWidget *parent)
    : QDialog(parent)
    , isUpdateDlg(false)
    , ui(new Ui::AddInfoDialog)
{
    ui->setupUi(this);
    initUI();
}

AddInfoDialog::~AddInfoDialog()
{
    delete ui;
}

void AddInfoDialog::clearData()
{
    ui->lineId->clear();
    ui->lineName->clear();
}

void AddInfoDialog::on_confirmButton_clicked()
{
    int idLen = ui->lineId->text().size();
    if (idLen < 6) {
        QMessageBox::information(this,"提示","应输入6位学号");
        return ;
    }

    int id = ui->lineId->text().toInt();
    QString name = ui->lineName->text();
    QString sex  = ui->cmbSex->currentText();

    CHumanInfo humanInfo;
    humanInfo.setData(id,name,sex);

    if (isUpdateDlg)
    {
        qDebug() << "change";
        emit sig_updateInfo(humanInfo);
    }
    else
    {
        qDebug() << "addInfo";
        emit sig_addInfo(humanInfo);
        clearData();
    }
}

void AddInfoDialog::initUI()
{
    ui->lineId->setPlaceholderText("请输入6位ID");
    QRegExp regId("^[0-9]{6}$");
    ui->lineId->setValidator(new QRegExpValidator(regId,this));
    ui->lineName->setPlaceholderText("例:Amy");
    ui->cmbSex->addItem("男");
    ui->cmbSex->addItem("女");
}


void AddInfoDialog::on_cancelButton_clicked()
{
    setIsUpdateDlg(false);
    ui->lineId->setReadOnly(false);
    clearData();
    this->close();
}

void AddInfoDialog::setIsUpdateDlg(bool newIsUpdateDlg)
{
    isUpdateDlg = newIsUpdateDlg;
}

bool AddInfoDialog::display(int id, QString name, QString sex)
{
    ui->lineId->setText(QString("%1").arg(id,6,10,QLatin1Char('0')));
    ui->lineId->setReadOnly(true);
    ui->lineName->setText(name);
    ui->cmbSex->setCurrentText(sex);
    return true;
}

