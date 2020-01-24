/**
 *@brief Price class
 *
 *sets all the types for all the variable types for the prices
 *
 *@author Kajal Patel
 *@date october 31, 2019
 */

#ifndef PRICE_H_
#define PRICE_H_

/** sets all the types for all the variable types */
class Price{
    private:
        double price;/**<original price of the item*/
        double salePrice;/**<sale price of the item if it is on sald*/
        bool onSale;/**<boolean to check if the item is on sale*/

    public:
        /** Construct the objects */
        Price ();
        Price (double price);
        Price (double price, double salePrice);

        /** Destroy the object */
        ~Price();

        /** Return the attributes */
        double getPrice();
        double getSalePrice();
        bool getIsOnSale();

        /** Set the attributes */
        void setPrice(double price);
        void setSalePrice(double salePrice);
        void setIsOnSale(bool onSale);
};

#endif /** PRICE_H_ */
