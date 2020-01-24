#include "PromoLoader.h"
#include "CouponManager.h"
#include "Coupon.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream> 
#include <stdlib.h>


/**
  * @brief Promo loader class
  * 
  * The constructor reads in from the input filestream with the parameters being the fileName
  * then opens the file and reads in various pieces of information to help understand.
  * next line by line in loop reads in from the file and adds it to the array where it can be used later
  * Then the array is used to send to addnewpromo where it can be added
  * finally all items read in are printed then the file is closed
  * @author Kyra Hinnegan
  * @date November 22, 2019
  */

/**
  * @brief Promo loader constructor
  * 
  * Reads in a file to load it's items as described above
  * @param string file name 
  */
PromoLoader::PromoLoader(std:: string fileName){
	std :: ifstream myfile;
	myfile.open(fileName);
	std:: string line;
	std :: string token;
	std:: string arr[2];
	char delim = ',';
	
	while (getline(myfile, line)){
		std:: stringstream ss(line);
		int i = 0;
		while(std:: getline(ss, token ,delim)){
			arr[i] = token;
			i++;}
	addNewPromo(arr[0], atof(arr[1].c_str()));
	
	}
	CouponManager::instance().printAllCoupons();
	myfile.close();

};

/**
  * @brief Add new promo method
  * 
  * Method for the addition of individual promos to the set
  * This is where the information of the array is sent, where it will be used to create a new promo
  * @param string promo code
  * @param double discount amount
  */
void PromoLoader:: addNewPromo(std::string code, double discount){
  Coupon newCoup(code, discount);
	CouponManager::instance().addCoupon(newCoup);
};
