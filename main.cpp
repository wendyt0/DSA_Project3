#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include "Location.h"
using namespace std;

void printMenu();

int main() {
    string location;
    string week;
    int command;
    string sort;

    cout << "Welcome to BnBeyond!" << endl;
    cout << "Where are you traveling to? ";
    cin >> location;
    if(location == "amsterdam" || location == "athens" || location == "barcelona" || location == "berlin" || location == "budapest"
    || location == "lisbon" || location == "london" || location == "paris" || location == "rome" || location == "vienna") {
        cout << "Do you plan on staying during a weekend or a weekday? ";
        cin >> week;
         if(week == "weekend" || week == "weekday") {
            ifstream file;
            file.open("dataset/" + location + "_" + week + "s.csv");
            string line;
            // The first line states what each index is for (price, distance, etc.)
            getline(file, line);
            vector<Location> locations;
            while(getline(file, line)) {
                stringstream s(line);
                vector<std::string> tempVec;
                while(s.good()) {
                    string temp;
                    getline(s, temp, ',');
                    tempVec.push_back(temp);
                }
                Location temp(tempVec[1], tempVec[10], tempVec[11], tempVec[9], tempVec[12], tempVec[13], tempVec[19], tempVec[18]);
                locations.push_back(temp);
                tempVec.clear();
            }
            file.close();
            // Test any index
//            locations[562].printAll();
            printMenu();
            cin >> command;

            cout << "Would you like to perform a quick sort or a merge sort? ";
            cin >> sort;
            if(sort == "quick") {
                QuickSort(locations, 0, locations.size()-1, command);
                if(command == 0) {
                    cout << "Sorting by price, the 5 cheapest airbnb are as follows: " << endl;
                }
                else if(command == 1) {
                    cout << "Sorting by rating, the 5 highest rated airbnb are as follows: " << endl;
                }
                else if(command == 2) {
                    cout << "Sorting by capacity, the 5 airbnb with greatest guest satisfaction overall are as follows: " << endl;
                }
                else if(command == 3) {
                    cout << "Sorting by cleanliness, the 5 airbnb rated most clean are as follows: " << endl;
                }
                else if(command == 4) {
                    cout << "Sorting by distance to city center, the 5 airbnb closet to the center are as follows: " << endl;
                }
                else if(command == 5) {
                    cout << "Sorting by distance to nearest metro, the 5 airbnb closet to a metro are as follows: " << endl;
                }
                for(int i = 0; i < 5; i++) {
                    locations[i].printAll();
                }
            }
            else if(sort == "merge") {
                if(command == 0) {
                    mergeSort(locations, 0, locations.size() - 1, command);
                    cout << "Sorting by price, the 5 cheapest airbnb are as follows: " << endl;
                }
                else if(command == 1) {
                    cout << "Sorting by rating, the 5 highest rated airbnb are as follows: " << endl;
                }
                else if(command == 2) {
                    cout << "Sorting by capacity, the 5 airbnb with greatest guest satisfaction overall are as follows: " << endl;
                }
                else if(command == 3) {
                    cout << "Sorting by cleanliness, the 5 airbnb rated most clean are as follows: " << endl;
                }
                else if(command == 4) {
                    cout << "Sorting by distance to city center, the 5 airbnb closet to the center are as follows: " << endl;
                }
                else if(command == 5) {
                    cout << "Sorting by distance to nearest metro, the 5 airbnb closet to a metro are as follows: " << endl;
                }
                for(int i = 0; i < 5; i++) {
                    locations[i].printAll();
                }
            }
            else {
                cout << "Invalid entry, please try again.";
            }
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
    cout << "Please enter a command: ";
}