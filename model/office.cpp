#include "office.h"

bool operator==(const office& l, const office& r) {
    return l.name == r.name
            && l.address == r.address
            && l.phone == r.phone;
}
