#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Location {
    std::string price;
    std::string rating;
    std::string capacity;
    std::string cleanliness;
    std::string distanceToCenter;
    std::string distanceToNearestMetro;
    std::string latitude;
    std::string longitude;

public:
    Location(std::string a, std::string b, std::string c, std::string d, std::string e, std::string f, std::string g, std::string h);
    void printAll();
    int QuickSortHelper(vector<Location> &v, int start, int end);
    void QuickSort(vector<Location> &v, int start, int end);
};

Location::Location(std::string a, std::string b, std::string c, std::string d, std::string e, std::string f, std::string g, std::string h) {
    price = a;
    rating = b;
    capacity = c;
    cleanliness = d;
    distanceToCenter = e;
    distanceToNearestMetro = f;
    latitude = g;
    longitude = h;
}

void Location::printAll() {
    std::cout << "Price: " << price << std::endl;
    std::cout << "Rating: " << rating << std::endl;
    std::cout << "Capacity: " << capacity << std::endl;
    std::cout << "Cleanliness: " << cleanliness << std::endl;
    std::cout << "DTC: " << distanceToCenter << std::endl;
    std::cout << "DTNM: " << distanceToNearestMetro << std::endl;
    std::cout << "Lat: " << latitude << std::endl;
    std::cout << "Long: " << longitude << std::endl;
}

//Quick Sort Function
int QuickSortHelper(vector<int> &v, int start, int end) {
    int pivot = end;
    int j = start;
    for(int i = start; i < end; i++) {
        if(v[i] < v[pivot]) {
            swap(v[i], v[j]);
            j++;
        }
    }
    swap(v[j], v[pivot]);
    return j;
}

void QuickSort(vector<Location> &v, int start, int end) {
    if(start < end) {
        int p = QuickSortHelper(v, start, end);
        QuickSort(v, start, p-1);
        QuickSort(v, p+1, end);
    }
}
