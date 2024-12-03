#include "table.h"
#include <QString>
#include <QTableWidgetItem>
#include <algorithm>


Table::Table() {
    // load locations into table
    CSVReader csv;
    locations = csv.into_vector("./data.csv");
}

void Table::setUi(Ui::MainWindow *ui) {
    this->ui = ui;
}

int Table::getSize() {
    return static_cast<int>(locations.size());
}

void Table::sortData(std::string attribute) {

    ui->progressBar->setRange(0, 100);
    ui->progressBar->setValue(0);
    ui->progressBar->setVisible(true);
    ui->locationTable->clear();
    QCoreApplication::processEvents();

    // Complete each sorting method, update the timings and progress bar, then process the event q
    std::vector<Location> copy = locations;
    double mergeTime = sorter.mergeSort(&copy, attribute);
    ui->mergeTime->setText(QString::number(mergeTime) + "s");
    ui->progressBar->setValue(33);
    QCoreApplication::processEvents();

    copy = locations;
    double shellTime = sorter.shellSort(&copy, attribute);
    ui->shellTime->setText(QString::number(shellTime) + "s");
    ui->progressBar->setValue(66);
    QCoreApplication::processEvents();

    double bubbleTime = sorter.shellSort(&locations, attribute);
    ui->bubbleTime->setText(QString::number(bubbleTime) + "s");
    ui->progressBar->setValue(100);
    QCoreApplication::processEvents();

    // repopulate table with sorted data and hide progress bar
    populate();
    ui->progressBar->setVisible(false);
}
void Table::handleSortModeChange(std::string mode) {
    if (!ui) return;
    if (sortMode == mode) return;

    sortMode = mode;
    // Clear the table and repopulate
    ui->locationTable->setRowCount(0);
    populate();
}

void Table::populate() {
    if (!ui) return;
    QTableWidget *tableWidget = ui->locationTable;

    int totalLocations = static_cast<int>(locations.size());
    int minimum = std::min(totalLocations, 100);

    // Construct Table
    tableWidget->setRowCount(minimum);
    tableWidget->setColumnCount(9);
    tableWidget->setHorizontalHeaderLabels({
        "Tract Code", "Block Group", "Name", "Population",
        "Households", "Employment", "Size", "Walkability", "Transit"
    });

    // Greatest 100 elements
    if (sortMode == "Greatest") {
        for (int i = 0; i < minimum; ++i) {
            displayData(i, locations[totalLocations - 1 - i]);
        }
    }
    // Least 100 elements
    else {
        for (int i = 0; i < minimum; ++i) {
            displayData(i, locations[i]);
        }
    }
}

void Table::displayData(int row, const Location &loc) {
    if (!ui) return;
    QTableWidget *tableWidget = ui->locationTable;

    // Create row from location
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
