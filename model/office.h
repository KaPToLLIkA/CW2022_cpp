#ifndef OFFICE_H
#define OFFICE_H

#include <QString>
#include <QDebug>
#include "../slow_list.h"
#include "iemployee.h"
#include "teacher.h"
#include "director.h"
#include "security.h"

class office
{
    QString name;
    QString address;
    QString phone;
    slow_list<iemployee> employees;
public:
    explicit office() {}

    explicit office(QString name,
                    QString address,
                    QString phone)
        : name(name), address(address), phone(phone)
    {}

    QString get_name() { return name; }
    QString get_address() { return address; }
    QString get_phone() { return phone; }

    void add_employee(iemployee* employee) {
        employees.add(employee);
    }

    uint32_t employees_count() {
        return employees.lenght();
    }

    iemployee* get_employee_at(int index) {
        return employees.get_value_at(index);
    }

    void remove_employee(iemployee* employee) {
        employees.remove_by_value(employee);
    }

    void set_name(QString value) { name = value; }
    void set_address(QString value) { address = value; }
    void set_phone(QString value) { phone = value; }

    virtual void serialize_to(QDataStream &stream) {
        stream << name;
        stream << address;
        stream << phone;
        stream << employees.lenght();
        for (int i = 0; i < employees.lenght(); ++i) {
            employees.get_value_at(i)->serialize_to(stream);
        }
    }

    virtual void deserialize_from(QDataStream &stream) {
        stream >> name;
        qDebug() << name;
        stream >> address;
        qDebug() << address;
        stream >> phone;
        qDebug() << phone;
        uint32_t count = 0;
        stream >> count;
        for (int i = 0; i < count; ++i) {
            QString post;
            stream >> post;

            qDebug() << post;

            if (post == "teacher") {
                auto x = new teacher();
                x->deserialize_from(stream);
                employees.add(x);
            }

            if (post == "security") {
                auto x = new security();
                x->deserialize_from(stream);
                employees.add(x);
            }

            if (post == "director") {
                auto x = new director();
                x->deserialize_from(stream);
                employees.add(x);
            }

        }
    }

    friend bool operator==(const office& l, const office& r);
};

#endif // OFFICE_H
