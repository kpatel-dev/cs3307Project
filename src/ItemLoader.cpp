#include "ItemLoader.h"
#include "InventoryManager.h"
#include "MenuItem.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream> 
#include <stdlib.h>

/**
  * @brief Item loader class
  * 
  * This is the item loader class, as its name might suggest it loads items.
  * The constructor reads in from the input filestream with the parameters being the fileName
  * then opens the file and reads in various pieces of information to help understand.
  * next line by line in loop reads in from the file and adds it to the array where it can be used later
  * Then the array is used to send to addnewitem where it can be added
  * finally all items read in are printed then the file is closed
  * @author Fahreen Bushra
  * @date November 27, 2019
  */

/**
  * @brief Item loader constructor
  * 
  * Reads in a file to load it's items as described above
  * @param string file name 
  */
ItemLoader::ItemLoader(std:: string fileName){
	std :: ifstream myfile;
	myfile.open(fileName);
	std:: string line;
	std :: string token;
	std:: string arr[6];
	char delim = ',';
	
	while (getline(myfile, line)){
		std:: stringstream ss(line);
		int i = 0;
		while(std:: getline(ss, token ,delim)){
			arr[i] = token;
			i++;}
	addNewItem(arr[0], arr[1], atof(arr[2].c_str()), atoi(arr[3].c_str()), atoi(arr[4].c_str()), arr[5]);
	
	}
	InventoryManager::instance().printAllMenuItems();
	myfile.close();

};

/**
  * @brief Add new item method
  * 
  * Method for the addition of individual items to the set
  * This is where the information of the array is sent, where it will be used to create a new menu item
  * @param string item name
  * @param double item id
  * @param int current inventory amount
  * @param int minimum inventory amount
  * @param string ingredients
  */
void ItemLoader:: addNewItem(std:: string name, std:: string id, double price, int currentInventory, int minimumInventory, std:: string ingredients){
	MenuItem item1(name,id,price,currentInventory,minimumInventory,ingredients);
	InventoryManager::instance().addMenuItem(item1);
	//InventoryManager::instance().printAllMenuItems();
};

