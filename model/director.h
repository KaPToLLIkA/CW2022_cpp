#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "iemployee.h"

class director : public iemployee
{
    QString phone;
public:
    explicit director(QString name,
             QString surname,
             QString patronymic,
             QDate birth_day,
             int salary,
             QString phone)
         :
           iemployee(name, surname, patronymic, birth_day, salary),
           phone(phone)
     {}

    QString get_phone() { return phone; }

    void set_phone(QString value) { phone = value; }

    void deserialize_from(QDataStream &stream) override {

    }

    void serialize_to(QDataStream &stream) override {

    }
};

#endif // DIRECTOR_H
