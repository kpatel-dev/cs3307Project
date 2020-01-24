#include <iostream>
#include <iomanip>
#include "SalesManager.h"
/**
 * Sales manager class
 * 
 * This class allows you to access the inventory of menu items that are on sale and print them
 */

using namespace std;  
private:
 /**
   * Print detailed list of menu items that are on sale method
   * For each item given to it, goes and searches through the list until it finds the first matching name
   * then prints out all attributes in relation to that item 
   * @param string inventory item name
   */
void SalesManager::printMenuItem(string itemName){
    cout<<endl;
    for (unsigned int i = 0; i < items.size(); i++) {
        if(itemName.compare(items[i].getName()) ==0){
            cout<<"Name: "<<items[i].getName()<<endl;
            cout<<"Current Price: "<<fixed<<setprecision(2)<<items[i].getCurrentPrice()<<endl;
            cout<<"Sale Price: "<<items[i].getSalePrice()<<setprecision(2)<<endl;
            cout<<"On Sale: "<<(items[i].getOnSale()? "true":"false")<<endl;
            cout<<"Current Inventory: "<<setprecision(0)<<items[i].getCurrentInventory()<<endl;
            cout<<"Minimum Inventory: "<<items[i].getMinimumInventory()<<endl;
            cout<<"Ingredients: "<<items[i].getIngredients()<<endl;
            return;
        }
    }
    cout<<"no item called " + itemName + " found in the sale item inventory"<<endl; //! if it can not find the item then just prints it cant find it

}
public:
 /**
  * Sales manager instance
  * Starts a instance as NULL allowing it to be start getting written to
  */ 
SalesManager * SalesManager:: _instance=NULL; 


 /**
   * Sales manager constructor
   * Prevents copying or sharing but reducing these to nothing and not adding any info or an instance to be able to work with it
   * @param SalesManager& other
   */
SalesManager::SalesManager(SalesManager& other){
    ;
}

 /**
   * Sales manager constructor
   * Prevents copying or sharing but reducing these to nothing and not adding any info or an instance to be able to work with it
   * @param SalesManager other 
   */
SalesManager& SalesManager:: operator= (SalesManager other){
    ;
}
 /**
   * Sales manager protected constructor
   * This is a singleton implementation (protected constructor) used to clear an instance of the SalesManager, removes all inside
   */
SalesManager::SalesManager(){
    this->items.clear();
}

 /**
   * Sales manager constructor
   * If the Sales manager doesnt exist then it creates a new instance of the Sales manager
   * then returns such instance in the form of a pointer
   * @return a pointer to the instance
   */
SalesManager& SalesManager::instance()
{
    if (_instance == NULL)
        _instance = new SalesManager();
    return *_instance;
}

 /**
   * Sales manager destructor
   * When the Sales manager is no longer required this destructs the instance and clears the items 
   */
SalesManager:: ~SalesManager(){
    this->items.clear();
}

 /**
   * Inventory getter method
   * This returns the set of items which are in the current inventory
   * @return vector set of items
   */
vector <MenuItem> SalesManager:: getSaleItems(){
	this->items.clear();
	std::vector<MenuItem> allItems = InventoryManager::instance().getMenuItems();
	for (unsigned int i = 0; i < allItems.size(); i++) 
        if(allItems[i].getOnSale())
           items.push_back(allItems[i]);
    return this->items;
}
        
 /**
   * Print menu items method
   * Takes the full list of all menu items and for that size loops through sending each line to the other print 
   * menu item where it does a job of printing off all information about the one object given to it 
   */
void SalesManager::printAllSaleItems(){
    cout<<endl<<"All menu items that are on sale:"<<endl<<endl;
	getSaleItems();
    for (unsigned int i = 0; i < items.size(); i++) {
        printMenuItem(items[i].getName());
    }
}  

 /**
   * Print detailed list of menu items that are on sale method
   * For each item given to it, goes and searches through the list until it finds the first matching name
   * then prints out all attributes in relation to that item 
   * @param string inventory item name
   */
void SalesManager::printSaleItem(string itemName){
	getSaleItems();
	printMenuItem(itemName);
}


 /**
   * Find menu item method
   * This method tries to locate an item by matching the name from the list of menu items, if the name does not exist
   * in the list then it comments saying that the item was not found
   * @param string item name to find
   * @return MenuItem object found from list of menu items 
   */
MenuItem * SalesManager::findSaleItem(string name){
    for (unsigned int i = 0; i < items.size(); i++) {
        if(name.compare(items[i].getName()) ==0){
            return &items[i];
        }
    }
    cout<<"the item with the name "+ name<<" does not exists in the sales list."<<endl;
}

