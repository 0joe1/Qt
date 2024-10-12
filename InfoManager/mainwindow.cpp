#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addinfodialog.h"
#include <QDebug>
#include <QMessageBox>
#include <QMap>

const int TABLE_COLUMN_SIZE = 3;
const int COL_ID = 0;
const int COL_NAME = 1;
const int COL_SEX = 2;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_dataSource(NULL)
    , m_standardModel(NULL)
    , m_addInfo(NULL)
    , m_menu(NULL)
    , m_actUpdate(NULL)
    , m_actDelete(NULL)
{
    ui->setupUi(this);
    qRegisterMetaType<CHumanInfo>("CHumanInfo");
    qRegisterMetaType<CHumanInfo>("CHumanInfo&");

    //实例化数据源
    m_dataSource = new CDataSourceSQLite();
    m_addInfo = new AddInfoDialog(this);

    //关联添加、修改账户的槽函数
    connect(m_addInfo,&AddInfoDialog::sig_addInfo,this,&MainWindow::slot_addInfo);
    connect(m_addInfo,&AddInfoDialog::sig_updateInfo,this,&MainWindow::slot_updateInfo);

    //初始化界面
    initUI();
}

MainWindow::~MainWindow()
{
    delete m_dataSource;
    delete ui;
}

bool MainWindow::appendToModel(CHumanInfo &humanInfo)
{

    QStandardItem *itemId = new QStandardItem(QString("%1").arg(humanInfo.id(),6,10,QLatin1Char('0')));
    itemId->setCheckable(true);
    itemId->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    QStandardItem *itemName = new QStandardItem(humanInfo.name());
    itemName->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    QStandardItem *itemSex = new QStandardItem(humanInfo.sex());
    itemSex->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    QList<QStandardItem*> rowItem;
    rowItem.append(itemId);
    rowItem.append(itemName);
    rowItem.append(itemSex);
    m_standardModel->appendRow(rowItem);
    return true;
}

void MainWindow::initUI()
{
    m_standardModel = new QStandardItemModel(this);
    connect(m_standardModel,&QStandardItemModel::itemChanged,this,&MainWindow::slot_itemChanged);

    m_menu = new QMenu(this);
    m_actUpdate = new QAction("修改",m_menu);
    m_actDelete = new QAction("删除",m_menu);
    m_menu->addAction(m_actUpdate);
    m_menu->addAction(m_actDelete);
    connect(m_actUpdate,&QAction::triggered,this,&MainWindow::slot_actUpdate);
    connect(m_actDelete,&QAction::triggered,this,&MainWindow::slot_actDelete);

    ui->humanTable->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->humanTable,&QTableView::customContextMenuRequested,this,&MainWindow::slot_popMenu);

    QList<CHumanInfo> humanInfoList;
    bool res = m_dataSource->selectHumanInfo(humanInfoList);
    if (!res) {
        QMessageBox::information(this,"提示","查询学生信息失败");
        return ;
    }
    for (int i = 0; i < humanInfoList.size(); i++)
    {
        appendToModel(humanInfoList[i]);
    }

    //添加表头
    QStringList headerList;
    headerList << "userID" << "name" << "sex";
    m_standardModel->setHorizontalHeaderLabels(headerList);

    ui->humanTable->verticalHeader()->setVisible(false);
    ui->humanTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->humanTable->setModel(m_standardModel);

    for (int col = 0; col < TABLE_COLUMN_SIZE; col++)
    {
        ui->humanTable->setColumnWidth(col,(ui->humanTable->width())/TABLE_COLUMN_SIZE);
    }
}

void MainWindow::on_addButton_clicked()
{
    m_addInfo->show();
}

bool MainWindow::slot_addInfo(CHumanInfo &humanInfo)
{
    bool res = m_dataSource->addHumanInfo(humanInfo);
    if (!res) {
        QMessageBox::information(this,"提示","插入失败");
        return false;
    }
    appendToModel(humanInfo);
    return true;
}

bool MainWindow::slot_updateInfo(CHumanInfo &humanInfo)
{
    int res = m_dataSource->updateHumanInfo(humanInfo);
    if (!res)
    {
        QMessageBox::information(this,"提示","修改失败!!!");
        return false;
    }
    int row = ui->humanTable->currentIndex().row();
    m_standardModel->setData(m_standardModel->item(row,COL_NAME)->index(),humanInfo.name());
    m_standardModel->setData(m_standardModel->item(row,COL_SEX)->index(),humanInfo.sex());
    QMessageBox::information(this,"提示","修改成功");
    return true;
}


void MainWindow::on_checkAllButton_clicked(bool checked)
{
    for(int row = 0; row < m_standardModel->rowCount(); row++)
    {
        if (checked)
            m_standardModel->item(row)->setCheckState(Qt::Checked);
        else
            m_standardModel->item(row)->setCheckState(Qt::Unchecked);
    }
}

bool MainWindow::slot_itemChanged(QStandardItem *item)
{
    if (m_standardModel->indexFromItem(item).column() > 0)
        return false;
    for (int row = 0; row < m_standardModel->rowCount(); row++)
    {
        if (m_standardModel->item(row)->checkState() !=  Qt::Checked)
        {
            ui->checkAllButton->setChecked(false);
            return false;
        }

    }
    ui->checkAllButton->setChecked(true);
    return true;
}


void MainWindow::on_delButton_clicked()
{
    QMap<int,QStandardItem*> delRowsMap;
    for (int row = 0;  row < m_standardModel->rowCount(); row++)
    {
        QStandardItem *item = m_standardModel->item(row);
        if (m_standardModel->item(row)->checkState() == Qt::Checked)
        {
            delRowsMap.insert(row,item);
        }
    }

    if (delRowsMap.size() == 0)
        return ;

    QList<int> keyList = delRowsMap.keys();
    for (int i = keyList.size()-1; i >= 0; i--)
    {
        if (m_dataSource->deleteHumanInfo(delRowsMap.value(keyList[i])->text().toInt()))
        {
            m_standardModel->takeRow(keyList[i]);
            delete delRowsMap.value(keyList[i]);
        }
    }
}

bool MainWindow::slot_popMenu(const QPoint &pos)
{
    if(m_standardModel->itemFromIndex(ui->humanTable->indexAt(pos)) == NULL)
        return false;
    m_menu->exec(QCursor::pos());
    return true;
}

bool MainWindow::slot_actUpdate()
{
    m_addInfo->setIsUpdateDlg(true);
    int row = ui->humanTable->currentIndex().row();
    int id   = m_standardModel->item(row,COL_ID)->text().toInt();
    QString name = m_standardModel->item(row,COL_NAME)->text();
    QString sex  = m_standardModel->item(row,COL_SEX)->text();
    m_addInfo->display(id,name,sex);
    m_addInfo->show();

    return true;
}

bool MainWindow::slot_actDelete()
{
    int row = ui->humanTable->currentIndex().row();
    int id  = m_standardModel->item(row)->text().toInt();
    m_dataSource->deleteHumanInfo(id);
    m_standardModel->removeRow(row);
    return true;
}

