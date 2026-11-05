
/*
main.c++: Have user log in to access CPlusPlus Tutor.  User can review topics, view learning track, or exit program.
    User will be able to progress through 7 different units on C++.
Names: Christopher Minter, Daniel Miranda, Jonathan Raposo Luna, Sebastian Mora, Erik Sadoff, Joseph Sorrento
Date: Oct. 28, 2026-Nov. 25, 2026
*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Prototypes
int displayMenu();


//  File to store user login information and progress


int main()
{
    bool running = true;
    int option;
    while (running)
    {

        option = displayMenu();

        switch (option)
        {
        case 1:
            cout << "******* Sign In *******" << endl;
            break;
        case 2:
            cout << "****** Log In *******" << endl;
            break;
        case 3:
            cout << "******* Review Topics" << endl;
            break;
        case 4:
            cout << "******* Show Learning Track" << endl;
            break;
        case 5:
            cout << "Good Bye ..." << endl;
            running = false;
            break;
        }
    }
}
int displayMenu()
{
    int option;
    do
    {
        cout << "\n---------------------------" << endl;
        cout << "   C++ Tutor App  " << endl;
        cout << "---------------------------" << endl;
        cout << "Choose one of the following:" << endl;
        cout << "\t1. Sign Up" << endl;
        cout << "\t2. Log in" << endl;
        cout << "\t3. Review Topics" << endl;
        cout << "\t4. Show Learning Track" << endl;
        cout << "\t5. Exit" << endl;
        cout << "Option: ";
        cin >> option;
        if (option < 1 || option > 5)
        {
            cout << "\nInvalid Option. Try again.\n";
        }

    } while (option < 1 || option > 5);
    return option;
}
