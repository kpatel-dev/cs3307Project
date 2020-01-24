#include <iostream>
#include <iomanip>
#include "InventoryManager.h"
/**
 * @brief Inventory Manager class
 * 
 * This class allows you to create instances of a inventory and has several 
 * funtions to be able to manipulate the data, such as getters, setters and deletes 
 * @author Kajal Patel
 * @date November 27, 2019
 */

using namespace std;  

 /**
  * @brief Inventory Manager instance
  *
  * Singleton instance of the inventory manager
  */ 
InventoryManager * InventoryManager:: _instance=NULL; 


  /**
   * @brief Inventory Manager constructor overridden
   *
   * Prevents copying or sharing but reducing these to nothing and not adding any info or an instance to be able to work with it
   * @param other the other InventoryManager object that should be copied
   * @return the new InventoryManager object created
   */
InventoryManager::InventoryManager(InventoryManager& other){
    ;
}

  /**
   * @brief The equals operator overridden
   *
   * Prevents copying or sharing but reducing these to nothing and not adding any info or an instance to be able to work with it
   * @param other the other InventoryManager object that should be copied
   * @return the new InventoryManager object created
   */
InventoryManager& InventoryManager:: operator= (InventoryManager other){
    ;
}
  /**
   * @brief Inventory Manager protected constructor
   *
   * This is a singleton implementation (protected constructor) used to clear an instance of the inventorymanager, removes all inside
   */
InventoryManager::InventoryManager(){
    this->items.clear();
}

  /**
   * @brief Retrieves instance of InventoryManager
   *
   * If the inventory manager doesnt exist then it creates a new instance of the inventory manager
   * then returns such instance in the form of a pointer
   * @return InventoryManager singleton instance
   */
InventoryManager& InventoryManager::instance()
{
    if (_instance == NULL)
        _instance = new InventoryManager();
    return *_instance;
}

  /**
   * @brief Inventory Manager destructor
   *
   * When the inventory manager is no longer required this destructs the instance and clears the items 
   */
InventoryManager:: ~InventoryManager(){
    this->items.clear();
}

  /**
   * @brief Inventory getter method
   *
   * This returns the set of items which are in the current inventory
   * @return vector set of items
   */
vector <MenuItem> InventoryManager:: getMenuItems(){
    return this->items;
}

  /**
   * @brief Inventory setter method
   *
   * This clears the old inventory then sets the current inventory by adding new items passed in by parameter, 
   * one new at a time is added in a loop 
   * @param vector of new inventory items
   */
void InventoryManager::setMenuItems(vector <MenuItem> items){
    this->items.clear();
	for (unsigned int i = 0; i < items.size(); i++) {
        addMenuItem(items[i]);
    }
}
        
  /**
   * @brief Print menu items method
   *
   * Takes the full list of all menu items and for that size loops through sending each line to the other print 
   * menu item where it does a job of printing off all information about the one object given to it 
   */
void InventoryManager::printAllMenuItems(){
    cout<<endl<<"All menu items listed:"<<endl<<endl;
    for (unsigned int i = 0; i < items.size(); i++) {
        printMenuItem(items[i].getName());
    }
}  

  /**
   * @brief Print detailed list of menu items method
   *
   * For each item given to it, goes and searches through the list until it finds the first matching name
   * then prints out all attributes in relation to that item 
   * @param string inventory item name
   */
void InventoryManager::printMenuItem(string itemName){
    cout<<endl;
    for (unsigned int i = 0; i < items.size(); i++) {
        if(itemName.compare(items[i].getName()) ==0){
            cout<<"Name: "<<items[i].getName()<<endl;
            cout<<"Item Id: "<<items[i].getId()<<endl;
            cout<<"Current Price: "<<fixed<<setprecision(2)<<items[i].getCurrentPrice()<<endl;
            cout<<"Sale Price: "<<items[i].getSalePrice()<<setprecision(2)<<endl;
            cout<<"On Sale: "<<(items[i].getOnSale()? "true":"false")<<endl;
            cout<<"Current Inventory: "<<setprecision(0)<<items[i].getCurrentInventory()<<endl;
            cout<<"Minimum Inventory: "<<items[i].getMinimumInventory()<<endl;
            cout<<"Ingredients: "<<items[i].getIngredients()<<endl;
            return;
        }
    }
    cout<<"no item called " + itemName + " found"<<endl; //! if it can not find the item then jsut prints it cant find it

}


  /**
   * @brief Add new menu item method
   *
   * Tries to add an item to the list of all menu items, if the name already exists in the list then it 
   * comments saying you should remove the old one before adding a new item with the matching name, it 
   * also rejects items that do not have a valid id
   * @param MenuItem object to be added to inventory
   */
int InventoryManager::addMenuItem(MenuItem item){
    for (unsigned int i = 0; i < items.size(); i++) {
        if(item.getName().compare(items[i].getName()) ==0){
            cout<<"the item with the name "+ item.getName()<<" already exists. Please delete it first."<<endl;
            return -1; //return -1 if the addition was not successful
        }
    }

    if(item.getId().compare("-1")==0)
    {
            cout<<"the item was not valid and was not added to the system"<<endl;
            return -1; //return -1 if the addition was not successful

    }else{
        items.push_back(item);
        cout<<"the item with the name "+ item.getName()<<" was added to the system."<<endl;
        return 0; //return 0 if the addition was successful

    }
}


  /**
   * @brief Remove menu item (by name) method
   *
   * This method tries to remove an item by matching the name from the list of menu items, if the name does not exist
   * in the list then it comments saying that the item was not found
   * @param string name of item to remove
   */
int InventoryManager::removeMenuItem(std::string itemName){
    for (unsigned int i = 0; i < items.size(); i++) {
        if(itemName.compare(items[i].getName()) ==0){
            items.erase(items.begin()+i);
            return 0; //return 0 if the removal was successful
        }
    }
    cout<<"The item with the name "+ itemName<<" does not exists in the system. Could not remove it."<<endl;
    return -1; //return 1 if the remove was not successful
}

 /**
   * @brief Remove menu item (by item) method
   *
   * This method tries to remove an item by extracting its name then calling the remove by name method 
   * @param MenuItem object to remove
   */
int InventoryManager::removeMenuItem(MenuItem item){
    return removeMenuItem(item.getName());
}

  /**
   * @brief Find menu item method
   *
   * This method tries to locate an item by matching the name from the list of menu items, if the name does not exist
   * in the list then it comments saying that the item was not found
   * @param string item name to find
   * @return MenuItem object found from list of menu items 
   */
MenuItem * InventoryManager::findMenuItem(string name){
    for (unsigned int i = 0; i < items.size(); i++) {
        if(name.compare(items[i].getName()) ==0){
            return &items[i];
        }
    }
    cout<<"the item with the name "+ name<<" does not exists in the system."<<endl;
    //create an invalid menuitem and return it
    return new MenuItem();
}

