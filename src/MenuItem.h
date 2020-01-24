/**
 * @brief MenuItem Class
 *
 * sets information needed for an item on te menu
 *
 * @author Kajal Patel
 * @date October 31, 2019
 *
 **/

#ifndef MENUITEM_H_
#define MENUITEM_H_

#include <string>
#include "Price.h"

/** Sets the definitions of the functions in terms of arguement length and type */
class MenuItem{
    private:
        std::string name; /**<name of the menuitem*/
        std::string id;/**<id of the menuitem*/
        double currentPrice;/**<current price of menuitem of type double */
        Price price;/**<price of menuitem of type Price*/
        int currentInventory;/**<number for the current inventory of the menuitem*/
        int minimumInventory;/**<minimum number of inventory for the item*/
        std::string ingredients;/**<ingredients of the menuitem */
        
        /**Private method to set the menuitem to invalid*/
        void setInvalidItem();

    public:
        /** constructor to initilize what a menu item is composed of */
        MenuItem();
        MenuItem (std::string name, std::string id, double price, int currentInventory, int minimumInventory, std::string ingredients);
        MenuItem (std::string name, std::string id, Price price, int currentInventory, int minimumInventory, std::string ingredients);
	    
        /** destructor method */
	    ~MenuItem();
        
        /** get info methods */
        std::string getName();
        std::string getId();
        double getCurrentPrice();
        double getSalePrice();
        bool getOnSale();
        double getCurrentInventory();
        double getMinimumInventory();
        std::string getIngredients();

        /** set attribute methods */
        void setName(std::string name);
        void setPrice(double price);
        void setCurrentInventory(int inventory);
        void setMinimumInventory(int minimumInventory);
        void setIngredients(std::string ingredients);

        /** sale functions */
        void putItemOnSale();
        void putItemOnSale(double price);
        void takeItemOffSale();
};

#endif /* MENUITEM_H_ */
