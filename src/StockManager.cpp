/**
 * @brief Stock Manager class. 
 * 
 * This class is used to manage the stock of the inventory, meaning the actually quantity of an item available in the store.
 * @author Kajal Patel
 * @date November 27, 2019
 */

#include <iostream>
#include<string>
#include <vector>
#include "StockManager.h"
#include "MenuItem.h"
#include "InventoryManager.h"
#include "OrderManager.h"

using namespace std;

/**
 * @brief instance of StockManger
 * 
 * This is the singleton instance of the stock manager
 */
StockManager * StockManager:: _instance=NULL; 

/**
* @brief Copy constructor overriden.
*
* Since this is a singleton class, the object cannot be copied. 
* @param other the other StockManager object that should be copied
* @return the new StockManager object created
*/
StockManager::StockManager(StockManager& other){
    ;
}

/**
* @brief The equals operator overriden. 
*
* Since this is a singleton class, the object cannot be copied. 
* @param other the other StockManager object that should be copied
* @return the new StockManager object created
*/
StockManager& StockManager:: operator= (StockManager other){
    ;
}

/**
* @brief The constructor. 
*
* Since this is a singleton class, the constructor cannot be called outside of the class. 
*/
StockManager::StockManager(){
    ;
}

/**
* @brief Retrieves instance of StockManager.
*
* Since this is a singleton class, the single instance of the object is returned everytime, or a new one is created if the object does not exist.
* @return the StockManager singleton instance
*/
StockManager &StockManager::instance()
{
    if (_instance == NULL){
        _instance = new StockManager();
    }
    return *_instance;
}

/**
* @brief The StockManager destructor.
*
* Overrides the default destructor. 
*/
StockManager:: ~StockManager(){
    ;
}

/**
* @brief Method to add additional stock.
*
* Increases the quantity of an item that is present in the inventory by a given amount.
* @param itemName the name of the inventory item
* @param increaseBy the quantity to increase the stock by
* @return return the new quantity of the stock available or return -1 with the update was unsuccessful and the inventory could not be added.
*/
int StockManager::addStock(string itemName, int increaseBy){
    MenuItem *item;
    item = InventoryManager::instance().findMenuItem(itemName);
    //check if the item exists in the inventory (is a valid item)
    if((item->getId()).compare("-1") ==0){
        cout <<"The item does not exist, therefore its stock level couldn't be increased."<<endl;
        delete item;
        return -1; //return -1 if the items stock couldnt be updated
    }else{
        //if its valid increase the stock
        int currInventory=item->getCurrentInventory();
        int newInventory = currInventory + increaseBy;
        item->setCurrentInventory(newInventory);
        //print out information regarding the updated inventory
        cout <<"Inventory for "<<itemName<<" updated:"<<endl;
        cout <<"Initial Inventory: "<<currInventory<<endl;
        cout <<"Increased By: "<<increaseBy<<endl;
        cout <<"New Inventory: "<<newInventory<<endl;
        return item->getCurrentInventory();
    }
}

/**
* @brief Method to remove stock.
*
* Decreases the quantity of an item that is present in the inventory by a given amount.
* @param itemName the name of the inventory item
* @param decreaseBy the quantity to decrease the stock by
* @return return the new quantity of the stock available or return -1 with the update was unsuccessful and the inventory could not be added.
*/
int StockManager::removeStock(string itemName, int decreaseBy){
    MenuItem *item;
    item = InventoryManager::instance().findMenuItem(itemName);
    //check if the itemName is valid
    if((item->getId()).compare("-1") ==0){
        cout <<"The item does not exist, therefore its stock level couldn't be decreased."<<endl;
        delete item;
        return -1; //return -1 if the items stock couldnt be updated
    }else{
        //update the inventory if the item is valid
        int currInventory=item->getCurrentInventory();
        int newInventory = currInventory - decreaseBy;
        //check if there is enough inventory to remove
        if(newInventory<0){
            //if there isnt enough inventory, print the information and return -1
            cout <<"Not enough inventory to perform action for: "<< itemName<<endl;
            cout <<"Initial Inventory: "<<currInventory<<endl;
            cout <<"Cannot Decrease By: "<<decreaseBy<<endl;
            return -1;
        }else{
            //if there is enough inventory, print the information and return the current quantity
            item->setCurrentInventory(newInventory);
            cout <<"Inventory for "<<itemName<<" updated:"<<endl;
            cout <<"Initial Inventory: "<<currInventory<<endl;
            cout <<"Decreased By: "<<decreaseBy<<endl;
            cout <<"New Inventory: "<<newInventory<<endl;
            if (newInventory<(item->getMinimumInventory())){
                cout << "WARNING: Inventory has fallen below the minimum threshold: "<<item->getMinimumInventory()<<endl;
            }
            return item->getCurrentInventory();
        }
    }
}

