#include "chumaninfo.h"

CHumanInfo::CHumanInfo() {}

bool CHumanInfo::setData(int id, QString name, QString sex)
{
    m_id = id;
    m_name = name;
    m_sex = sex;

    return true;
}

int CHumanInfo::id() const
{
    return m_id;
}

void CHumanInfo::setId(int newId)
{
    m_id = newId;
}

QString CHumanInfo::name() const
{
    return m_name;
}

void CHumanInfo::setName(const QString &newName)
{
    m_name = newName;
}

QString CHumanInfo::sex() const
{
    return m_sex;
}

void CHumanInfo::setSex(const QString &newSex)
{
    m_sex = newSex;
}
