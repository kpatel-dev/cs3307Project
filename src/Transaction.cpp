/**
 *@brief Transaction class
 *
 *this class has the information needed for one transaction
 *
 *@author Abigail Garces, Kajal Patel
 *@date November 22, 2019
 */

#include <string>
#include <iostream>
#include <iomanip>

#include "Transaction.h"


using namespace std;



/**
 *@brief Transaction constructor
 *this method created a transaction object with the attributes given in the parameters
 *@param MenuItem menuitem that customer is ordering
 *@param int id of the transaction
 *@param int quantity of menuitems customer is ordering
 */
Transaction::Transaction(MenuItem menuItem, int id, int quantity){
    
    this->menuItem = menuItem;
    this->transactionID=id;
    this->price=menuItem.getCurrentPrice();
    this->revenue=(menuItem.getCurrentPrice())*quantity;
    this->quantity=quantity;
    this->fulfilled=false;
}



/**
 *@brief Transaction deconstructor
 *
 *destroys the transaction that is not needed
 */
Transaction::~Transaction(){
    MenuItem item; //create an invalid item
    this->menuItem = item;
    this->transactionID=-1;
    this->revenue=0;
    this->price=0;
    this->quantity=0;
    this->fulfilled=false;
}



/**
 *@brief getter method to get customer order item
 *
 *gets the Menuitem that the customer ordered
 *@return MenuItem object of the item customer ordered
 */
MenuItem Transaction::getCustomerOrderItem(){
    return this->menuItem;
}



/**
 *@brief getter method to get the name of the item the customer ordered
 *
 *gets the name of the item customer ordered
 *@return a string of the name of the menuitem the customer ordered
 */
string Transaction::getCustomerOrderItemName(){
    return (this->menuItem).getName();
}



/**
 *@brief getter method to get the transaction id
 *
 *gets the id of the transaction
 *@return int id of the transaction
 */
int Transaction::getTransactionId(){
    return this->transactionID;
}



/**
 @brief getter method to get quanaitity of items
 *
 *gets the quantity of menuitems the customer ordered
 *@return int the quantity of items the customer ordered
 */
int Transaction::getTransactionQuantity(){
    return this->quantity;
}



/**
 *@brief getter method to get the revenue of the transaction
 *
 *gets the total revenue of the transaction
 *@return double type of the transactions revenue
 */
double Transaction::getTransactionRevenue(){
    return this->revenue;
}



/**
 *@brief getter method to get the transactions item price
 *
 *gets the price of the transaction
 *@return double type of the price of the transaction
 */
double Transaction::getTransactionItemPrice(){
    return this->price;
}

/**
* boolean method to check if the transaction is fulfilled
* @return boolean true if the transaction is fulfilled, false if it has not been fulfilled 
*/
/**
 *@brief boolean to check if the transaction is complete
 *
 *checks if the transaction has been fulfilled
 *@return boolean true if transaction is complete, otherwise false
 */
bool Transaction::isFulfilled(){
    return this->fulfilled;
}


/**
 *@brief method to mark the transaction as complete
 *
 *marks the transaction complete
 */
void Transaction::markComplete(){
    this->fulfilled=true;
}



/**
 *@brief method to print the information of the transaction
 *
 *prints the transaction like a receipt
 */
void Transaction::printTransaction(){
    cout<<"Transaction Id: "<<this->getTransactionId()<<endl;
    cout<<"Transaction Completed: "<<(this->fulfilled?"True":"False")<<endl;
    cout<<"Item Ordered: "<<this->getCustomerOrderItemName()<<endl;
    cout<<"Quantity Ordered: "<<this->getTransactionQuantity()<<endl;
    cout<<"Item Price: "<<this->getTransactionItemPrice()<<setprecision(2)<<endl;
    cout<<"Transaction Revenue: "<<this->getTransactionRevenue()<<setprecision(2)<<endl<<endl;
    
}
