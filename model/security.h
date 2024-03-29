#ifndef SECURITY_H
#define SECURITY_H

#include "iemployee.h"

class security : public iemployee
{
    QString security_organization;
public:
    explicit security() {
        post = "security";
    }

    explicit security(QString name,
             QString surname,
             QString patronymic,
             QDate birth_day,
             int salary,
             QString security_organization)
         :
           iemployee(name, surname, patronymic, birth_day, salary),
           security_organization(security_organization)
     {
        post = "security";
    }

    QString get_sec_organization() { return security_organization; }

    void set_sec_organization(QString value) { security_organization = value; }

    void deserialize_from(QDataStream &stream) override {
        iemployee::deserialize_from(stream);
        stream >> security_organization;
    }

    void serialize_to(QDataStream &stream) override {
        iemployee::serialize_to(stream);
        stream << security_organization;
    }

    friend bool operator==(const security& l, const security& r);
};

#endif // SECURITY_H
