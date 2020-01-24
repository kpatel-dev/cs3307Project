#ifndef PROMOLOADER_H_
#define PROMOLOADER_H_

#include "FileLoader.h"

/**
 * @brief Promo Loader class
 *
 * The constructor reads in from the input filestream with the parameters being the fileName
 * then opens the file and reads in various pieces of information to help understand.
 * Next line by line in loop reads in from the file and adds it to the array where it can be used later
 * Then the array is used to send to addnewpromo where it can be added
 * Finally all items read in are printed then the file is closed
 * @author Kyra Hinnegan
 * @date November 22, 2019
 */
class PromoLoader : public FileLoader{
public:
   //Promo Loader method For the bulk loading of all the items in a file
	PromoLoader(std :: string fileName);
private:
	void addNewPromo(std::string coupon_code, double discount); /**<Add new promo method for the creation of a new promo to be added to the list */
};
#endif
 
