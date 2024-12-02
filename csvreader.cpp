//
// Created by dlleo on 12/2/2024.
//
#include "csvreader.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

CSVReader::CSVReader() {
    // Empty constructor implementation
}

vector<Location> CSVReader::into_vector(string name) {
    //pass in csv file to read
    ifstream datafile(name);

    //vector of Locations
    vector<Location> Locations;

    //ensure file is open
    if (datafile.is_open()) {
        cout << "open" << endl;
    } else {
        cout << "not open" << endl;
    }

    //read first line with labels
    string firstline;
    getline(datafile, firstline);

    //while loop to read each line of the csv
    string singleLine;
    while (getline(datafile, singleLine)){
        //variable to help when delimiters are inconsistent
        string garbage;

        //create struct to store each tract
        Location locstruct;

        istringstream stream(singleLine);

        //tractCode (small region within a county)
        string tractCode;
        getline(stream, tractCode, ',');
        locstruct.tractCode = tractCode;

        //blockGroup
        string blockGroup;
        getline(stream, blockGroup, ',' );
        locstruct.blockGroup = blockGroup;

        //name of location (can be in two different columns, logic to compensate)
        bool tovect = true;
        string name1, name2, finalname;

        // check for the first potential name
        if (stream.peek() == '"') {
            getline(stream, garbage, '"');
            getline(stream, name1, '"');
            stream.ignore(1);
        } else {
            getline(stream, name1, ',');
        }

        // check for the second potential name
        if (stream.peek() == '"') {
            getline(stream, garbage, '"');
            getline(stream, name2, '"');
            stream.ignore(1);
        } else {
            getline(stream, name2, ',');
        }

        //logic if name is not in csv
        if (name1 != "") {
            finalname = name1;
        }
        else if (name2 != ""){
            finalname = name2;
        } else {
            tovect = false;
        }

        locstruct.name = finalname;

        //population
        string pop;
        getline(stream, pop, ',');
        int intpop = stoi(pop);
        locstruct.population = intpop;

        //number of households
        string housenum;
        getline(stream, housenum, ',');
        int inthousenum = stoi(housenum);
        locstruct.numHouseholds = inthousenum;

        //employment
        string totemploy;
        getline(stream, totemploy, ',');
        int inttotemploy = stoi(housenum);
        locstruct.totalEmployment = inttotemploy;

        //size
        string size;
        getline(stream, size, ',');
        float fsize = stof(size);
        locstruct.size = fsize;

        //walkability
        string walkability;
        getline(stream, walkability, ',');
        float fwalkability = stof(walkability);
        locstruct.walkability = fwalkability;

        //transitScore
        string transitScore;
        getline(stream, transitScore, ',');
        float ftransitScore = stof(transitScore);
        locstruct.transitScore = ftransitScore;

        if (tovect == true) {
            Locations.push_back(locstruct);
        }
    }

    return Locations;
}

void CSVReader::printLocations(const vector<Location>& locations) {
    for (size_t i = 0; i < locations.size(); ++i) { // Traditional for loop
        const Location& loc = locations[i]; // Access the current element
        std::cout << "Tract Code: " << loc.tractCode << "\n"
                  << "Block Group: " << loc.blockGroup << "\n"
                  << "Name: " << loc.name << "\n"
                  << "Population: " << loc.population << "\n"
                  << "Number of Households: " << loc.numHouseholds << "\n"
                  << "Total Employment: " << loc.totalEmployment << "\n"
                  << "Size: " << loc.size << "\n"
                  << "Walkability: " << loc.walkability << "\n"
                  << "Transit Score: " << loc.transitScore << "\n"
                  << "--------------------" "\n";
    }
}