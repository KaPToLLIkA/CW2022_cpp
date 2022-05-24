#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "iemployee.h"

class director : public iemployee
{
    QString phone;
public:
    explicit director();

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

    }

    void serialize_to(QDataStream &stream) override {

    }

    friend bool operator==(const director& l, const director& r);
};

bool operator==(const director& l, const director& r) {
    return (iemployee)l == (iemployee)r
            && l.phone == r.phone;
}
#endif // DIRECTOR_H
