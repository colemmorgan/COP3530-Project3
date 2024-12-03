#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTableWidget>
#include <QTableWidgetItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , sortingButtons(new SortingButtons(this))
    , table()
{
    ui->setupUi(this);
    ui->progressBar->setVisible(false);
    setWindowTitle("Relocation Assistant");
    table.setUi(ui); // pass ui to table
    sortingButtons->setTable(&table); // pass table to sorting buttons


    // add the sorting filters to a button group so we can monitor a click.
    sortingButtons->addButtonToGroup(ui->population);
    sortingButtons->addButtonToGroup(ui->walkability);
    sortingButtons->addButtonToGroup(ui->totalEmployment);
    sortingButtons->addButtonToGroup(ui->size);
    sortingButtons->addButtonToGroup(ui->numHouseholds);
    sortingButtons->addButtonToGroup(ui->transitScore);

    // Monitor whether users are switching the sorting mode (least, greatest)
    connect(ui->sort, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::onSortByChanged);

    // Configure table and update row count
    ui->locationTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->locationTable->setShowGrid(false);
    table.populate();
    ui->row_count->setText(QString::number(table.getSize()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

// handle sort mode being changed
void MainWindow::onSortByChanged(int index)
{
    std::string mode = ui->sort->itemText(index).toStdString();
    table.handleSortModeChange(mode);
}
