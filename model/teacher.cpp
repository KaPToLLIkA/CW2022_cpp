#include "teacher.h"

bool operator==(const teacher& l, const teacher& r) {
    return (iemployee)l == (iemployee)r
            && l.education == r.education
            && l.subject == r.subject;
}
