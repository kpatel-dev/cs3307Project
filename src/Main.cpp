//
//  main.cpp
//  cafe
//
//  Created by Abigail Garces  on 10/29/19.
//  Copyright © 2019 Abigail Garces . All rights reserved.
//

#include <iostream>
#include <string>
//#include <stdlib.h>

#include "FileLoader.h"
#include "InventoryManager.h"
#include "ItemLoader.h"
#include "MenuItem.h"
#include "Price.h"
#include "StaffManager.h"
#include "User.h"
#include "UserDataLoader.h"
#include "PromoLoader.h"
#include "Coupon.h"
#include "CouponManager.h"
#include "Order.h"
#include "OrderManager.h"
#include "StockManager.h"
#include "Transaction.h"
#include "TransactionManager.h"

#include <sstream> 
using namespace std;

/**
 * Main class
 * 
 * This class is used to test the cafe manager methods and classes that we have implemented
 */

/** Setting all the functions up before use */

//transaction stuff
Transaction createTransaction(MenuItem menuItem);
void fulfillTransaction(int transactionID);
void printAllTransactions();

//inventory stuff
void updatePrice(string itemName, double price);
void printMenuItem(string itemName);
void printMenu();
void addNewItem(string name, string id, double price, int currentInventory, int minimumInventory, string ingredients);
void removeItem(string itemName);

//staff stuff
void printAllStaff();
void printManagers();
void printEmployees();
User addUser(string id, string fname, string lname, string type, string password);
void removeUser(std::string userId);

//coupon stuff
void printAllCoupons();
void printCoupon(std::string couponCode);
void addNewPromo(std::string code, double discount);
void removeCoupon(std::string couponCode);

//stock and order stuff
MenuItem * findAMenuItem(string itemName);
int createOrder (string itemName, int quantitiy);
void printAllOrders();
int markOrderReceived(int orderId);
int cancelOrder(int orderId);
Order *findOrder(int orderId);
void printAllItemsInStock();
void printAllItemsOutOfStock();
void printAllItemsBelowThreshold();
int decreaseStock(string itemName, int decreaseBy);
int increaseStock(string itemName, int increaseBy);
bool isInStock(string itemName);
bool isBelowThresh(string itemName);

//transaction stuff
int createTransaction(string itemName, int quantity);
void fulfillTransaction(int transactionID);
void printAllPendingTransactions();
void printAllFullfilledTransactions();
void printAllTransactions();
void printTotalProfit();
/*****************/
//INVENTORY ACTIONS
/*****************/

/**
 * Update price method
 * 
 * Creates a pointer to an instance after finding a menu item then sets the price on the item that you have just found
 * @param string item name
 * @param double price of item
 */
void updatePrice(string itemName, double price){
    MenuItem *item = InventoryManager::instance().findMenuItem(itemName);
   item->setPrice(price);
}

/**
 * Print menu item method 
 * Uses an instance of the class to print an menu item based on an item name
 * @param string item name
 */
void printMenuItem(string itemName){
    InventoryManager::instance().printMenuItem(itemName);
}

/**
 * Print menu item method 
 * Prints every single menu item
 */
void printMenu(){
    InventoryManager::instance().printAllMenuItems();
}

/**
 * Add new item method 
 * Creates new menu item object then uses this objects and adds it to the menu list
 * @param string name of item
 * @param string id of item
 * @param double price of item
 * @param int current inventory amount
 * @param int minimum inventory amount 
 * @param string ingredients in item
 */
void addNewItem(string name, string id, double price, int currentInventory, int minimumInventory, string ingredients){
    MenuItem item1(name,id,price,currentInventory,minimumInventory,ingredients);

    InventoryManager::instance().addMenuItem(item1);
}

/**
 * Remove item method 
 * Removes item by the name of the item as a parameter
 * @param string item name
 */
void removeItem(string itemName){
    InventoryManager::instance().removeMenuItem(itemName);
}


/*****************/
//STAFF ACTIONS
/*****************/

/**
 * Print all staff method 
 * Prints all staff by calling an instance of it
 */
void printAllStaff(){
    StaffManager::instance().printAllStaff();
}

/**
 * Print all managers method 
 * Prints all managers by calling an instance of it
 */ 
void printManagers(){
    StaffManager::instance().printAllManagers();
}

/**
 * Print all employees method 
 * Prints all employees by calling an instance of it
 */ 
void printEmployees(){
    StaffManager::instance().printAllEmployees();
}

