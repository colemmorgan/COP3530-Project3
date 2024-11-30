#ifndef SORTER_H
#define SORTER_H
#include "location.h"
#include <string>
#include <vector>

class Sorter
{
public:
    double mergeSort(std::vector<Location> *locations, std::string attribute);
    double shellSort(std::vector<Location> *locations,  std::string attribute);
    double bubbleSort(std::vector<Location> *locations,  std::string attribute);

};

#endif // SORTER_H
