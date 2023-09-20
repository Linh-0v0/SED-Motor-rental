#include <iostream>
#include "include/models/User.h"
#include "include/models/Motorbike.h"

int main() {
    cout << "\nEEET2482/COSC2082 ASSIGNMENT";
    cout << "\nMOTORBIKE RENTAL APPLICATION";
    cout << "\nInstructor: Dr. Ling Huo Chong";
    cout << "\nGroup: Group No.";
    cout << "\ns3805869, Student Name: Nguyen Truong Thinh.\nsXXXXXXX, Student Name:\nsXXXXXXX, Student Name:";
    member member1;
    motorbike motorbike1;
    while (1){
        int USER_ROLE=10, bike=0, command=0;
        // Intro:
        cout << "\n\nUse the app as \n1. Guest \n2. Member[sign in required] \n3. Admin [sign in required]";
        cout << "\nEnter your choice:";

        //check role
        while (USER_ROLE<1 || USER_ROLE >3){
            cin >> USER_ROLE;
            if (cin.fail()){
                cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "Invalid input. Please try again\n";
            }
        }

        cout << "Access Granted!\nYou are accessed as ";
        
        // Access as Guest
        if (USER_ROLE==1){
            cout << "Guest\n";
            while (1){
                cout << "As a guest, you can:\n1. Exit Program.\n2. View all motorbike details\n3. Rent a motorbike (register required)\n4. Sign up/ Register\n";
                cout << "\nEnter your choice:";
                cin >> command;
                if (cin.fail()){
                    cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout << "Invalid input. Please try again\n";
                }else if (command == 1){
                    break;
                }else if (command == 3 || command == 4){
                    if (command == 3){cout << "In order to rent a bike, you need to register first.\n";}
                    bike = member1.NEW_MEMBER();
                    if (bike){
                        motorbike1.NEW_BIKE(member1.USERS_NAME);
                    }
                    //Add to appdata.txt
                    APPEND_USER_INFO(member1);
                    member1.showinfo();
                    if (bike){
                        //
                        APPEND_BIKE_INFO(motorbike1);
                        motorbike1.showinfo();
                    }

                    cout << "\nYou are now a Member. Please sign in again.\n";
                    USER_ROLE=2;
                    break;
                }
            }
        }
        
        
        // Access as Member 
        else if (USER_ROLE==2){
            cout << "Member\n";
            while (1){
                cout << "As a member, you can:\n1. Exit Program.\n2. View all motorbike details\n3. Rent a motorbike\n4. Show info\n5. Manage your bike\n6. Search for motorbike\n7. View requests\n8. Rating\n9.\u001b[31mAdd credit point\u001b[0m";
                cin >> command;
                if (cin.fail()){
                    cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout << "Invalid input. Please try again\n";
                }else if (command == 1){
                    break;
                }else if (command == 2){
                    break;
                }else if (command == 3){
                    break;
                }else if (command == 4){
                    break;
                }else if (command == 5){
                    break;
                }else if (command == 6){
                    break;
                }else if (command == 7){
                    break;
                }else if (command == 8){
                    break;
                }else if (command == 9){
                    member1.topsup();
                    break;
                }
            }
        }
        
        

        // Access as Admin
        else {
            cout << "Admin\n";
            while(1){
                cout << "As an admin, you can:\n1. Exit Program.\n2. View all motorbike details\n3. View all users detail.\n";
                cin >> command;
                if (cin.fail()){
                    cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout << "Invalid input. Please try again\n";
                }else if (command == 1){
                    break;
                }else if (command == 2){
                    break;
                }else if (command == 3){
                    break;
                }
            }
        }
    }
}
