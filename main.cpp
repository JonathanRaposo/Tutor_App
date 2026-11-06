
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
int displayTutorMenu();
void displaySubMenu(int);
void signup(string);
bool login(string);
string getString(string);

//  File to store user login information and progress

int main()
{
    bool running = true;
    int option;
    string filename = "database/users.txt";
    int isFound;

    while (running)
    {

        option = displayMenu();

        switch (option)
        {
        case 1:
            cout << "******* Sign In *******" << endl;
            signup(filename);
            break;
        case 2:
            cout << "****** Log In *******" << endl;

            isFound = login(filename);

            if (isFound == 1)
            {
                option = displayTutorMenu();
                displaySubMenu(option);
            }
            else
            {
                cout << "\nInvalid username or password.\n";
            }

            break;

        case 3:
            cout << "Good Bye ..." << endl;
            running = false;
            break;
        }
    }

    return 0;
}

// Sign up new users
void signup(string filename)
{
    string userName;
    string storedUser;
    string storedPassword;
    string password;

    userName = getString("Enter username: ");

    // Open file to check whether user exists.
    ifstream inFile(filename);

    while (inFile >> storedUser >> storedPassword)
    {
        if (userName == storedUser)
        {
            cout << "\nUsername already exists. Try another one.\n";
            return;
        }
    }
    inFile.close();

    // User does not exists. Ask for password
    password = getString("Enter password: ");

    ofstream outFile(filename, ios::app);
    outFile << userName << " " << password << endl;
    outFile.close();
    cout << "\nUser registered successfully!\n";
}

bool login(string filename)
{

    string user, password;
    string inputUser, inputPass;
    // ... get inputUser / inputPass from cin ...
    inputUser = getString("Enter username: ");
    inputPass = getString("Enter password: ");

    ifstream inFile(filename);
    bool found = false;
    while (inFile >> user >> password)
    {
        if (user == inputUser && password == inputPass)
        {
            found = true;
            break;
        }
    }
    inFile.close();

    if (found)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Display menu option. Returns option
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
        cout << "\t3. Exit" << endl;
        cout << "Option: ";
        cin >> option;
        cin.ignore(1000, '\n');

        if (option < 1 || option > 3)
        {
            cout << "\nInvalid Option. Try again.\n";
        }

    } while (option < 1 || option > 3);
    return option;
}

// Menu for registered users
int displayTutorMenu()
{
    int option;

    do
    {
        cout << "\n---------------------------" << endl;
        cout << "   C++ Tutor App  " << endl;
        cout << "---------------------------" << endl;
        cout << "Choose one of the following:" << endl;
        cout << "\t1. Review Topics" << endl;
        cout << "\t2. Show Learning Track" << endl;
        cout << "\t3. Exit" << endl;
        cout << "Option: ";
        cin >> option;
        cin.ignore(1000, '\n');

        if (option < 1 || option > 3)
        {
            cout << "\nInvalid Option. Try again.\n";
        }

    } while (option < 1 || option > 3);
    return option;
}
void displaySubMenu(int option)
{
    do
    {
        switch (option)
        {

        case 1:
            cout << "****** Review Topics *******" << endl;
            // function here with implementation
            break;
        case 2:
            cout << "******* Show Learning Track ********" << endl;
            // function here with implementation
            break;
        case 3:
            cout << "\nBack to main menu\n";
            break;
        default:
            cout << "\nInvalid option. Try again\n";
            option = displayTutorMenu();
            break;
        }
    } while (option < 1 || option > 3);
}

// function to get input from user. it validates input
string getString(string msg)
{

    string input;

    while (true)
    {
        cout << msg;
        getline(cin, input);

        if (input.empty())
        {
            cout << "\nInvalid input. You must enter a value.\n";
            continue;
        }
        return input;
    }
}