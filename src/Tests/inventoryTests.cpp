/*
 * 	Filename: mycp.cpp
 *  Created on: Oct. 3, 2019
 *  Author: kajalpatel
 *
 *  Description: Copies a file from the source to the destination which are provided as parameters from the command line.
 */

#include <iostream>
#include "Price.h"
#include "MenuItem.h"
#include "InventoryManager.h"

using namespace std;

/**
 * Call these functions to perform specific inventory actions
 * */
void updatePrice(string itemName, double price){
	MenuItem *item = InventoryManager::instance().findMenuItem(itemName);
   item->setPrice(price);
}

void printMenuItem(string itemName){
	InventoryManager::instance().printMenuItem(itemName);
}

void printMenu(){
	InventoryManager::instance().printAllMenuItems();
}

void addNewItem(string name, string id, double price, int currentInventory, int minimumInventory, string ingredients){
	MenuItem item1(name,id,price,currentInventory,minimumInventory,ingredients);

	InventoryManager::instance().addMenuItem(item1);
}

void removeItem(string itemName){
	InventoryManager::instance().removeMenuItem(itemName);
}

int main(int argc, char *argv[]) {

//create a new item
addNewItem("item1","123",2.00,12,1,"egg,cheese");


//print newly created item
printMenuItem("item1");

//update the price of the item
updatePrice("item1", 12.00);
printMenuItem("item1");

//try to remove the same item twice
removeItem("item1");
removeItem("item1");
printMenuItem("item1");

//create a few items and print out the whole list
addNewItem("item1","123",2.00,12,1,"egg,cheese");
addNewItem("item123","122223",2.00,12,1,"egg,cheese");
addNewItem("item3","122223",2.00,12,1,"egg,cheese");
printMenu();

//update the price to an invalid value
updatePrice("item1", -12.00);


//remove the price
removeItem("item1");
printMenu();


}
