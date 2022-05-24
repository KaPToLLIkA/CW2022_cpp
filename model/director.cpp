#include "director.h"

director::director()
{

}

bool operator==(const director& l, const director& r) {
    return (iemployee)l == (iemployee)r
            && l.phone == r.phone;
}
