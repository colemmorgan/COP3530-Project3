#ifndef LOCATION_H
#define LOCATION_H
#include <string>

struct Location {
    // Location identifiers
    std::string tractCode;
    std::string blockGroup;
    std::string name;

    // Location statistics
    int population;
    int numHouseholds;
    int totalEmployment;
    float size;
    float walkability;
    float transitScore;
};

#endif // LOCATION_H
