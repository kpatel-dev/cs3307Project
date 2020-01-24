
/**
 * @brief Order Manager class. 
 * 
 * This class is used to manage the Orders made to a supplier to re-stock the inventory.
 * @author Kajal Patel
 * @date November 27, 2019
 */
#include <iostream>
#include<string>
#include "OrderManager.h"
#include "InventoryManager.h"
#include "StockManager.h"


using namespace std;

/**
 * @brief instance of OrderManager
 * 
 * This is the singleton instance of the order manager
 */
OrderManager * OrderManager:: _instance=NULL; 

/**
* @brief Copy constructor overriden.
*
* Since this is a singleton class, the object cannot be copied. 
* @param other the other OrderManager object that should be copied
* @return the new OrderManager object created
*/
OrderManager::OrderManager(OrderManager& other){
    ;
}

/**
* @brief The equals operator overriden. 
*
* Since this is a singleton class, the object cannot be copied. 
* @param other the other OrderManager object that should be copied
* @return the new OrderManager object created
*/
OrderManager& OrderManager:: operator= (OrderManager other){
    ;
}

/**
* @brief Print a list of orders
*
* Take a list of order and print their details 
* @param orderList a vector containing the list of orders to be printed
*/
void OrderManager:: printOrderList(vector<Order> orderList){
    for (unsigned int i = 0; i < orderList.size(); i++){
        printOrder(orderList[i]);
    }
}

/**
* @brief Print details of a specific item
*
* Take an Order object and print its details
* @param order the order object thats details should be printed
*/
void OrderManager::printOrder(Order order){
    cout<<"Item Name: "<<order.getMenuItemOrderedName()<<endl;
    cout<<"Item Id: "<<order.getMenuItemOrderedId()<<endl;
    cout<<"Order Id: "<<order.getOrderId()<<endl;
    cout<<"Quantity Ordered: "<<order.getQuantityOrdered()<<endl;
    cout<<"Order Received: "<<(order.isOrderReceived()?"True":"False")<<endl<<endl;
}

/**
* @brief The constructor. 
*
* Since this is a singleton class, the constructor cannot be called outside of the class. 
*/
OrderManager::OrderManager(){
    ;
}

/**
* @brief Retrieves instance of OrderManager.
*
* Since this is a singleton class, the single instance of the object is returned everytime, or a new one is created if the object does not exist.
* @return the OrderManager singleton instance
*/
OrderManager &OrderManager::instance()
{
    if (_instance == NULL){
        _instance = new OrderManager();
        _instance->totalOrders = 0;
    }
    return *_instance;
}

/**
* @brief The OrderManager destructor.
*
* Overrides the default destructor. 
*/
OrderManager:: ~OrderManager(){
    ;
}

/**
* @brief Retrieves list of pending orders.
*
* Retrieve the vector list of all the orders that are still pending
*/
vector<Order> OrderManager:: getOrdersPending(){
    return this->ordersPending;
}

/**
* @brief Retrieves list of received orders.
*
* Retrieve the vector list of all the orders that are received
*/
vector<Order> OrderManager:: getOrdersReceived(){
    return this->ordersReceived;
}

/**
* @brief Retrieves list of cancelled orders.
*
* Retrieve the vector list of all the orders that are cancelled
*/
vector<Order> OrderManager::getOrdersCancelled(){
    return this->orderCancelled;
}

/**
* @brief Method to create an order
*
* Creates new order for an item that is in the inventory for a set quantity
* @param itemName the name of the inventory item
* @param quantity the quantity to order
* @return return the order id of the order or return -1 if the order creation was not successful
*/
int OrderManager::createOrder(string itemName, int quantity){
    MenuItem *item;
    item = InventoryManager::instance().findMenuItem(itemName);
    if((item->getId()).compare("-1") ==0){
        cout <<"The item does not exist, therefore could not be ordered"<<endl;
        delete item;
        return -1; //return -1 if the item could not be successfully ordered
    }else if (quantity<1){
        cout <<"Invalid order quantity, the quantity should be greater than 0"<<endl;
        return -1;
    }
    else{
        //order the item
        Order order(*item, totalOrders++, quantity);
        this->allOrders.push_back(order); //add the item to all order
        this->ordersPending.push_back(order); //add the item to pending orders
        return order.getOrderId();

    }
}

