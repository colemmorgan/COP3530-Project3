#include "mainwindow.h"
#include <location.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();

	//if you want to check if the locations are implemented properly

	//into_vector will return the vector of structs

    //CSVReader reader;
    //reader.printLocations(reader.into_vector("C:/Users/dlleo/OneDrive/Documents/misc/DSAProjData.csv"));
}
