
/**
 * @brief Order class. 
 * 
 * This class is used to hold a specific Order's information
 * @author Kajal Patel
 * @date November 27, 2019
 */
#include <string>
#include <iostream>
#include "Order.h"
#include "MenuItem.h"

using namespace std;

/**
* @brief The default constructor. 
*
*  Default constructor will create an invalid order with the id set to -1 
*/
Order::Order(){
    this->orderId = -1;
    MenuItem item;
    this->itemOrdered = item;
    this->orderRecieved= false;
    this->quantity=-1;
}

/**
* @brief The constructor for an order object. 
*
*  Create an order object with an order id, order quantity and the specific item to be ordered.
* @param item the MenuItem object to be ordered
* @param orderId the id of the order that it should be set to
* @param quantity the quantity to be ordered
*/
Order::Order(MenuItem item, int orderId, int quantity){
    this->orderId = orderId;
    this->itemOrdered = item;
    this->orderRecieved= false;
    this->quantity=quantity;
}

/**
* @brief The Order destructor.
*
* Overrides the default destructor. 
*/
Order::~Order(){
    ;
}

/**
* @brief Retrieves order id of the Order
*
* Get the order id of this Order object
* @return the order id
*/
int Order::getOrderId(){
    return this->orderId;
}

/**
* @brief Retrieves MenuItem of the Order
*
* Get the MenuItem object of the item that was ordered
* @return the MenuItem object
*/
MenuItem Order::getMenuItemOrdered(){
    return this->itemOrdered;
}

/**
* @brief Check if an order is received
*
* Check if this order has been marked as recieved
* @return Returns true if the order is marked as received, otherwise false
*/
bool Order::isOrderReceived(){
    return this->orderRecieved;
}

/**
* @brief Check the quantity of the item ordered
*
* Check the total quantity of the item that was ordered 
* @return Return the quantity of the order
*/
int Order::getQuantityOrdered(){
    return this->quantity;
}

/**
* @brief Mark an order as received.
*
* Mark an order as received. 
* @return Return 0 if the marking is successful, return -1 if it is not successful
*/
int Order:: markOrderReceived(){
    if(this->orderRecieved==true){
        cout<< "Error: The order was already recieved. Could not mark as received" <<endl;
        return -1; //return -1 if the order was already received
    }else{
        this->orderRecieved=true;
        return 0; //return 0 if the marking was successful
    }
}  

/**
* @brief Get the name of the MenuItem that was ordered
*
* Get the name of the item that was ordered
* @return the name of the item ordered as a string
*/
string Order::getMenuItemOrderedName(){
    return (this->itemOrdered).getName();
}

/**
* @brief Get the MenuItem id of the item that was ordered
*
* Get the id of the item that was ordered
* @return the id of the item ordered as a string
*/
string Order::getMenuItemOrderedId(){
    return (this->itemOrdered).getId();
}
