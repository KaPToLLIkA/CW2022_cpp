#ifndef DATA_BASE_H
#define DATA_BASE_H

#include "../slow_list.h"
#include "office.h"

class data_base
{
    static data_base *_i;

    slow_list<office> offices;

    explicit data_base();
public:
    static data_base* i() {
        if (_i == nullptr) {
            _i = new data_base();
        }
        return _i;
    }

    void add_office(office* office) {
        offices.add(office);
    }

    void remove_office(office* office) {
        offices.remove_by_value(office);
    }

    uint32_t offices_count() {
        return offices.lenght();
    }

    office* get_office_at(uint32_t index) {
        return offices.get_value_at(index);
    }

    void load_from_file(QString path) {

    }

    void unload_to_file(QString path) {

    }
};

#endif // DATA_BASE_H
