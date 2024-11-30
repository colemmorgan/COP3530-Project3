#include "mainwindow.h"
#include <location.h>
#include <QApplication>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
