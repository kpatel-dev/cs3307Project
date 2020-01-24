/**
 *@brief User Data Loader class
 *
 * This is the user data loader class, as its name might suggest it loads user data.
 * The constructor reads in from the input filestream with the parameters being the fileName
 * then opens the file and reads in various pieces of information to help understand.
 * Next line by line in loop reads in from the file and adds it to the array where it can be used later
 * Then the array is used to send to addUser where it can be added
 *
 * @author Fahreen Bushra
 * @date October 31, 2019
 */


#include "UserDataLoader.h"
#include <iostream>
#include <fstream>
#include "StaffManager.h"
#include "User.h"
#include <sstream> 
#include <stdlib.h>


/**
 * @brief User Data Loader constructor
 * 
 * Reads in an input file amd extracts user information as decribed above
 * @param string name of file to be read 
 */
UserDataLoader ::UserDataLoader(std:: string fileName){
	std :: ifstream myfile;
	myfile.open(fileName);
	std:: string line;
	std :: string token;
	std:: string arr[5];
	
	char delim = ',';
	
	while (getline(myfile, line)){
		std:: stringstream ss(line);
		int i = 0;
		while(std:: getline(ss, token ,delim)){
			arr[i] = token;
			i++;}
			addUser(arr[2], arr[0] , arr[1], arr[3], arr[4]);
	}
	StaffManager::instance().printAllStaff();
	myfile.close();
};

/**
 * @brief Add user method
 * 
 * Method for the addition of individual users to the set
 * This is where the information of the array is sent, where it will be used to perform authentication and authorization
 * @param string user id
 * @param string user first name
 * @param string user last name
 * @param string type of user
 * @param string user password 
 */
void UserDataLoader :: addUser(std:: string id, std:: string fname, std:: string lname, std:: string type, std:: string password){
    User user(id, fname, lname, type,password);
	StaffManager::instance().addStaff(user);
	
	};
