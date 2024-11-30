#ifndef TABLE_H
#define TABLE_H
#include "location.h"
#include <QTableWidget>
#include <vector>

class Table {
public:
    static void populate(QTableWidget *tableWidget, const std::vector<Location> &locations);
    static std::vector<Location> generateLocations(int count);
};

#endif // TABLE_H
