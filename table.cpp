#include "table.h"
#include <QString>
#include <QTableWidgetItem>
#include <algorithm>
#include <iostream>



Table::Table() {
    CSVReader csv;
    locations = csv.into_vector("./data.csv");
}

int Table::getSize() {
    return int(locations.size());
}

void Table::sortData(std::string attribute) {
    std::vector<Location> copy = locations;
    double timeTaken = sorter.mergeSort(&copy, attribute);
    std::cout << timeTaken << std::endl;
}

void Table::handleSortModeChange(QTableWidget *tableWidget, std::string mode) {
    if (sortMode == mode) return; // Avoid redundant operations
    sortMode = mode;
    tableWidget->setRowCount(0);
    populate(tableWidget);
}


void Table::populate(QTableWidget *tableWidget) {
    int totalLocations = locations.size();
    int minimum = std::min(totalLocations, 100);

    tableWidget->setRowCount(minimum);
    tableWidget->setColumnCount(9);
    tableWidget->setHorizontalHeaderLabels({
        "Tract Code", "Block Group", "Name", "Population",
        "Households", "Employment", "Size", "Walkability", "Transit"
    });


    if(sortMode == "Greatest") {
        for (int i = 0; i < minimum; ++i) {
            displayData(tableWidget, i, locations[totalLocations - minimum + i]);
        }
    }
    else {
        for(int i = 0; i < minimum;++i) {
            displayData(tableWidget, i, locations[i]);
        }
    }
}

void Table::displayData(QTableWidget *tableWidget, int row, const Location &loc){
    QTableWidgetItem *tractCodeItem = new QTableWidgetItem(QString::fromStdString(loc.tractCode));
    QTableWidgetItem *blockGroupItem = new QTableWidgetItem(QString::fromStdString(loc.blockGroup));
    QTableWidgetItem *nameItem = new QTableWidgetItem(QString::fromStdString(loc.name));
    QTableWidgetItem *populationItem = new QTableWidgetItem(QString::number(loc.population));
    QTableWidgetItem *numHouseholdsItem = new QTableWidgetItem(QString::number(loc.numHouseholds));
    QTableWidgetItem *totalEmploymentItem = new QTableWidgetItem(QString::number(loc.totalEmployment));
    QTableWidgetItem *sizeItem = new QTableWidgetItem(QString::number(loc.size, 'f', 2));
    QTableWidgetItem *walkabilityItem = new QTableWidgetItem(QString::number(loc.walkability, 'f', 2));
    QTableWidgetItem *transitScoreItem = new QTableWidgetItem(QString::number(loc.transitScore, 'f', 2));

    // Make items read-only
    tractCodeItem->setFlags(tractCodeItem->flags() & ~Qt::ItemIsEditable);
    blockGroupItem->setFlags(blockGroupItem->flags() & ~Qt::ItemIsEditable);
    nameItem->setFlags(nameItem->flags() & ~Qt::ItemIsEditable);
    populationItem->setFlags(populationItem->flags() & ~Qt::ItemIsEditable);
    numHouseholdsItem->setFlags(numHouseholdsItem->flags() & ~Qt::ItemIsEditable);
    totalEmploymentItem->setFlags(totalEmploymentItem->flags() & ~Qt::ItemIsEditable);
    sizeItem->setFlags(sizeItem->flags() & ~Qt::ItemIsEditable);
    walkabilityItem->setFlags(walkabilityItem->flags() & ~Qt::ItemIsEditable);
    transitScoreItem->setFlags(transitScoreItem->flags() & ~Qt::ItemIsEditable);

    // Add items to the table
    tableWidget->setItem(row, 0, tractCodeItem);
    tableWidget->setItem(row, 1, blockGroupItem);
    tableWidget->setItem(row, 2, nameItem);
    tableWidget->setItem(row, 3, populationItem);
    tableWidget->setItem(row, 4, numHouseholdsItem);
    tableWidget->setItem(row, 5, totalEmploymentItem);
    tableWidget->setItem(row, 6, sizeItem);
    tableWidget->setItem(row, 7, walkabilityItem);
    tableWidget->setItem(row, 8, transitScoreItem);
}
