#ifndef TABLE_H
#define TABLE_H
#include "location.h"
#include "csvreader.h"
#include "sorter.h"
#include <QTableWidget>
#include <vector>
#include "ui_mainwindow.h"

class Table {
public:
    Table();
    void setUi(Ui::MainWindow *ui);
    void populate();
    void displayData(int row, const Location &loc);
    void handleSortModeChange(std::string mode);
    void sortData(std::string attribute);
    int getSize();

private:
    Ui::MainWindow *ui = nullptr;
    std::vector<Location> locations;
    Sorter sorter;
    std::string sortMode = "Least";
};

#endif // TABLE_H