/**
 * Add user method 
 * Creates an user object with the parameters taken in, then adds that object into the staff list
 * then returns the original user object
 * @param string user id
 * @param string user first name
 * @param string user last name
 * @param string type of user
 * @param string password of user
 * @return user object
 */
User addUser(string id, string fname, string lname, string type, string password){
    User user(id, fname, lname, type,password);
    StaffManager::instance().addStaff(user);
    return user;
}

/**
 * Remove user method 
 * Removes a user from the staff list using the user ID as a parameter
 * @param string user id
 */
void removeUser(std::string userId){
    StaffManager::instance().removeStaff(userId);
}

/*****************/
//COUPON ACTIONS
/*****************/

/**
 * Prints a coupon given its code
 * @param string couponCode
 * */
void printCoupon(string couponCode){
    CouponManager::instance().printCoupon(couponCode);
}

/**
 * Prints a list of all the coupons in the system
 * */
void printAllCoupons(){
    CouponManager::instance().printAllCoupons();
}

/**
 * Adds a new promo to the list of coupons in the system
 * @param string couponCode
 * @param double discount
 * */
void addNewPromo(std::string couponCode, double discount){
    Coupon couponadd(couponCode, discount);
    CouponManager::instance().addCoupon(couponadd);
}

/**
 * Removes a coupon from the system given its code
 * @param string couponCode
 * */
void removeCoupon(std::string couponCode){
    CouponManager::instance().removeCoupon(couponCode);
}
/**
 * STOCK AND ORDER ACTIONS
 * */
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
    bool inStock = StockManager::instance().isInStock(itemName);
    cout<<itemName<<" in stock: "<<(inStock? "True" : "False")<<endl;
    return inStock;
}

bool isBelowThresh(string itemName){
     bool belowThresh = StockManager::instance().isBelowThreshold(itemName);
     cout<<itemName<<" below thresh: "<<(belowThresh? "True" : "False")<<endl;
     return belowThresh;
}

/**
 TRANSACTION STUFF
 */
int createTransaction(string itemName, int quantity){
    return TransactionManager::instance().createTransaction(itemName,quantity);
}
void fulfillTransaction(int transactionID){
    TransactionManager::instance().fulfillTransaction(transactionID);
}

//print all pending transactions
void printAllPendingTransactions(){
    TransactionManager::instance().printAllPendingTransactions();
}

//print all completed transactions
void printAllFullfilledTransactions(){
    TransactionManager::instance().printAllCompletedTransactions();
}

//print all trasnactions
void printAllTransactions(){
    TransactionManager::instance().printAllTransactions();
}

//print total profit
void printTotalProfit(){
    TransactionManager::instance().printTotalProfit();
}

/**
 * Main Function used to contain actions 
 * This is the main function that is used to access many other functions and test their functuallity 
 * Has many different functions with restrictions on each to make sure that they work properly 
 */
