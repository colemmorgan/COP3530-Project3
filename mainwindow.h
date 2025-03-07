#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <location.h>
#include <QMainWindow>
#include "SortingButtons.h"
#include "table.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onSortByChanged(int index);

private:
    Ui::MainWindow *ui;
    SortingButtons *sortingButtons;
    Table table;
};
#endif // MAINWINDOW_H
