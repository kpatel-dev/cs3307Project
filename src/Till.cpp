#include <string>
#include <iostream>
#include "Till.h"
#include "Price.h"

using namespace std;

/**
 * Set invalid item method
 * Sets an item that is invalid to remove all of its qualities
 * Also may be called to set the base stats of a new item so you have a base to assign qualities to
 */
void Till:: setInvalidItem(){
    this->id = "-1";
    this->cashBalance = 0;
}

/**
 * Menu item constructor
 */
Till::Till(){
    setInvalidItem();
}

/**
 * Till object parameterized constructor
 * This method is build to create till objects with 2 different attributes
 * Has failsafes such as that if it does not have an ID then it is unable to create an object
 * otherwise will assign all attributes to the object
 * @param string id of item
 * @param double cash balance of a till  
 */
Till::Till (string id, double cashBalance){
    if(id.compare("")==0){
        setInvalidItem();
        cout<<"The id entered was not valid. Please make sure it is not blank. Item not created."<<endl;
    }else if(cashBalance<0){
        setInvalidItem();
        cout<<"The cash balance entered was not valid. Item not created."<<endl;
    }
    else{
        this->id = id;
        this->cashBalance = cashBalance;
        
    }
}




/**
 * Till destructor 
 * Destroys the object after it is no longer useful  
 */
Till::~Till(){
    ;
}

/**
 * ID getter method 
 * @return string item id  
 */
string Till:: getId(){
    return this->id;
}

/**
 * Cash balance getter method 
 * @return double item cashBalance
 */
double Till:: getCashBalance(){
    return this->cashBalance;
}

 /**
 * Price setter method
 * Set Price, sets the type indicated to the new value held in the parameter field as long as the price is above 0 
 * @param double new price of item  
 */
void Till::setCashBalance(double balance){
    if(balance>=0){
        this->cashBalance=balance;
    }else{
        cout<<"Invalid balance. Please enter a positive balance value."<<endl;
    }
}
