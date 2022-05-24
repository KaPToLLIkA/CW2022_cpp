#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "iemployee.h"

class director : public iemployee
{
    QString phone;
public:
    explicit director() {
        post = "director";
    }

    explicit director(QString name,
             QString surname,
             QString patronymic,
             QDate birth_day,
             int salary,
             QString phone)
         :
           iemployee(name, surname, patronymic, birth_day, salary),
           phone(phone)
    {
       post = "director";
   }

    QString get_phone() { return phone; }

    void set_phone(QString value) { phone = value; }

    void deserialize_from(QDataStream &stream) override {
        iemployee::deserialize_from(stream);
        stream >> phone;
    }

    void serialize_to(QDataStream &stream) override {
        iemployee::serialize_to(stream);
        stream << phone;
    }

    friend bool operator==(const director& l, const director& r);
};
#endif // DIRECTOR_H
