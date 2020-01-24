
/**
 *
 * @brief Transaction Manager Class
 *
 * This class manages all the transactions created and fulfilled
 *  @author Abigail Garces, Kajal Patel
 *  @date November 22, 2019
 *
 */

#ifndef TransactionManager_hpp
#define TransactionManager_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <fstream>
#include "MenuItem.h"
#include "InventoryManager.h"
#include "StockManager.h"
#include "Transaction.h"

class TransactionManager{
    private:
    
        int totalTransactions;/**<int to keep track of the number of transactions*/
        double totalProfit;/**<int to keep traack of the total profit*/
  		std::vector<Transaction> pendingTransactions;/**<vector to keep track of pending transactions*/
        std::vector<Transaction> completedTransactions;/**vector to keep track of completed transactions*/
  		std::vector<Transaction> allTransactions;/**<vector to keep track of all the transactions, created and completed*/
    
        /**
         *<Singleton design pattern.  restricts instantiation of TransactionManager to one object
         */
        static TransactionManager *_instance;
  		
  		/**
        * Singleton design pattern.  Restricts instantiation of TransactionManager to one object
        * @param TransactionManager& other
        */
        TransactionManager(TransactionManager& other);
  
  		/**
        * Singleton design pattern.  Restricts instantiation of TransactionManager to one object
        *  @param TransactionManager other
        */
        TransactionManager& operator= (TransactionManager other);
        
    
    protected:
        
  		/**
        * 
        */
  		TransactionManager();

    public:
    
  		/**
        * Instance method to get a singleton TransacionManager object
        */
        static TransactionManager & instance();
  
  		/**
        * Deconstructor method for TransactionManager object that is no longer needed
        */
        virtual ~TransactionManager();

        /**
        * Getter method to get a vector of all the pending transactions.
        * the transactions that have been created but not fulfilled
        */
  		std::vector<Transaction> getPendingTransactions();
  
  		/**
        * Getter method to get a vector of all the completed transactions
        * The transactions that have been created AND fulfilled 
        */
        std::vector<Transaction> getCompletedTransactions(); 
        
  		/**
        * Getter method to get the total profit
        */
  		double getTotalProfit(); 
	
  		/**
        * Method to create a transation
        * @param string itemName name of the menu item customer wants to order
        * @param int quantity number of items the customer wants to order 
        */
  		int createTransaction(std::string itemName, int quantity); //f1
        
  		/**
        * Method to complete a transaction that has been created
        * @param int transactionID 
        */
  		int fulfillTransaction(int transactionID); //f2
        
  		/**
        * Method to print all the pending transactions.
        * Transactions that have only been created
        */
        void printAllPendingTransactions(); //f3
  
  		/**
        * Method to print all the completed transactions
        * Transactions that have been created AND fulfilled
        */
        void printAllCompletedTransactions(); //f4
  
  		/**
        * Method to print all the transactions
        * transactions that have been created and/or completed
        */
  		void printAllTransactions();

  		/**
        * Method to print the total profit made
        */
        void printTotalProfit(); //f5

        
    
};

#endif /** TransactionManager_hpp */
