#include "security.h"

bool operator==(const security& l, const security& r) {
    return (iemployee)l == (iemployee)r
            && l.security_organization == r.security_organization;
}
