#include "../../include/models/User.h"

void READ_USER_INFO(){}

void APPEND_USER_INFO(member member1){
    cout << "\nYour infomation will be added in to our data base.";
    std::ofstream outfile;
    outfile.open("../../appdata.txt", std::ios_base::app); // append instead of overwrite
    
    outfile << member1.USERS_NAME;
}

void MODIFY_USER_INFO(){}


