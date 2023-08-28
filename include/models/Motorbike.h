#include <iostream>     //use string
#include <fstream>      //save to appdata.txt
#include <limits>       //check integer
#include <string.h>     //use string function
using namespace std;    //use std

class motorbike{
public:
    string OWNER, MODEL, COLOR, ENGINE_SIZE, TRANSMISSION_MODE, DESCRIPTION;
    int YEAR_MADE=0;
    void NEW_BIKE(string USERS_NAME){
        
        OWNER= USERS_NAME;
        cout << "\nThis bike is a property of user " <<OWNER;

        cout << "\nEnter your bike model:\n";
        cin >> MODEL;

        cout << "Enter your bike color:\n";
        cin >> COLOR;

        cout << "Enter your bike's engine size:\n";
        cin >> ENGINE_SIZE;
        
        cout << "Enter your bike's transmission mode:\n";
        cin >> TRANSMISSION_MODE;

        while (YEAR_MADE<1500 || YEAR_MADE>2023){
            cout << "Enter the year yor bike made:\n";
            cin >> YEAR_MADE;
            if (cin.fail()){
                cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "Invalid input. Please try again\n";
            }
        }
        
        cout << "Enter your bike description:\n";
        cin >> DESCRIPTION;
        
    }
    void showinfo(){
        cout << "\nThis bike is a property of member: " << OWNER;
        cout << "This bike model : " << MODEL;
        cout << "This bike color:  " << COLOR;
        cout << "This bike engine size: " << ENGINE_SIZE;
        cout << "This bike transmission mode: " << TRANSMISSION_MODE;
        cout << "This bike description: " << DESCRIPTION;
    }
};