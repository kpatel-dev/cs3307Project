
/**
 *@brief Transaction class
 *
 * this class has the information needed for one transaction
 *
 * @author Abigail Garces, Kajal Patel
 * @date November 22, 2019
 */
#ifndef Transaction_hpp
#define Transaction_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include "Order.h"
#include "MenuItem.h"

class Transaction{
    private:
        MenuItem menuItem;/**< menuitem that the customer is ordering*/
        int transactionID;/**<the id of the transactions*/
        int quantity;/**<the amount of menuitems the customer wants to order*/
        double price;/**<the price of the transaction*/
        double revenue;/**<the total profit made from the transaction*/
        bool fulfilled;/**<boolean to check if the transaction is complete*/
    
    public:

        /**
        * Constructors to initialize a transaction
        */
        Transaction();
        Transaction(MenuItem menuItem, int id, int quantity);
        Transaction(MenuItem menuItem, int id, int quantity, double price, double revenue);
        
        /**
        * Deconstructor
        */
        ~Transaction();
        
        /**
        * Getter methods for members of a transactions
        */
        MenuItem getCustomerOrderItem();
        std::string getCustomerOrderItemName();
        int getTransactionId();
        int getTransactionQuantity();
        double getTransactionRevenue();
        double getTransactionItemPrice();
        
        /**
        * functions needed to process a transaction
        */
        bool isFulfilled();
        void markComplete();

        /**
        *print transaction function
        */
        void printTransaction();
    
    
};

#endif /* Transaction_hpp */
