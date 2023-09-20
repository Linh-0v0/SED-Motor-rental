#include <iostream>     
#include <limits>    
#include <string.h>     
using namespace std;  

void rateBike(){
    int rate;
    while (rate<1 || rate >10){
        if (cin.fail()){
                cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "Invalid input. Please try again\n";
        }
    }
    cout << "What is your rating for rental bike in a grade of 10 (1-10): \n";
    cin >> rate;    
}

void rateDriver(){
    int rate;
    string comment;
    while (rate>=1 || rate <=10){
        if (cin.fail()){
                cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "Invalid input. Please try again\n";
        }
    cout << "What is your rating for rental driver in a grade of 10 (1-10): \n";
    cin >> rate;
    }
    
    cout << "What is your comment for the driver: \n";
        while (comment==""){            
            getline(cin, comment);
        }

}