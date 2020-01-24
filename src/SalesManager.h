#ifndef SALESMANAGER_H_
#define SALESMANAGER_H_
#include <vector>
#include <map>
#include <string>
#include <fstream>
#include "MenuItem.h"

/**
 * Sales manager header file
 * 
 * This class allows you to create instances of a inventory and has several
 * funtions to be able to manuplulate the data, such as getters, setters and deletes
 * 
 */
class SalesManager{
    private:
        void SalesManager::printMenuItem(string itemName);
        static SalesManager *_instance; /** The class only allows one instance of the Sales manager */
        std::vector<MenuItem> items; /** The class allows one menu list per instance manager reference */

      /**
        * Sales manager constructor
        * By setting these private it prevents copying and assignment to other class as they should
        * not be accessing this
        * @param SalesManager& other
        */ 
        SalesManager(SalesManager& other);
      /**
        * Sales manager constructor
        * By setting these private it prevents copying and assignment to other class as they should
        * not be accessing this
        * @param SalesManager other
        */ 
        SalesManager& operator= (SalesManager other);

    protected:
        SalesManager(); /** Prevents instantiation of the of the Sales manager by making a protected class */


    public:
       /**
         * Instance method
         * There is no public constructor (singleton) but instead an instance method to get the singleton object 
         */
        static SalesManager & instance();

       /**
         * Sales manager destructor
         * This is a virtual method that is meant to be a destructor of an instance that is no longer required 
         */
        virtual ~SalesManager(); 

       /**
         * Menu items getter method
         * This is a get method that gets the set of menu items and returns them
         * @return vector set of menu items
         */
        std::vector <MenuItem> getSaleItems();

       /**
         * Here are some additional methods to help maintain the data structure
         */
        void printAllSaleItems();   
        void printSaleItem(std::string itemName);    
        MenuItem * findSaleItem(std::string name);
};

#endif 
/*SALEMANAGER_H_*/
