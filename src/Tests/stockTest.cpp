/*
 * 	Filename: mycp.cpp
 *  Created on: Oct. 3, 2019
 *  Author: kajalpatel
 *
 *  Description: Copies a file from the source to the destination which are provided as parameters from the command line.
 */

#include <iostream>
#include "FileLoader.h"
#include "InventoryManager.h"
#include "ItemLoader.h"
#include "MenuItem.h"
#include "Price.h"
#include "StaffManager.h"
#include "User.h"
#include "UserDataLoader.h"
#include "Order.h"
#include "OrderManager.h"
#include "StockManager.h"

#include <sstream> 

using namespace std;

MenuItem * findAMenuItem(string itemName){
    return InventoryManager::instance().findMenuItem(itemName);
}

int createOrder (string itemName, int quantitiy){
        return OrderManager::instance().createOrder(itemName, quantitiy);
}

void printAllOrders(){
        OrderManager::instance().printAllOrders();
}

int markOrderReceived(int orderId){
        return OrderManager::instance().markOrderReceived(orderId);
}

int cancelOrder(int orderId){
        return OrderManager::instance().cancelOrder(orderId);
}

Order *findOrder(int orderId){
        return OrderManager::instance().findOrderById(orderId);
}

void printAllItemsInStock(){
        StockManager::instance().printItemsInStock();
}

void printAllItemsOutOfStock(){
        StockManager::instance().printItemsOutOfStock();
}

void printAllItemsBelowThreshold(){
        StockManager::instance().printItemsBelowThreshold();
}

int decreaseStock(string itemName, int decreaseBy){
        return StockManager::instance().removeStock(itemName, decreaseBy);
}

int increaseStock(string itemName, int increaseBy){
        return StockManager::instance().addStock(itemName, increaseBy);
}

bool isInStock(string itemName){
        return StockManager::instance().isInStock(itemName);
}

bool isBelowThresh(string itemName){
        return StockManager::instance().isBelowThreshold(itemName);
}

/**
 * Call these functions to perform stock and order actions
 * */



int main(int argc, char *argv[]) {
        /*
        * Initialize the system before starting testing 
        */
        FileLoader f1("foodinventory.csv",'B');

        //Create a invalid order
        Order order;
        cout<<"Invalid Order"<<endl;
        cout<<order.getMenuItemOrderedName()<<endl;
        cout<<order.getMenuItemOrderedId()<<endl;
        cout<<order.getQuantityOrdered()<<endl;
        cout<<(order.isOrderReceived()?"true":"false")<<endl<<endl;
        order.markOrderReceived();
        cout<<(order.isOrderReceived()?"true":"false")<<endl<<endl;

        //find coffee in the inventory
        MenuItem *Coffee;
        Coffee = InventoryManager::instance().findMenuItem("Coffeee");
        if((Coffee->getId()).compare("-1") ==0){
                cout <<"the item does not exist, could not be ordered";
        }else{
        //order some coffee
                Order orderCoffee(*Coffee, 123, 12);
                cout<<"Coffee Order"<<endl;
                cout<<orderCoffee.getMenuItemOrderedName()<<endl;
                cout<<orderCoffee.getMenuItemOrderedId()<<endl;
                cout<<orderCoffee.getQuantityOrdered()<<endl;
                cout<<(orderCoffee.isOrderReceived()?"true":"false")<<endl<<endl;
                order.markOrderReceived();
                cout<<(orderCoffee.isOrderReceived()?"true":"false")<<endl<<endl;
                cout<<orderCoffee.getMenuItemOrdered().getName()<<endl;
        }

        cout<<endl<<endl;
        cout <<"ORDER MANAGER TESTING"<<endl;
        cout<<"OrderId: "<<(createOrder ("Coffee", 10))<<endl;
        cout<<"OrderId: "<<(createOrder ("Coffee", 15))<<endl;
        cout<<"OrderId: "<<(createOrder ("Tea", 7))<<endl;
        cout<<"OrderId: "<<(createOrder ("invalid", 10))<<endl;
        cout<<"OrderId: "<<(createOrder ("Brownie", 1))<<endl;

        Order *findOrderInfo = findOrder(2);
        cout <<findOrderInfo->getMenuItemOrderedName()<<endl;

       // printAllOrders();

        cout<<endl<<endl;
        markOrderReceived(2);
        printAllOrders();

        /*cancelOrder(0);
        printAllOrders();

        cancelOrder(0);

        printAllOrders();


        vector<Order> orders = OrderManager::instance().getOrdersPending();
         for (unsigned int i = 0; i < orders.size(); i++){
            cout <<orders[i].getMenuItemOrderedName()<<endl;
         }
*/

        cout <<endl<<endl;

        cout <<"STOCKMANAGER TESTING"<<endl;

        cout<<decreaseStock("Tea", 10)<<endl;
        cout<<endl;
        cout<<increaseStock("Tea", 10)<<endl;
        cout<<endl;

        cout<<decreaseStock("Tea", 450)<<endl;
        cout<<endl;

        cout<<decreaseStock("Tea", 450)<<endl;
        cout<<endl;




       printAllItemsInStock();
       printAllItemsBelowThreshold();
        cout<<decreaseStock("Tea", 57)<<endl;

       printAllItemsOutOfStock();
}



