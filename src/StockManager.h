/**
 * @brief Stock Manager class. 
 * 
 * This class is used to manage the stock of the inventory, meaning the actually quantity of an item available in the store.
 * @author Kajal Patel
 * @date November 27, 2019
 */

#ifndef STOCKMANAGER_H_
#define STOCKMANAGER_H_

#include <string>
#include <vector>
#include "MenuItem.h"
#include "InventoryManager.h"
#include "OrderManager.h"

class StockManager{
    private:
        static StockManager *_instance; /**<The class only allows one instance of the inventory manager */

        //copy constructor
        StockManager(StockManager& other);
        //equals operator
        StockManager& operator= (StockManager other);

    protected:
        //constructor
        StockManager(); // Prevents instantiation of the of the inventory manager by making a protected class 

    public:
	    //retrieve an instance of the class
        static StockManager& instance();
        
        //destructor
        virtual ~StockManager();
        
        //add/remove stock methods
        int addStock(std::string itemName, int increaseBy); 
        int removeStock(std::string itemName, int decreaseBy);

        //checking methods for items are in stock or not
        bool isInStock(std::string itemName);
        bool isBelowThreshold(std::string itemName);

        //retrieves vectors of items
        std::vector<MenuItem> getListOfItemsInStock();
        std::vector<MenuItem> getListOfItemsOutOfStock();
        std::vector<MenuItem> getListOfItemsBelowThreshold();

        //printing methods
        void printItemsInStock();
        void printItemsOutOfStock();
        void printItemsBelowThreshold();
};

#endif /* STOCKMANAGER_H_ */
