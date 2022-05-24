#ifndef TEACHER_H
#define TEACHER_H

#include "iemployee.h"

class teacher : public iemployee
{
    QString education;
    QString subject;
public:
    explicit teacher() {}

    explicit teacher(QString name,
            QString surname,
            QString patronymic,
            QDate birth_day,
            int salary,
            QString education,
            QString subject)
        :
          iemployee(name, surname, patronymic, birth_day, salary),
          education(education),
          subject(subject)
    {
       post = "teacher";
   }

    QString get_subject() { return subject; }
    QString get_education() { return education; }

    void set_subject(QString value) { subject = value; }
    void set_education(QString value) { education = value; }

    void deserialize_from(QDataStream &stream) override {

    }

    void serialize_to(QDataStream &stream) override {

    }

    friend bool operator==(const teacher& l, const teacher& r);
};

#endif // TEACHER_H
