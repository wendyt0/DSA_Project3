#include <iostream>
using namespace std;

int main() {
//    int command;
    string location;
    string week;
    string filename;
    int command;
    cout << "Welcome to BnBeyond!" << endl;
    cout << "Where are you traveling to? ";
    cin >> location;
    if(location == "amsterdam" || location == "athens" || location == "barcelona" || location == "berlin" || location == "budapest"
    || location == "lisbon" || location == "london" || location == "paris" || location == "rome" || location == "vienna") {
        cout << "Do you plan on staying during a weekend or a weekday? ";
        cin >> week;
        if(week == "weekend" || week == "weekday") {
            filename = location + "_" + week + ".csv";
            cout << endl << "Main Menu:" << endl;
            cout << "0. Sort by price" << endl;
            cout << "1. Sort by rating" << endl;
            cout << "2. Sort by capacity" << endl;
            cout << "3. Sort by cleanliness" << endl;
            cout << "4. Sort by distance to city center" << endl;
            cout << "5. Sort by distance to nearest metro" << endl;\
            cout << "6. Exit" << endl;
            cout << "Please enter a command: ";
            cin >> command;
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
