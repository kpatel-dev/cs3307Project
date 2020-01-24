/**
 *@brief File loader class
 *
 * This is the header file for the user data loader class, as its name might suggest it loads users.
 * The constructor reads in from the input filestream with the parameters being the fileName
 * then opens the file and reads in various pieces of information to help understand.
 * Next line by line in loop reads in from the file and adds it to the array where it can be used later
 * Then the array is used to send to addUser where it can be added
 *
 * @author Fahreen Bushra
 * @date October 30, 2019
 *
 */


#ifndef DATA_H_
#define DATA_H_

#include "FileLoader.h"


class UserDataLoader: public FileLoader{

    private:
        
        /**
         * @brief adduser method for the creation of new user profiles
         *the users are individually added to the set where it will be used to perform authentication and authorization
         *@param string id of the user
         *@param string firstname of user
         *@param string lastname of user
         *@param string type of user
         *@param string password of user
         */
        void addUser(std:: string id, std:: string fname, std:: string lname, std:: string type, std:: string password);

    public:
  
        /**
         *@brief method for the bulk of loading all of the users in a file
         *@param fileName that has a file of user information
         */
        UserDataLoader(std :: string fileName);
  

};
#endif