/**
* @brief Method to cancel an order
*
* Cancel an order that was previously created
* @param orderId the orderId of the item thats to be cancelled
* @return return the order id of the order or return -1 if the order cancellation was not successful
*/
int OrderManager::cancelOrder(int orderId){
    Order *order;
    order = findOrderById(orderId);
    if((order->getOrderId())==-1){
        cout <<"The order does not exist, therefore could not be cancelled."<<endl;
        delete order;
        return -1; //return -1 if the item could not be successfully cancelled
    }else{
        //cancel the order
        for (unsigned int i = 0; i < (this->ordersPending).size(); i++){
            if(orderId==ordersPending[i].getOrderId()){
                this->ordersPending.erase(ordersPending.begin()+i); //remove the order from the pending list
                this->orderCancelled.push_back(*order); //add the item to pending orders
                return order->getOrderId();
            }
        }
        //if the order was not found in pending list, then it is either already received or cancelled
        cout <<"The order was already cancelled or received. Could not cancel the order."<<endl;
        return -1; //return -1 if the item could not be successfully cancelled
    }
}

/**
* @brief Method to mark an order as received
*
* Mark an order received that was previously created
* @param orderId the orderId of the item thats to be marked as received
* @return return the order id of the order or return -1 if the order marking was not successful
*/
int OrderManager::markOrderReceived(int orderId){
    Order *order = findOrderById(orderId);
    if((order->getOrderId())==-1){
        cout <<"The order does not exist, therefore could not be marked as received"<<endl;
        delete order;
        return -1; //return -1 if the item could not be successfully cancelled
    }else{
        //cancel the order
        for (unsigned int i = 0; i < (this->ordersPending).size(); i++){
            if(orderId==ordersPending[i].getOrderId()){
                this->ordersPending.erase(ordersPending.begin()+i); //remove the order from the pending list
                order->markOrderReceived();
                this->ordersReceived.push_back(*order); //add the item to received orders
                //update stockmanager after receiving an order
                StockManager::instance().addStock(order->getMenuItemOrderedName(), order->getQuantityOrdered());
                return order->getOrderId();
            }
        }
        //if the order was not found in pending list, then it is either already received or cancelled
        cout <<"The order was already cancelled or received. Could not mark the order as received."<<endl;
        return -1; //return -1 if the item could not be successfully cancelled
    }
}

/**
* @brief Method to find a specific order
*
* Finds and returns an order object based on the order id
* @param orderId the orderId of the order thats to be found
* @return return the order object on success or an invalid order object (with id -1) if unsuccessful
*/
Order * OrderManager::findOrderById(int orderId){
    //look for the order id and return the object if found
    for (unsigned int i = 0; i < (this->allOrders).size(); i++){
        if(orderId==allOrders[i].getOrderId()){
            return &allOrders[i];
        }
    }
    cout <<"The order with the id: " << orderId <<" does not exits in the system"<<endl;
    return new Order();//return an invalid order object
}

/**
* @brief Print pending orders.
*
* Go through all the orders pending and print out them out
*/
void OrderManager::printAllOrdersPending(){
    cout<<"ORDERS PENDING:"<<endl<<endl;
    printOrderList(this->ordersPending);
    cout<<endl<<endl;
}

/**
* @brief Print received orders.
*
* Go through all the orders received and print out them out
*/
void OrderManager::printAllOrdersReceived(){
    cout<<"ORDERS RECEIVED:"<<endl<<endl;
    printOrderList(this->ordersReceived);
    cout<<endl<<endl;
}

/**
* @brief Print cancelled orders.
*
* Go through all the orders cancelled and print out them out
*/
void OrderManager::printAllOrdersCancelled(){
    cout<<"ORDERS CANCELLED:"<<endl<<endl;
    printOrderList(this->orderCancelled);
    cout<<endl<<endl;
}

/**
* @brief Print all the order
*
* Go through all the orders and print them out
*/
void OrderManager::printAllOrders(){
    printAllOrdersPending();
    printAllOrdersReceived();
    printAllOrdersCancelled();
}