/**
* @brief Check if an item is in stock.
*
* Check if an item is available stock meaning that the quantity is greater than 0.
* @param itemName the name of the inventory item
* @return return true if the item is in stock, return false if it is not available or the item is invalid
*/
bool StockManager::isInStock(string itemName){
    MenuItem *item;
    item = InventoryManager::instance().findMenuItem(itemName);
    //check if the item name is valid
    if((item->getId()).compare("-1") ==0){
        cout <<"The item does not exist, therefore its not in stock."<<endl;
        delete item;
        return false; //return false if the item is not valid
    }else{
        //if the item is valid, check if it has quantity greater than 0
        int currInventory=item->getCurrentInventory();
        if(currInventory<=0){
            return false;
        }
        return true;
    }
}

/**
* @brief Check if an item is below its minimum threshold.
*
* Check if an item's quantity is below its minimum threshold to indicate if it should be re-ordered or not.
* @param itemName the name of the inventory item
* @return return true if the item is below threshold or doesn't exist, return false if it is above the threshold
*/
bool StockManager::isBelowThreshold(string itemName){
    MenuItem *item;
    item = InventoryManager::instance().findMenuItem(itemName);
    //check if the itemname is valid
    if((item->getId()).compare("-1") ==0){
        cout <<"The item does not exist, therefore its not in stock."<<endl;
        delete item;
        return true; //return -1 if the items stock couldnt be checked
    }else{
        //check if the quantity is greater than 0
        int currInventory=item->getCurrentInventory();
        if(currInventory<(item->getMinimumInventory())){
            return true;
        }else{
            return false;
        }
    }
}

/**
* @brief Get a list of items in stock.
*
* Go through all the items in the inventory and find the ones that are in stock.
* @return return a vector of items that are in stock
*/
vector<MenuItem> StockManager::getListOfItemsInStock(){
    vector<MenuItem> allItems = InventoryManager::instance().getMenuItems();
    vector<MenuItem> inStock;
    //iterate all the menu items
    for (unsigned int i = 0; i < allItems.size(); i++) {
        //verify if the item is in stock
        if(isInStock(allItems[i].getName())){
            //add it to the vector of instock items if it is in stock
            inStock.push_back(allItems[i]);
        }
    }
    return inStock;
}

/**
* @brief Get a list of items out of stock.
*
* Go through all the items in the inventory and find the ones that are out of stock.
* @return return a vector of items that are out of stock
*/
vector<MenuItem> StockManager::getListOfItemsOutOfStock(){
    vector<MenuItem> allItems = InventoryManager::instance().getMenuItems();
    vector<MenuItem> outOfStock;
    //iterate the menu items
    for (unsigned int i = 0; i < allItems.size(); i++) {
        //check if the item is not in stock
        if(!isInStock(allItems[i].getName())){
            //add it to the vector if it is out of stock
            outOfStock.push_back(allItems[i]);
        }
    }
    return outOfStock;
}

/**
* @brief Get a list of items below the minimum threshold.
*
* Go through all the items in the inventory and find the ones that are below the minimum threshold
* @return return a vector of items that are out of stock
*/
vector<MenuItem> StockManager::getListOfItemsBelowThreshold(){
    vector<MenuItem> allItems = InventoryManager::instance().getMenuItems();
    vector<MenuItem> belowThreshold;
    //iterate the menuitems
    for (unsigned int i = 0; i < allItems.size(); i++) {
        //check if the menu item is below the threshold
        if(isBelowThreshold(allItems[i].getName())){
            //add it to the below threshold vector
            belowThreshold.push_back(allItems[i]);
        }
    }
    return belowThreshold;
}

/**
* @brief Print in stock items.
*
* Go through all the items in the inventory and print out the ones in stock
*/
void StockManager::printItemsInStock(){
    cout <<"PRINTING IN STOCK ITEMS"<<endl;
    //get a list of items in stock
    vector<MenuItem> itemsInStock = getListOfItemsInStock();
    //print each one
    for (unsigned int i = 0; i < itemsInStock.size(); i++) {
        InventoryManager::instance().printMenuItem(itemsInStock[i].getName());
    }
}

/**
* @brief Print out of stock items.
*
* Go through all the items in the inventory and print out the ones out of stock
*/
void StockManager::printItemsOutOfStock(){
    cout <<"PRINTING OUT OF STOCK ITEMS"<<endl;
    //get a list of items out of stock
    vector<MenuItem> itemsOutOfStock = getListOfItemsOutOfStock();
    //print each one
    for (unsigned int i = 0; i < itemsOutOfStock.size(); i++) {
        InventoryManager::instance().printMenuItem(itemsOutOfStock[i].getName());
    }
}

/**
* @brief Print the items below threshold.
*
* Go through all the items in the inventory and print out the ones that are below the minimum threshold
*/
void StockManager::printItemsBelowThreshold(){
    cout <<"PRINTING ITEMS THATS ARE BELOW THRESHOLD"<<endl;
    //get a list of items below the minimum threshold
    vector<MenuItem> itemsBelowThresh = getListOfItemsBelowThreshold();
    //print each one
    for (unsigned int i = 0; i < itemsBelowThresh.size(); i++) {
        InventoryManager::instance().printMenuItem(itemsBelowThresh[i].getName());
    }

}