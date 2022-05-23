#ifndef OFFICE_H
#define OFFICE_H

#include <QString>
#include "../slow_list.h"
#include "iemployee.h"

class office
{
    QString name;
    QString address;
    QString phone;
    slow_list<iemployee> employyes;
public:
    office();
};

#endif // OFFICE_H
