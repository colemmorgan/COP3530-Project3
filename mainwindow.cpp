#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include <iostream>




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , sortingButtons(new SortingButtons(this))
    , table()
{
    ui->setupUi(this);
    sortingButtons->setTable(&table);
    setWindowTitle("Relocation Assistant");

    sortingButtons->addButtonToGroup(ui->population);
    sortingButtons->addButtonToGroup(ui->walkability);
    sortingButtons->addButtonToGroup(ui->totalEmployment);
    sortingButtons->addButtonToGroup(ui->size);
    sortingButtons->addButtonToGroup(ui->numHouseholds);
    sortingButtons->addButtonToGroup(ui->transitScore);

    ui->locationTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->locationTable->setShowGrid(false);
    table.populate(ui->locationTable);
    ui->row_count->setText(QString::number(table.getSize()));

    connect(ui->sort, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::onSortByChanged);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::onSortByChanged(int index)
{
    std::string mode = ui->sort->itemText(index).toStdString();
    std::cout << mode << std::endl;
    table.handleSortModeChange(ui->locationTable, mode);
}
