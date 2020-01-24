/*
 * 	Filename: mycp.cpp
 *  Created on: Oct. 3, 2019
 *  Author: kajalpatel
 *
 *  Description: Copies a file from the source to the destination which are provided as parameters from the command line.
 */

#include <iostream>
#include <string>
#include "User.h"
#include "StaffManager.h"

using namespace std;

/**
 * MAIN
 * */

void printAllStaff(){
	StaffManager::instance().printAllStaff();
}

void printManagers(){
	StaffManager::instance().printAllManagers();
}

void printEmployees(){
	StaffManager::instance().printAllEmployees();
}

User addUser(string id, string fname, string lname, string type, string password){
    User user(id, fname, lname, type,password);
	StaffManager::instance().addStaff(user);
    return user;
}

void removeUser(std::string userId){
	StaffManager::instance().removeStaff(userId);
}



int main(int argc, char *argv[]) {
    printAllStaff();

    //create a manager account
    User user1 = addUser("manager1", "fname", "lname", "Manager","password");
    cout<<"Has command 'getStaff?' "<<(user1.checkCommand("getStaff")? "true" : "false")<<endl<<endl;
    user1.printAllCommands();
    cout<<endl<<endl;
    user1.printSelectCommands();

    //create a employee account
    cout<<endl<<endl;
    User user2 = addUser("employee1", "fname", "lname", "employee","password");
    cout<<"Has command 'getStaff?' "<<(user2.checkCommand("getStaff")? "true" : "false")<<endl<<endl;
    cout<<"Has command 'addItem?' "<<(user2.checkCommand("addItem")? "true" : "false")<<endl<<endl;
    user2.printAllCommands();
    cout<<endl<<endl;
    user2.printSelectCommands();

    //prints the employee and manager
    printAllStaff();
    //prints just the managers
    printManagers();
    //prints just the employees
    printEmployees();

    //try to add a user with existing user id
    cout<<endl<<endl;
    User user3 = addUser("manager1", "fname", "lnamse", "manager","password");

    //try to remove a user without existing user id
    cout<<endl<<endl;
    removeUser("fake");

    //remove a user and  see it was removed from the systems
    removeUser("manager1");
    printAllStaff();

    return 0;

}