int main() {
    /** sets up the start with setting up the input and then reading in a line of input */
    while (1){
    //char line[100];
    //char* word;
    //char* input[10];
    string line;
    cout<<endl<<endl;
    cout<<"---------------------------------------------"<<endl;
    cout << "Enter command: ";
    getline(cin, line);
    cout<<"---------------------------------------------"<<endl;
    string input[10];
    int i = 0;
    string word; 
    stringstream ss(line);
	/** Get line, gets a word as a new input and adds 1 to the counter */
    while (getline(ss, word ,' ')){
        input[i] = word;
        i++;
        //word = strtok(NULL, " ");
        //cout << word<< endl;
    }
    /** Checking for fails that wouldnt work with any inputs */
    if (sizeof(input)<1)
      cout << "ERROR: INVALID COMMAND more arguments needed";
    
    /** This is Update price, checks for the key word then the size of the arguement, if correct updates the price */
    else if(strncmp(input[0].c_str(),"updatePrice",12) == 0 ){
        /*if (input[2] == NULL){
            cout << "Invalid command, more arguments needed";
        }*/
        if (sizeof(input) < 2)
            cout << "ERROR: INVALID COMMAND more arguments needed";
        updatePrice(input[1].c_str(), stod(input[2]));
    }
    /** Print Menu Item, check for keyword then size of the argument, if correct prints a menu item */
    else if (strncmp(input[0].c_str(), "printMenuItem", 13) == 0){
        if (sizeof(input) < 2)
            cout << "ERROR: INVALID COMMAND more arguments needed";
        
        printMenuItem(input[1]);
    }

	/** Print Menu, check for keyword then prints the menu */
    else if (strncmp(input[0].c_str(),"printMenu", 9) ==0){
        printMenu();
    }
    
	/** Add New Item, check for keyword then size of the argument, if correct adds a new item to the item list */
    else if (strncmp(input[0].c_str(), "addNewItem", 10 )==0){
       if (sizeof(input) < 7)
            cout << "ERROR: INVALID COMMAND more arguments needed";
        
        //for (int j = ; j< 7; j++)
            //cout<< input [j] <<endl;
        
        addNewItem(input[1], input[2], stod(input[3]), stoi(input[4]), stoi(input[5]), input[6]);
    //addNewItem(input[1], input[2], atof((input[3])), atoi(input[4]), atoi(input[5]), input[6]);
    
    
    }
	/** Remove Item, check for keyword then size of the argument, if correct removes an item */
    else if (strncmp(input[0].c_str(),"removeItem",10) ==0){
       if (sizeof(input) < 2)
            cout << "ERROR: INVALID COMMAND more arguments needed";
        
        removeItem(input[1]);
    }
    
	/** Print All Staff, check for keyword then size of the argument, if correct prints all staff */
    else if (strncmp(input[0].c_str(), "printAllStaff",13) == 0){
        printAllStaff();
    }
	/** Print Managers, check for keyword then size of the argument, if correct prints managers */
    else if (strncmp(input[0].c_str(),"printManagers",13)==0){
        printManagers();
    }

	/** Print Employees, check for keyword then size of the argument, if correct prints employees */
    else if (strncmp(input[0].c_str(), "printEmployees",14) ==0){
        printEmployees();
    }
    
	/** Add user, check for keyword then size of the argument, if correct adds a new user with the rest of the arguements */
    else if (strncmp(input[0].c_str() ,"addUser", 8) ==0){
        
        if (sizeof(input) < 6)
            cout << "ERROR: INVALID COMMAND more arguments needed";
        
        
        addUser(input[1], input[2], input[3], input[4], input[5]);
        
    }
    
	/** Remove User, check for keyword then size of the argument, if correct removes a user with the paramater being the second arguement */
    else if (strncmp(input[0].c_str(),"removeUser", 10) ==0){
        
       if (sizeof(input)<2)
            cout << "ERROR: INVALID COMMAND more arguments needed";
        
        
        removeUser(input[1]);
    }
      
     /** Print coupon **/
    else if (strncmp(input[0].c_str(), "printCoupon", 11) == 0){
        if (sizeof(input) < 2)
            cout << "ERROR: INVALID COMMAND more arguments needed";
        
        printCoupon(input[1]);
    }
      
    /**Print list of all coupons */
    else if (strncmp(input[0].c_str(),"printAllCoupons", 15) ==0){
        printAllCoupons();
    }
      
    //Add new promo 
    else if (strncmp(input[0].c_str(), "addNewPromo", 11 )==0){
       if (sizeof(input) < 3)
            cout << "ERROR: INVALID COMMAND more arguments needed";
        
        addNewPromo(input[1], stod(input[2]));
    
    }
    
     //Remove coupon
    else if (strncmp(input[0].c_str(),"removeCoupon",12) ==0){
       if (sizeof(input) < 2)
            cout << "ERROR: INVALID COMMAND more arguments needed";
        
        removeCoupon(input[1]);
    }
    //Create Order
    else if (strncmp(input[0].c_str(),"createOrder",12) ==0){
       if (sizeof(input) < 3)
            cout << "ERROR: INVALID COMMAND more arguments needed";
        
        createOrder(input[1], stoi(input[2]));
    }

    //Order Received
    else if (strncmp(input[0].c_str(),"receiveOrder",12) ==0){
       if (sizeof(input) < 2)
            cout << "ERROR: INVALID COMMAND more arguments needed";
        
        markOrderReceived(stoi(input[1]));
    }

    //Cancel Order
    else if (strncmp(input[0].c_str(),"cancelOrder",12) ==0){
       if (sizeof(input) < 2)
            cout << "ERROR: INVALID COMMAND more arguments needed";
        
        cancelOrder(stoi(input[1]));
    }

    //print Orders
    else if (strncmp(input[0].c_str(),"printOrders",12) ==0){
       if (sizeof(input) < 1)
            cout << "ERROR: INVALID COMMAND more arguments needed";
        
        printAllOrders();
    }
    
    //print in stock items
    else if (strncmp(input[0].c_str(),"inStock",12) ==0){
       if (sizeof(input) < 1)
            cout << "ERROR: INVALID COMMAND more arguments needed";
        
        printAllItemsInStock();
    }

    //print out of stock items
    else if (strncmp(input[0].c_str(),"outOfStock",12) ==0){
       if (sizeof(input) < 1)
            cout << "ERROR: INVALID COMMAND more arguments needed";
        
        printAllItemsOutOfStock();
    }

    //print below threshhold items
    else if (strncmp(input[0].c_str(),"belowThresh",12) ==0){
       if (sizeof(input) < 1)
            cout << "ERROR: INVALID COMMAND more arguments needed";
        
        printAllItemsBelowThreshold();
    }

    //check if in stock
    else if (strncmp(input[0].c_str(),"itemInStock",12) ==0){
       if (sizeof(input) < 2)
            cout << "ERROR: INVALID COMMAND more arguments needed";
        
        isInStock(input[1]);
    }

    //check if below threhold
    else if (strncmp(input[0].c_str(),"itemThresh",12) ==0){
       if (sizeof(input) < 2)
            cout << "ERROR: INVALID COMMAND more arguments needed";
        
        isBelowThresh(input[1]);
    }

    //increase stock for an item
    else if (strncmp(input[0].c_str(),"incStock",12) ==0){
       if (sizeof(input) < 3)
            cout << "ERROR: INVALID COMMAND more arguments needed";
        
        increaseStock(input[1], stoi(input[2]));
    }

    //decrease stock for an item
    else if (strncmp(input[0].c_str(),"decStock",12) ==0){
       if (sizeof(input) < 3)
            cout << "ERROR: INVALID COMMAND more arguments needed";
        
        decreaseStock(input[1],stoi(input[2]));
    }
        
    //create transaction
    else if (strncmp(input[0].c_str(),"createTransaction",17) ==0){
        if (sizeof(input) < 3)
            cout << "ERROR: INVALID COMMAND more arguments needed";
        
        createTransaction(input[1],stoi(input[2]));
    }
    
    else if (strncmp(input[0].c_str(),"fulfillTransaction",18) ==0){
        if (sizeof(input) < 2)
            cout << "ERROR: INVALID COMMAND more arguments needed";
        
        fulfillTransaction(stoi(input[1]));
    }
    
    else if (strncmp(input[0].c_str(),"pendingTransactions",20) ==0){
        if (sizeof(input) < 1)
            cout << "ERROR: INVALID COMMAND more arguments needed";
        printAllPendingTransactions();
    }
    else if (strncmp(input[0].c_str(),"completedTransactions",20) ==0){
        if (sizeof(input) < 1)
            cout << "ERROR: INVALID COMMAND more arguments needed";
        printAllFullfilledTransactions();
    }
    else if (strncmp(input[0].c_str(),"allTransactions",20) ==0){
        if (sizeof(input) < 1)
            cout << "ERROR: INVALID COMMAND more arguments needed";
        
        printAllTransactions();
    }
    else if (strncmp(input[0].c_str(),"totalProfit",20) ==0){
        if (sizeof(input) < 1)
            cout << "ERROR: INVALID COMMAND more arguments needed";
        printTotalProfit();
    }
   
/**
 * Initialize, check for keyword then size of the argument
 * depending on the next arguement either loads the food inventory or the employee list
 */
	else if (strncmp(input[0].c_str(), "Initialize",10) == 0){
        if (sizeof(input) < 2)
            cout << "ERROR: INVALID COMMAND more arguments needed";
        else if (strncmp(input[1].c_str(), "inventory", 9) == 0)
            FileLoader f1("foodinventory.csv",'B');
        else if (strncmp(input[1].c_str(), "staff", 9) == 0)
            FileLoader f1("employees.csv",'A');
      	else if (strncmp(input[1].c_str(), "promos", 6) == 0)
            FileLoader f1("promos.csv", 'C');
    }
    /** this means that they have entered the exit keyword and would like to exit main */
    else if (strncmp((input[0].c_str()) ,"exit", 5) ==0)
        exit(1);
        
	/** This means it has not matched any of the keywords and therefore is no applicable */
    else
        cout << "ERROR: INVALID COMMAND\n";
    
    }
  /** returns 0 at the very very very very end */
    return 0;
}
