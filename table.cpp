#include "table.h"
#include <cstdlib>
#include <ctime>
#include <QString>
#include <QTableWidgetItem>


std::vector<Location> Table::generateLocations(int count) {
    std::vector<Location> locations;


    srand(static_cast<unsigned>(time(nullptr)));

    for (int i = 0; i < count; ++i) {
        Location loc;

        // Randomly generate location identifiers
        loc.tractCode = "Tract_" + std::to_string(rand() % 1000 + 1); // e.g., "Tract_123"
        loc.blockGroup = "Block_" + std::to_string(rand() % 100 + 1); // e.g., "Block_45"
        loc.name = "Location_" + std::to_string(i + 1); // e.g., "Location_1"

        // Randomly generate statistics
        loc.population = rand() % 5000 + 100;          // Random population between 100 and 5000
        loc.numHouseholds = rand() % 2000 + 50;        // Random households between 50 and 2000
        loc.totalEmployment = rand() % 1000 + 10;      // Random employment between 10 and 1000
        loc.size = static_cast<float>(rand() % 100) / 10.0f + 1.0f;  // Random size between 1.0 and 10.0
        loc.walkability = static_cast<float>(rand() % 100) / 10.0f;  // Random walkability between 0.0 and 10.0
        loc.transitScore = static_cast<float>(rand() % 100) / 10.0f; // Random transit score between 0.0 and 10.0

        // Add to the vector
        locations.push_back(loc);
    }

    return locations;
}

void Table::populate(QTableWidget *tableWidget, const std::vector<Location> &locations) {

    tableWidget->setRowCount(locations.size());
    tableWidget->setColumnCount(8); // Number of attributes in Location

    tableWidget->setHorizontalHeaderLabels({
        "Tract Code", "Block Group", "Name", "Population",
        "Households", "Employment", "Size", "Walkability", "Transit Score"
    });

    // Populate the table
    for (size_t i = 0; i < locations.size(); ++i) {
        const Location &loc = locations[i];

        // Create items for each column
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
        tableWidget->setItem(i, 0, tractCodeItem);
        tableWidget->setItem(i, 1, blockGroupItem);
        tableWidget->setItem(i, 2, nameItem);
        tableWidget->setItem(i, 3, populationItem);
        tableWidget->setItem(i, 4, numHouseholdsItem);
        tableWidget->setItem(i, 5, totalEmploymentItem);
        tableWidget->setItem(i, 6, sizeItem);
        tableWidget->setItem(i, 7, walkabilityItem);
        tableWidget->setItem(i, 8, transitScoreItem);
    }
}
