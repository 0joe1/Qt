#ifndef CDATASOURCESQLITE_H
#define CDATASOURCESQLITE_H

#include "idatasource.h"
#include <QSqlDatabase>

class CDataSourceSQLite : public IDataSource
{
public:
    CDataSourceSQLite();
    ~CDataSourceSQLite();

    virtual bool selectHumanInfo(QList<CHumanInfo> &humanInfos) override;
    virtual bool addHumanInfo(CHumanInfo &humanInfo) override;
    virtual bool updateHumanInfo(CHumanInfo &humanInfo) override;
    virtual bool deleteHumanInfo(int id) override;
private:
    QSqlDatabase m_db;

};

#endif // CDATASOURCESQLITE_H
