
/**
 *@brief Price Class
 *
 * sets all the types for all the variable types for the prices
 *
 * @author Kajal Patel
 * @date October 31, 2019
 */

#include "Price.h"

/**
 * @brief Price constructor
 * 
 * Constructs the base state of sales  
 */
Price::Price (){
    this->price=-1;
    this->salePrice = -1;
    this->onSale=false;
}

/**
 * @brief Price constructor
 * 
 * Sets the price of an object including the sale price then set it to not be on sale
 * @param double price to set  
 */
Price::Price (double price){
    this->price=price;
    this->salePrice = price;
    this->onSale=false;
}

/**
 * @brief Price constructor
 * 
 * Sets the price of an object as well as a price for sales and set it to not be on sale
 * @param double price to set 
 * @param double sale price to set 
 */
Price::Price (double price, double salePrice){
    this->price=price;
    this->salePrice = salePrice;
    this->onSale=false;
}

/**
 * @brief Price destructor
 * 
 * For removing the price object 
 */
Price::~Price(){
    ;
}

/**
 * @brief Price getter method
 * @return double price of object  
 */
double Price:: getPrice(){
    return this->price;
}

/**
 * @brief Sale price getter method
 * @return double sale price of object  
 */
double Price::getSalePrice(){
    return this->salePrice;
}

/**
 * @brief On sale getter method
 * @return bool value of whether item is on sale or not 
 */
bool Price:: getIsOnSale(){
    return this->onSale;
}

/**
 * @brief Price setter method
 * @param double item price to set   
 */
void Price::setPrice(double price){
    this->price=price;
}

/**
 * @brief Sale price setter method
 * @param double item sale price to set   
 */
void Price::setSalePrice(double salePrice){
    this->salePrice=price;
}

/**
 * @brief On sale setter method 
 * @param bool onSale to set as true for specified item   
 */
void Price:: setIsOnSale(bool onSale){
    this->onSale = onSale;
}
