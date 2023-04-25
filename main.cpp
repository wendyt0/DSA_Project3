#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include "Location.h"
using namespace std;

void printMenu();

int main() {
    std::string location;
    std::string week;
    int command;

    std::cout << "Welcome to BnBeyond!" << std::endl;
    std::cout << "Where are you traveling to?" << std::endl;
    

    std::cin >> location;
    if(location == "amsterdam" || location == "athens" || location == "barcelona" || location == "berlin" || location == "budapest"
    || location == "lisbon" || location == "london" || location == "paris" || location == "rome" || location == "vienna") {
        std::cout << "Do you plan on staying during a weekend or a weekday?" << std::endl;
        cin >> week;
         if(week == "weekend" || week == "weekday") {
            std::ifstream file;
            
            file.open("dataset/" + location + "_" + week + "s.csv");
            std::string line;
            // The first line states what each index is for (price, distance, etc.)
            std::getline(file, line);
            std::vector<Location> locations;
            while(std::getline(file, line)) {
                std::stringstream s(line);
                std::vector<std::string> tempVec;
                while(s.good()) {
                    std::string temp;
                    std::getline(s, temp, ',');
                    tempVec.push_back(temp);
                }
                Location temp(tempVec[1], tempVec[10], tempVec[11], tempVec[9], tempVec[12], tempVec[13], tempVec[19], tempVec[18]);
                locations.push_back(temp);
                tempVec.clear();
            }
            file.close();
            // Test any index
            //locations[562].printAll();
            printMenu();
         }
         else {
            cout << "Invalid entry, please try again.";
         }
    }
    else {
        cout << "Sorry, we do not support that location at this time.";
    }
    
    return 0;
}

void printMenu() {
    cout << "Main Menu:" << endl;
    cout << "0. Sort by price" << endl;
    cout << "1. Sort by rating" << endl;
    cout << "2. Sort by capacity" << endl;
    cout << "3. Sort by cleanliness" << endl;
    cout << "4. Sort by distance to city center" << endl;
    cout << "5. Sort by distance to nearest metro" << endl;
    cout << "6. Exit" << endl;
    cout << "Please enter a command: " << endl;
}