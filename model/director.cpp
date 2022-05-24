#include "director.h"

bool operator==(const director& l, const director& r) {
    return (iemployee)l == (iemployee)r
            && l.phone == r.phone;
}
