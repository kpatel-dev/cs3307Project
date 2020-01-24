
/**
 *@brief MenuItem class
 *
 *sets information needed for an item on the menu
 *
 *@author Kajal Patel
 *@date October 31, 2019
 */


#include <string>
#include <iostream>
#include "MenuItem.h"
#include "Price.h"

using namespace std;

/**
 * @brief Set invalid item method
 * Sets an item that is invalid to remove all of its qualities
 * Also may be called to set the base stats of a new item so you have a base to assign qualities to
 */
void MenuItem:: setInvalidItem(){
    this->name = "";
    this->id = "-1";
    this->price = Price();
    this->currentPrice = 0;
    this->currentInventory=0;
    this->minimumInventory=0;
    this->ingredients="";
}

/**
 * @brief Menu item constructor
 */
MenuItem::MenuItem(){
    setInvalidItem();
}

/**
 * @brief Menu item parameterized constructor
 * This method is build to create menu item objects with 6 different attributes
 * The price is turned from a double into a price object that is then used for the Menu item object
 * Has failsafes such as that if it does not have a name then it is unable to create an object
 * otherwise will assign all attributes to the object
 * @param string name of item
 * @param string id of item
 * @param double price of item
 * @param int current inventory amount
 * @param int minimum inventory amount 
 * @param string ingredients in item  
 */
MenuItem::MenuItem (string name, string id, double price, int currentInventory, int minimumInventory, string ingredients){
    Price priceObj(price); 
    if(name.compare("")==0){
        setInvalidItem();
        cout<<"The name entered was not valid. Please make sure it is not blank. Item not created."<<endl;
    }else if(id.compare("")==0){
        setInvalidItem();
        cout<<"The id entered was not valid. Please make sure it is not blank. Item not created."<<endl;
    }else if(priceObj.getPrice()<0){
        setInvalidItem();
        cout<<"The price initialized was not valid. Item not created."<<endl;
    }
    else{
        this->name=name;
        this->id = id;
        this->price = priceObj;
        this->currentPrice = price;
        this->currentInventory=currentInventory;
        this->minimumInventory=minimumInventory;
        this->ingredients=ingredients;
    }
}


/**
 * @brief Menu item parameterized constructor with Price
 * This method is build to create menu item objects with 6 different attributes
 * Has failsafes such as that if it does not have a name then it is unable to create an object
 * otherwise will assign all attributes to the object
 * In the assignment check for sales before setting the price of the object
 * @param string name of item
 * @param string id of item
 * @param Price object of item
 * @param int current inventory amount
 * @param int minimum inventory amount 
 * @param string ingredients in item  
 */
MenuItem::MenuItem (string name, string id, Price price, int currentInventory, int minimumInventory, string ingredients){
    if(name.compare("")==0){
        setInvalidItem();
        cout<<"The name entered was not valid. Please make sure it is not blank. Item not created."<<endl;
    }else if(id.compare("")==0){
        setInvalidItem();
        cout<<"The id entered was not valid. Please make sure it is not blank. Item not created."<<endl;
    }else if(price.getPrice()<0){
        setInvalidItem();
        cout<<"The price initialized was not valid. Item not created."<<endl;
    }
    else{
        this->name=name;
        this->id = id;
        this->price = price;
        this->currentPrice = price.getIsOnSale()? price.getSalePrice(): price.getPrice();
        this->currentInventory=currentInventory;
        this->minimumInventory=minimumInventory;
        this->ingredients=ingredients;
    }
}

/**
 * @brief Menu item destructor
 * Destroys the object after it is no longer useful  
 */
MenuItem::~MenuItem(){
    ;
}

/**
 * @brief ID getter method
 * @return string item id  
 */
string MenuItem:: getId(){
    return this->id;
}

/**
 * @brief Name getter method
 * @return string item name  
 */
string MenuItem:: getName(){
    return this->name;
}

/**
 * @brief Price getter method
 * @return double item price 
 */
double MenuItem:: getCurrentPrice(){
    return this->currentPrice;
}

/**
 * @brief Sale price getter method
 * @return double item sale price  
 */
double MenuItem:: getSalePrice(){
    return this->price.getSalePrice();
}

/**
 * @brief On sale getter method
 * @return bool value indicating if item is on sale  
 */
bool MenuItem::getOnSale(){
    return this->price.getIsOnSale();
}

/**
 * @brief Current inventory getter method
 * @return double inventory of item  
 */
double MenuItem::getCurrentInventory(){
    return this->currentInventory;
}

/**
 * @brief Minimum inventory getter method
 * @return double minimum inventory of item  
 */
double MenuItem::getMinimumInventory(){
    return this->minimumInventory;
}

/**
 * @brief Ingredients getter method
 * @return string ingredients of item  
 */
string MenuItem::getIngredients(){
    return this->ingredients;
}

/**
 * @brief Name setter method
 * @param string new name of item  
 */
void MenuItem::setName(string name){
    this->name = name;
}



/**
 *@brief Price setter method
 *set Price, sets the type indicated to the new value held in the parameter field as long as the price is above 0
 *@param double new price of item
 */
void MenuItem::setPrice(double price){
    if(price>0){
        this->currentPrice=price;
        this->price.setPrice(price);
    }else{
        cout<<"Invalid price. Please enter a positive price value."<<endl;
    }
}



/**
 * @brief inventory setter method
 * @param int inventory amount of item
 */
void MenuItem::setCurrentInventory(int inventory){
    this->currentInventory=inventory;
}

/**
 * @brief Minimum inventory setter method
 * @param int minimum inventory amount of item  
 */
void MenuItem::setMinimumInventory(int minimumInventory){
    this->minimumInventory=minimumInventory;
}

/**
 * @brief Ingredients setter method
 * @param string ingredients of item  
 */
void MenuItem::setIngredients(string ingredients){
    this->ingredients=ingredients;
}

/**
 * @brief Method to put item on sale
 * Sets given item's sale attribute to "true"
 */
void MenuItem::putItemOnSale(){
    this->currentPrice=price.getSalePrice();
    this->price.setIsOnSale(true);
}

/**
 * @brief Set item on sale with price method
 * Set the price on sale, sets the type indicated to the new value held in the parameter field but does not change if it is on sale 
 * @param double sale price of item  
 */
void MenuItem::putItemOnSale(double price){
    this->price.setSalePrice(price);
    this->putItemOnSale();
}




/**
 * @brief takes the menu off sale method
 * sets the item to no longer be on sale, sets the instance as not on sale
 */
void MenuItem::takeItemOffSale(){
    this->currentPrice = price.getPrice();
    this->price.setIsOnSale(false);
}
