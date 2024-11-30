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
{
    ui->setupUi(this);

    ui->locationTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    std::vector<Location> locations = Table::generateLocations(10);
    Table::populate(ui->locationTable, locations);

}

MainWindow::~MainWindow()
{
    delete ui;
}

