#pragma once

#include <QDataStream>
#include <QString>
#include <QDate>

class iemployee
{
protected:
    QString name;
    QString surname;
    QString patronymic;
    QDate birth_day;
    QString post;
    int salary;
public:
    explicit iemployee() {}

    explicit iemployee(QString name,
                       QString surname,
                       QString patronymic,
                       QDate birth_day,
                       int salary)
        : name(name),
          surname(surname),
          patronymic(patronymic),
          birth_day(birth_day),
          salary(salary)
    {};

    QString get_name() { return name; }
    QString get_surname() { return surname; }
    QString get_patronymic() { return patronymic; }
    QDate get_birth_day() { return birth_day; }
    int get_salary() { return salary; }
    QString get_post() { return post; }

    void set_name(QString value) { name = value; }
    void set_surname(QString value) { surname = value; }
    void set_patronymic(QString value) { patronymic = value; }
    void set_birth_day(QDate value) { birth_day = value; }
    void set_salary(int value) { salary = value; }

    virtual void serialize_to(QDataStream &stream);
    virtual void deserialize_from(QDataStream &stream);

    friend bool operator==(const iemployee& l, const iemployee& r);
};

inline void iemployee::serialize_to(QDataStream &stream)
{
    stream << post;
    stream << name;
    stream << surname;
    stream << patronymic;
    stream << birth_day;
    stream << salary;
}

inline void iemployee::deserialize_from(QDataStream &stream)
{
    stream >> name;
    stream >> surname;
    stream >> patronymic;
    stream >> birth_day;
    stream >> salary;
}
