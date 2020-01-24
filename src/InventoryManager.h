#ifndef INVENTORYMANAGER_H_
#define INVENTORYMANAGER_H_
#include <vector>
#include <map>
#include <string>
#include <fstream>
#include "MenuItem.h"

/**
 * @brief Inventory Manager class
 * 
 * This class allows you to create instances of a inventory and has several
 * funtions to be able to manuplulate the data, such as getters, setters and deletes
 * @author Kajal Patel
 * @date November 27, 2019
 */
class InventoryManager{
    private:
        static InventoryManager *_instance; /**<The class only allows one instance of the inventory manager */
        std::vector<MenuItem> items; /**<The class allows one menu list per instance manager reference */

        //copy constructor
        InventoryManager(InventoryManager& other);
        //equals operator
        InventoryManager& operator= (InventoryManager other);

    protected:
        //Prevents instantiation of the of the inventory manager by making a protected class
        InventoryManager(); 


    public:
        //Retrieve an instance of the class
        static InventoryManager & instance();

        //This is a virtual method that is meant to be a destructor of an instance that is no longer required 
        virtual ~InventoryManager(); 

        //Get menu items method
        std::vector <MenuItem> getMenuItems();
        
        //Set menu items method
        void setMenuItems(std::vector <MenuItem> items);
        
       
        //Here are some additional methods to help maintain the data structure
        void printAllMenuItems();   
        void printMenuItem(std::string itemName);    
        int addMenuItem(MenuItem item);   
        int removeMenuItem(std::string itemName); 
        int removeMenuItem(MenuItem item);
        MenuItem * findMenuItem(std::string name);
};

#endif 
/*INVENTORYMANAGER_H_*/
