#ifndef TABLE_H
#define TABLE_H

#include "location.h"
#include "csvreader.h"
#include "sorter.h"
#include <QTableWidget>
#include <vector>

class Table {
public:
    Table();  // Explicit declaration of the default constructor
    void populate(QTableWidget *tableWidget);
    void displayData(QTableWidget *tableWidget, int row, const Location &loc);
    void handleSortModeChange(QTableWidget *tableWidget, std::string mode);
    void sortData(std::string attribute);
    int getSize();

private:
    std::vector<Location> locations;
    Sorter sorter;
    std::string sortMode = "Least";
};


#endif // TABLE_H
