#include "iemployee.h"

bool operator==(const iemployee& l, const iemployee& r) {
    return l.name == r.name
            && l.surname == r.surname
            && l.birth_day == r.birth_day
            && l.patronymic == r.patronymic
            && l.salary == r.salary;
}
