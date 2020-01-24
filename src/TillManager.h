#ifndef TillMANAGER_H_
#define TillMANAGER_H_
#include <vector>
#include <map>
#include <string>
#include <fstream>
#include "MenuItem.h"

/**
 * Till Manager header file
 * 
 * This class allows you to create instances of a Till and has several
 * funtions to be able to manuplulate the data, such as getters, setters and deletes
 * 
 */
class TillManager{
    private:
        static TillManager *_instance; /** The class only allows one instance of the Till manager */
        std::vector<Till> tills; /** The class allows one instance of a till list per instance manager reference */

      /**
        * Till manager constructor
        * By setting these private it prevents copying and assignment to other class as they should
        * not be accessing this
        * @param TillManager& other
        */ 
        TillManager(TillManager& other);
      /**
        * Till manager constructor
        * By setting these private it prevents copying and assignment to other class as they should
        * not be accessing this
        * @param TillManager other
        */ 
        TillManager& operator= (TillManager other);

    protected:
        TillManager(); /** Prevents instantiation of the of the Till manager by making a protected class */


    public:
       /**
         * Instance method
         * There is no public constructor (singleton) but instead an instance method to get the singleton object 
         */
        static TillManager & instance();

       /**
         * Till manager destructor
         * This is a virtual method that is meant to be a destructor of an instance that is no longer required 
         */
        virtual ~TillManager(); 

       /**
         * Tills getter method
         * This is a get method that gets the set of tills and returns them
         * @return vector set of tills
         */
        std::vector <MenuItem> getTills();

       /**
         * Tills setter method
         * This is a set method that takes a set of tills and replaces the current set with such
         * @param vector set of tills
         */
        void setTills(std::vector <Till> tills);
        
       /**
         * Here are some additional methods to help maintain the data structure
         */
        void printAllTills();   
        void printTill(std::string id);    
        void addTill(Till till);   
        void removeTill(std::string id); 
        void removeTill(Till till);   
        Till * findTill(std::string id);
};

#endif 
/*TILLMANAGER_H_*/
