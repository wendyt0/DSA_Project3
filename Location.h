#include <string>
#include <iostream>

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

