#ifndef SECURITY_H
#define SECURITY_H

#include "iemployee.h"

class security : public iemployee
{
    QString security_organization;
public:
    explicit security(QString name,
             QString surname,
             QString patronymic,
             QDate birth_day,
             int salary,
             QString security_organization)
         :
           iemployee(name, surname, patronymic, birth_day, salary),
           security_organization(security_organization)
     {}

    QString get_sec_organization() { return security_organization; }

    void set_sec_organization(QString value) { security_organization = value; }

    void deserialize_from(QDataStream &stream) override {

    }

    void serialize_to(QDataStream &stream) override {

    }

    friend bool operator==(const security& l, const security& r);
};

bool operator==(const security& l, const security& r) {
    return (iemployee)l == (iemployee)r
            && l.security_organization == r.security_organization;
}

#endif // SECURITY_H
