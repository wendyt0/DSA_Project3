#include <iostream>
using namespace std;

int main() {
    int command;
    cout << "Welcome to BnBeyond!" << endl;
    cout << "Main Menu:" << endl;
    cout << "0. Sort by price" << endl;
    cout << "1. Sort by rating" << endl;
    cout << "2. Sort by capacity" << endl;
    cout << "3. Sort by cleanliness" << endl;
    cout << "4. Sort by distance to city center" << endl;
    cout << "5. Sort by distance to nearest metro" << endl;\
    cout << "6. Exit" << endl << endl;
    cout << "Please enter a command: ";
    cin >> command;

    return 0;
}
