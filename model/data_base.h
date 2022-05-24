#ifndef DATA_BASE_H
#define DATA_BASE_H

#include <QFile>
#include <QDebug>

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

    void clear() {
        offices = slow_list<office>();
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
        qDebug() << path;

        offices = slow_list<office>();

        QFile inFile(path);
        inFile.open(QIODevice::ReadOnly);
        QDataStream inStream(&inFile);

        uint32_t size;
        inStream >> size;

        qDebug() << "s" << size;

        for(uint32_t i = 0; i < size; ++i) {
            auto x = new office();
            qDebug() << "i" << i;
            x->deserialize_from(inStream);
            offices.add(x);
        }
    }

    void unload_to_file(QString path) {
        QFile outFile(path);
        outFile.open(QIODevice::WriteOnly);
        QDataStream outStream(&outFile);

        outStream << offices.lenght();
        for(uint64_t i = 0; i < offices.lenght(); ++i) {
            offices.get_value_at(i)->serialize_to(outStream);
        }
    }
};

#endif // DATA_BASE_H
