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
    int QuickSortHelper(vector<Location> &v, int start, int end, int command);
    void QuickSort(vector<Location> &v, int start, int end, int command);
    string getPrice();
    string getRating();
    string getCapacity();
    string getCleanliness();
    string getDTC();
    string getDTNM();
    string getLat();
    string getLong();
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
    cout << endl;
}

string Location::getPrice() {
    return price;
}

string Location::getRating() {
    return rating;
}

string Location::getCapacity() {
    return capacity;
}

string Location::getCleanliness() {
    return cleanliness;
}

string Location::getDTC() {
    return distanceToCenter;
}

string Location::getDTNM() {
    return distanceToNearestMetro;
}

string Location::getLat() {
    return latitude;
}

string Location::getLong() {
    return longitude;
}

//Quick Sort Function
int QuickSortHelper(vector<Location> &v, int start, int end, int command) {
    if(command == 0) {
        int pivot = end;
        int j = start;
        for (int i = start; i < end; i++) {
            if (stof(v[i].getPrice()) < stof(v[pivot].getPrice())) {
                swap(v[i], v[j]);
                j++;
            }
        }
        swap(v[j], v[pivot]);
        return j;
    }
    else if(command == 1) {
        int pivot = end;
        int j = start;
        for (int i = start; i < end; i++) {
            if (stof(v[i].getRating()) > stof(v[pivot].getRating())) {
                swap(v[i], v[j]);
                j++;
            }
        }
        swap(v[j], v[pivot]);
        return j;
    }
    else if(command == 2) {
        int pivot = end;
        int j = start;
        for (int i = start; i < end; i++) {
            if (stof(v[i].getCapacity()) > stof(v[pivot].getCapacity())) {
                swap(v[i], v[j]);
                j++;
            }
        }
        swap(v[j], v[pivot]);
        return j;
    }
    else if(command == 3) {
        int pivot = end;
        int j = start;
        for (int i = start; i < end; i++) {
            if (stof(v[i].getCleanliness()) > stof(v[pivot].getCleanliness())) {
                swap(v[i], v[j]);
                j++;
            }
        }
        swap(v[j], v[pivot]);
        return j;
    }
    else if(command == 4) {
        int pivot = end;
        int j = start;
        for (int i = start; i < end; i++) {
            if (stof(v[i].getDTC()) < stof(v[pivot].getDTC())) {
                swap(v[i], v[j]);
                j++;
            }
        }
        swap(v[j], v[pivot]);
        return j;
    }
    else if(command == 5) {
        int pivot = end;
        int j = start;
        for (int i = start; i < end; i++) {
            if (stof(v[i].getDTNM()) < stof(v[pivot].getDTNM())) {
                swap(v[i], v[j]);
                j++;
            }
        }
        swap(v[j], v[pivot]);
        return j;
    }
}

void QuickSort(vector<Location> &v, int start, int end, int command) {
    if (start < end) {
        float p = QuickSortHelper(v, start, end, command);
        QuickSort(v, start, p - 1, command);
        QuickSort(v, p + 1, end, command);
    }
}
