#ifndef CHUMANINFO_H
#define CHUMANINFO_H

#include <QString>

class CHumanInfo
{
public:
    CHumanInfo();
    bool setData(int id,QString name,QString sex);

    int id() const;
    void setId(int newId);

    QString name() const;
    void setName(const QString &newName);

    QString sex() const;
    void setSex(const QString &newSex);

private:
    int m_id;
    QString m_name;
    QString m_sex;
};

#endif // CHUMANINFO_H
