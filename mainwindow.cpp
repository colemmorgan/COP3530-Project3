#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "location.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include <vector>
#include "table.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , sortingButtons(new SortingButtons(this))
{
    ui->setupUi(this);

    sortingButtons->addButtonToGroup(ui->population_sorter);
    sortingButtons->addButtonToGroup(ui->walkability_sorter);
    sortingButtons->addButtonToGroup(ui->employment_sorter);
    sortingButtons->addButtonToGroup(ui->size_sorter);
    sortingButtons->addButtonToGroup(ui->households_sorter);
    sortingButtons->addButtonToGroup(ui->transit_sorter);

    ui->locationTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->locationTable->setShowGrid(false);
    std::vector<Location> locations = Table::generateLocations(100);
    Table::populate(ui->locationTable, locations);

}

MainWindow::~MainWindow()
{
    delete ui;
}

