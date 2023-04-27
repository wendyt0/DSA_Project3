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
    void printInfo(int command);
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
    string getInfo(int command);
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

void Location::printInfo(int command) {
    if(command == 0)
        std::cout <<  "Price: ";
    if(command == 1)
        std::cout << "Rating: ";
    if(command == 2)
        std::cout << "Capacity: ";
    if(command == 3)
        std::cout << "Cleanliness: ";
    if(command == 4)
        std::cout << "Distance to center: ";
    if(command == 5)
        std::cout << "Distance to nearest metro: ";
    std::cout << getInfo(command) << std::endl;
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

string Location::getInfo(int command) {
    if(command == 0)
        return price;
    if(command == 1)
        return rating;
    if(command == 2)
        return capacity;
    if(command == 3)
        return cleanliness;
    if(command == 4)
        return distanceToCenter;
    if(command == 5)
        return distanceToNearestMetro;
    return "";
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

void merge(vector<Location> &v, int left, int mid, int right, int command) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<Location> x;
    vector<Location> y;

    for(int i = 0; i < n1; i++) 
        x.push_back(v[left + i]);
    for(int j = 0; j < n2; j++)
        y.push_back(v[mid + 1 + j]);
    int i = 0;
    int j = 0;
    int k = left;

    while(i < n1 && j < n2) {

        if(stof(x[i].getInfo(command)) >= stof(y[j].getInfo(command))) {
            v[k] = x[i];
            i += 1;
        }
        else {
            v[k] = y[j];
            j += 1;
        }
        k += 1;
    }
    while(i < n1) {
        v[k] = x[i];
        i += 1;
        k += 1;
    }
    while(j < n2) {
        v[k] = y[j];
        j += 1;
        k += 1;
    }
}

void mergeSort(vector<Location> &v, int left, int right, int command) {

    if(left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(v, left, mid, command);
        mergeSort(v, mid + 1, right, command);

        merge(v, left, mid, right, command);
    }

}
