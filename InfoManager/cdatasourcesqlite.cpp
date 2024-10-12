#include "cdatasourcesqlite.h"
#include <QDebug>
#include <QSqlQuery>

CDataSourceSQLite::CDataSourceSQLite()
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("./InfoDB.db");
    if (!m_db.open())
    {
        qDebug() << "Failed to Open database";
        return ;
    }

    QSqlQuery query;
    QString sql = QString("create table if not exists tb_human"
                          "(id int primary key not null,"
                          "name varchar(30),"
                          "sex varchar(2));");

    if (!query.exec(sql))
    {
        qDebug() << "Failed to create table";
        qDebug() << query.lastQuery();
        return ;
    }
    m_db.close();
}

CDataSourceSQLite::~CDataSourceSQLite()
{

}

bool CDataSourceSQLite::selectHumanInfo(QList<CHumanInfo> &humanInfos)
{
    if (!m_db.open())
    {
        qDebug() << "selectHumanInfo:Failed to Open Database";
        return false;
    }
    QSqlQuery query;
    QString sql = "Select * from tb_human;";
    if (!query.exec(sql))
    {
        qDebug() << "Failed to select tb_human;";
        return false;
    }
    while (query.next())
    {
        CHumanInfo humanInfo;
        humanInfo.setId(query.value("id").toInt());
        humanInfo.setName(query.value("name").toString());
        humanInfo.setSex(query.value("sex").toString());

        humanInfos.append(humanInfo);
    }

    return true;
}

bool CDataSourceSQLite::addHumanInfo(CHumanInfo &humanInfo)
{
    if (!m_db.open())
    {
        qDebug() << "addHumanInfo:Failed to Open Database";
        return false;
    }
    QSqlQuery query;
    query.prepare("insert into tb_human(id,name,sex)"
                  "values(:id,:name,:sex)");
    query.bindValue(":id",humanInfo.id());
    query.bindValue(":name",humanInfo.name());
    query.bindValue(":sex",humanInfo.sex());
    if (!query.exec()) {
        qDebug() << "Failed to insert to table";
        m_db.close();
        return false;
    }
    m_db.close();

    return true;
}

bool CDataSourceSQLite::updateHumanInfo(CHumanInfo &humanInfo)
{
    if (!m_db.open())
    {
        qDebug() << "addHumanInfo:Failed to Open Database";
        return false;
    }
    QSqlQuery query;
    query.prepare("update tb_human set name=:name,sex=:sex where id=:id");
    query.bindValue(":id",humanInfo.id());
    query.bindValue(":name",humanInfo.name());
    query.bindValue(":sex",humanInfo.sex());
    if (!query.exec()) {
        qDebug() << "Failed to update data";
        m_db.close();
        return false;
    }
    m_db.close();

    return true;
}

bool CDataSourceSQLite::deleteHumanInfo(int id)
{
    if (!m_db.open())
    {
        qDebug() << "addHumanInfo:Failed to Open Database";
        return false;
    }
    QSqlQuery query;
    QString sql = QString("delete from tb_human where id = %1").arg(id);
    if (!query.exec(sql))
    {
        qDebug() << "Failed to delete data";
        m_db.close();
        return false;
    }

    m_db.close();
    return true;
}
