
/**
 *
 * @brief Transaction Manager Class
 *
 * This class manages all the transactions created and fulfilled
 *  @author Abigail Garces, Kajal Patel
 *  @date November 22, 2019
 *
 */

#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include "TransactionManager.h"
#include "Transaction.h"
#include "StockManager.h"

using namespace std;

/**
 * @brief Instance of Transaction manager
 *
 * This is the singleton instance of the stock manager .  restricts instantiation of TransactionManager to one object
 */
TransactionManager * TransactionManager:: _instance = NULL;


/**
 * @brief copy constructor overridden
 *
 * object cannot be copied since this is a singleton design pattern
 * @param other A TransactionManager object that should be copied
 * @return TransactionManager, the new object created
 */
TransactionManager::TransactionManager(TransactionManager& other){
    ;
}


/**
 * @brief copy constructor overridden
 *
 * object cannot be copied since it is a singleton design pattern
 * @param other a TransactionManager object that should be copied
 * @return TransactionManager, the new object created
 */
TransactionManager& TransactionManager:: operator = (TransactionManager other){
    ;
}


/**
 * @brief the constructor
 *
 * since this is a singleton class, the constructor cannot be called outside of the class
 */
TransactionManager::TransactionManager(){
    this->totalTransactions=0;
    this->totalProfit=0;
}


/**
 *@brief Gets an instance of a TransactionManager
 *
 *Since this is a singleton design pattern class, the single instance of TransactionManager object is returned everytime
 *or a new one if there is no current one
 *@return the TransactionManager singleton instance
*/
TransactionManager& TransactionManager::instance(){
    if (_instance == NULL){
        _instance = new TransactionManager();

    }
    return *_instance;
}


/**
 * @brief TransactionManager deconstructor
 *
 * deconstructor method for a TransactionManager object that is no longer needed
 */
TransactionManager:: ~TransactionManager(){
    this->pendingTransactions.clear();
    this->completedTransactions.clear();
    this->allTransactions.clear();
}


/**
 * @brief getter method to get a vector of all the pending transactions
 *
 * gets a set of all the pending transactions that have been created but not fulfilled yet
 * @return vector<Transaction> a vector ofpending transactions of type  type Transactions
 */
vector<Transaction> TransactionManager::  getPendingTransactions(){
    return this->pendingTransactions;
}

/**
 * @brief getter method to get a vector of all the completed transactions
 *
 * gets a set of all the completed transactions that have been created and fulfilled
 * @return vector<Transaction> a vector of completed transactions of type transaction
 */
vector<Transaction> TransactionManager:: getCompletedTransactions(){
    return this->completedTransactions;
}

/**
 * @brief getter method to get the total profit
 *
 * gets the total profit made from all of the transactions
 * @return the total profit of type double
 */
double TransactionManager:: getTotalProfit(){
    return this->totalProfit;
}



/**
 * @brief method to create a transaction
 *
 * creates a transactions with the customers order item and quantity of it by calling the Transaction constructor
 * @param string the item name that the customer wants to order
 * @param int the quantity of the item the customer wants to order
 * @return int  the transaction id if it was successful, otherwise -1
 */
int TransactionManager::createTransaction(std::string itemName, int quantity){
    MenuItem *item;
    item = InventoryManager::instance().findMenuItem(itemName);
    if((item->getId()).compare("-1") ==0){
        cout <<"The item does not exist, therefore transaction could not be created"<<endl;
        delete item;
        return -1; //invalid transaction (-1)
    }else {
        if (StockManager::instance().removeStock(itemName, quantity)!=-1){ //reduce the stock , check if it was successful
            Transaction  transaction(*item, (this->totalTransactions)++, quantity);
            this->pendingTransactions.push_back(transaction); //add the item to pending transactions
            this->allTransactions.push_back(transaction); //add the item to all transactions
            cout<<endl<<endl<<"TRANSACTION CREATED "<<endl<<endl;
            transaction.printTransaction();
            cout<<endl<<"Total revenue updated "<<endl<<endl;
            //increment the total profit
            totalProfit=totalProfit+transaction.getTransactionRevenue();
            printTotalProfit();
            return transaction.getTransactionId();   //return the transaction id when successful   
        }
        else{
            cout <<"Transaction not created."<<endl;
            return -1; //invalid transaction (-1)
        }
        
    }
}



/**
 * @brief method to fulfill a transaction
 *
 * fulfills atransaction that has been created
 * @param int transaction id, takes a transaction id from a created transaction
 * @return int the transaction id that has been created and fulfilled, otherwise -1
 */
int TransactionManager::fulfillTransaction(int transactionID){
    if(transactionID>=this->totalTransactions || transactionID<0){
        cout <<"Transaction with transaction id: "<<transactionID<<" was not fullfilled. It does not exist."<<endl;
        return -1;
    }
    for (unsigned int i = 0; i < (this->allTransactions).size(); i++){
            if(transactionID==allTransactions[i].getTransactionId()){
                if(!allTransactions[i].isFulfilled()){
                    this->completedTransactions.push_back(allTransactions[i]); //add the item to fulfilled trasnactions
                    
                    //remove the transaction from the pending list
                    for (unsigned int i = 0; i < (this->allTransactions).size(); i++){
                        if(transactionID==pendingTransactions[i].getTransactionId()){
                            this->pendingTransactions.erase(pendingTransactions.begin()+i); 
                        }
                    }

                    cout<<"The following transaction was completed "<<endl<<endl;
                    allTransactions[i].printTransaction();
                    allTransactions[i].markComplete();
                    return allTransactions[i].getTransactionId();//on success, return the trasnaction id;
                }
            }
    }
    //if the trasnaction was not found in pending list, then it is either already fulfilled or never placed
    cout <<"Transaction with transaction id: "<<transactionID<<" was not fullfilled. It may have been already fulfilled."<<endl;
    return -1; //return -1 if the item could not be successfully fullfilled
}


/**
 *@brief method to print all pending transactions
 *
 *prints only the transactions that have been created
 */
void TransactionManager::printAllPendingTransactions(){
    cout<<endl<<"PENDING TRANSACTIONS:"<<endl<<endl;
    for(unsigned int i = 0; i<pendingTransactions.size(); i++){
        pendingTransactions[i].printTransaction();
    }
}



/**
 *@brief method to print all completed transactions
 *
 *prints transactions that have been created AND FULFILLED
 */
void TransactionManager::printAllCompletedTransactions(){
    cout<<endl<<"FULFILLED TRANSACTIONS:"<<endl<<endl;
    for(unsigned int i = 0; i<completedTransactions.size(); i++){
        completedTransactions[i].printTransaction();
    }
}



/**
 *@brief method to print all the transactions
 *
 *prints all transactions that have been crerated and/or fulfilled
 */
void TransactionManager::printAllTransactions(){
    cout<<"ALL TRANSACTIONS "<<endl<<endl;
    printAllPendingTransactions();
    printAllCompletedTransactions();
}


/**
 *@brief method to print the total profit
 *
 *the amount of money made
 */
void TransactionManager::printTotalProfit(){
    cout<<"Total Profit: "<<this->totalProfit<<setprecision(2)<<endl;
}



