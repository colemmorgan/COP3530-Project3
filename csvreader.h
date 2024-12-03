#ifndef CSVREADER_H
#define CSVREADER_H

#include <fstream>
#include "location.h"
#include <vector>

using namespace std;

class CSVReader{

public:
    CSVReader();

    //function to push locations onto a vector and then the GUI
    vector<Location> into_vector(string name);

    //if want to see what is in the vector of structs
    void printLocations(const vector<Location>& locations);
};

#endif // CSVREADER_H
