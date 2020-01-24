/**
 *@brief User class
 *
 *user creation class, this takes 5 variables and sets these to be attributes of the classes under each of their own names
 *checks if it is a manager or an employee and assigns them a type and allowed commands
 * @author Kajal Patel
 */


#include <string>
#include <iostream>
#include <algorithm>
#include "User.h"

using namespace std;



/**
 * @brief User constructor
 * Creates a new user by taking in parameters to set user information
 *
 * @param string user id
 * @param string first name
 * @param string last name
 * @param string user type
 * @param string password
 */
User::User(string uID, string uFName, string uLName, string uType, string uPass){
   	transform(uType.begin(), uType.end(), uType.begin(), ::tolower);
	this->uID = uID;
	this->uFName = uFName;
	this->uLName = uLName;
	this->uType = uType;
	this->uPass = uPass;
	string commands[] = {"getManagers", "getEmployees", "getStaff", "addStaff", "removeStaff","addItem","removeItem","saleTransaction","viewItem","viewInventory"};
	this->commandsvec.assign(commands,end(commands));

	if(uType.compare("manager")==0){
		this->selectvec.assign(commands,end(commands));
	}else if(uType.compare("employee")==0){
		string employee[] = {"addItem","removeItem","saleTransaction","viewItem","viewInventory"};
		this->selectvec.assign(employee,end(employee));
	}
}
/**
 * @brief User destructor
 * Destroys the user object 
 */
User::~User(){
	;
}

/**
 * @briefID getter method
 *
 * @return string user id 
 */
string User::getUID(){
	return this->uID;
}

/**
 * @briefFirst name getter method
 *
 * @return string user first name 
 */
string User::getUFName(){
	return this->uFName;
}

/**
 * @briefLast name getter method
 *
 * @return string user last name 
 */
string User::getULName(){
	return this->uLName;
}

/**
 * @briefUser type getter method
 *
 * @return string user type 
 */
string User::getUType(){
	return this->uType;
}

/**
 * @brief Password getter method
 *
 * @return string user password 
 */
string User::getUPass(){
	return this->uPass;
}
		
/**
 * @brief ID setter method
 *
 * @param string user id  
 */
void User::setUID(string uID){
	this->uID = uID;
}

/**
 * @brief First name setter method
 *
 * @param string user first name  
 */
void User::setUFName(string uFName){
	this->uFName = uFName;
}

/**
 * @brief First name setter method
 *
 * @param string user first name  
 */
void User::setULName(string uLName){
	this->uLName = uLName;
}

/**
 * @brief User type setter method
 *
 * @param string user type  
 */
void User::setUType(string uType){
	this->uType = uType;
}

/**
 * @brief Password setter method
 *
 * @param string user password  
 */
void User::setUPass(string uPass){
	this->uPass = uPass;
}
	
/**
 * @brief Check command method
 *
 * This checks if the user has the ability to be able to access a certain commands or not 
 * @param string command to check 
 * @return bool value true if given user can access command, false otherwise
 */
bool User::checkCommand(std::string command){
    for (unsigned int i = 0; i < this->selectvec.size(); i++) {
        if(this->selectvec[i].compare(command) ==0){
			return true;
		}
	}
	return false;
}

/**
 * @brief Return all commands method
 *
 * Returns all commands found my commandsvec  
 * @return vector containing all commands
 */
vector <string> User::returnAllCommands(){
	return this-> commandsvec;
}

/**
 * @brief Return select commands method
 * Returns some commands found my selectvec 
 * @return vector containing select commands
 */

vector <string> User::returnSelectCommands(){
	return this->selectvec;
}

/**
 * @brief Print all commands method
 * Prints all commands found my commandsvec in a for loop
 */
void User::printAllCommands(){
	cout<<"Printing all commands"<<endl;

    for (unsigned int i = 0; i < this->commandsvec.size(); i++) {
        cout<<this->commandsvec[i]<<endl;
	}
}

/**
 * @brief Print select commands method
 * Print select commands, print some commands found my selectvec
 */
void User:: printSelectCommands(){
	cout<<"Printing select commands for this user"<<endl;

    for (unsigned int i = 0; i < this->selectvec.size(); i++) {
        cout<<this->selectvec[i]<<endl;
	}
}
