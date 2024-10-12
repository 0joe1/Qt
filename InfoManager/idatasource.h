#ifndef IDATASOURCE_H
#define IDATASOURCE_H

#include <QList>
#include "chumaninfo.h"

class IDataSource
{
public:
    IDataSource();
    virtual ~IDataSource()=0;

    virtual bool selectHumanInfo(QList<CHumanInfo> &humanInfos) = 0;
    virtual bool addHumanInfo(CHumanInfo &humanInfo) = 0;
    virtual bool updateHumanInfo(CHumanInfo &humanInfo) = 0;
    virtual bool deleteHumanInfo(int id) = 0;
};

#endif // IDATASOURCE_H
