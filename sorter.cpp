#include "sorter.h"
#include <vector>
#include <chrono>

using namespace std;

bool compareLocations(Location &a, Location &b, string &attribute) {
    if (attribute == "tractCode") {
        if (a.tractCode < b.tractCode) {
            return true;
        } else {
            return false;
        }
    } else if (attribute == "blockGroup") {
        if (a.blockGroup < b.blockGroup) {
            return true;
        } else {
            return false;
        }
    } else if (attribute == "name") {
        if (a.name < b.name) {
            return true;
        } else {
            return false;
        }
    } else if (attribute == "population") {
        if (a.population < b.population) {
            return true;
        } else {
            return false;
        }
    } else if (attribute == "numHouseholds") {
        if (a.numHouseholds < b.numHouseholds) {
            return true;
        } else {
            return false;
        }
    } else if (attribute == "totalEmployment") {
        if (a.totalEmployment < b.totalEmployment) {
            return true;
        } else {
            return false;
        }
    } else if (attribute == "size") {
        if (a.size < b.size) {
            return true;
        } else {
            return false;
        }
    } else if (attribute == "walkability") {
        if (a.walkability < b.walkability) {
            return true;
        } else {
            return false;
        }
    } else if (attribute == "transitScore") {
        if (a.transitScore < b.transitScore) {
            return true;
        } else {
            return false;
        }
    }

}
void merge(vector<Location> &locations, int left, int mid, int right, string &attribute) {
    vector<Location> temp(right - left + 1);

    int i = left;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= right) {
        if (compareLocations(locations[i], locations[j], attribute)) {
            temp[k++] = locations[i++];
        } else {
            temp[k++] = locations[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = locations[i++];
    }

    while (j <= right) {
        temp[k++] = locations[j++];
    }

    for (int t = 0; t < temp.size(); ++t) {
        locations[left + t] = temp[t];
    }
}

void mergeRecursionHelper(vector<Location> &locations, int left, int right, string &attribute) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeRecursionHelper(locations, left, mid, attribute);
        mergeRecursionHelper(locations, mid + 1, right, attribute);

        merge(locations, left, mid, right, attribute);
    }
}

double mergeSort(vector<Location> *locations, string attribute) {
    auto start = chrono::high_resolution_clock::now();
    mergeRecursionHelper(*locations, 0, locations->size() - 1, attribute);
    auto end = chrono::high_resolution_clock::now();
    return chrono::duration<double>(end - start).count();
}

double shellSort(vector<Location> *locations, string attribute) {
    auto start = chrono::high_resolution_clock::now();
    int n = locations->size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; ++i) {
            Location temp = (*locations)[i];
            int j;
            for (j = i; j >= gap && compareLocations(temp, (*locations)[j - gap], attribute); j -= gap) {
                (*locations)[j] = (*locations)[j - gap];
            }
            (*locations)[j] = temp;
        }
    }
    auto end = chrono::high_resolution_clock::now();
    return chrono::duration<double>(end - start).count();
}

double bubbleSort(vector<Location> *locations, string attribute) {
    auto start = chrono::high_resolution_clock::now();
    int n = locations->size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (!compareLocations((*locations)[j], (*locations)[j + 1], attribute)) {
                swap((*locations)[j], (*locations)[j + 1]);
            }
        }
    }
    auto end = chrono::high_resolution_clock::now();
    return chrono::duration<double>(end - start).count();
}
