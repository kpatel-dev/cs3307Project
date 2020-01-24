#ifndef ITEMLOAD_H_
#define ITEMLOAD_H_

#include "FileLoader.h"

/**
 * @brief Item Loader class 
 *
 * This is the item loader class, as its name might suggest it loads items.
 * The constructor reads in from the input filestream with the parameters being the fileName
 * then opens the file and reads in various pieces of information to help understand.
 * Next line by line in loop reads in from the file and adds it to the array where it can be used later
 * Then the array is used to send to addnewitem where it can be added
 * Finally all items read in are printed then the file is closed
 * @author Fahreen Bushra
 * @date November 27, 2019
 */
class ItemLoader : public FileLoader{
public:
    //Item Loader method for the bulk loading of all the items in a file
	ItemLoader(std :: string fileName);
private:
	void addNewItem(std:: string name, std:: string id, double price, int currentInventory, int minimumInventory, std:: string ingredients); /**<Method for the creation of new menu items to add to the set */
};
#endif
