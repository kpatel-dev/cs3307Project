#ifndef COUPON_H_
#define COUPON_H_

#include <string>
/**
 * @brief Coupon class
 *
 * This class is used to create new Coupon objects
 * @date November 22nd
 * @author Kyra Hinnegan
 */
class Coupon{
	private:
		std::string couponCode; /**<Code attribute of coupon, allows the coupon to be identified in the system */
		double discount; /**<Discount amount attribute of the coupon */
        void setInvalidCoupon(); /**<Sets an invalid coupon object */
		
	public:
		
  		//Parameterized and unparameterized constructors and destructors
		Coupon();
        ~Coupon();
		Coupon(std::string couponCode, double discount);
		
  
  		//Getter method to retrieve the coupon code 
		std::string getCouponCode();
		
  		//Getter method to retrieve the discount
		double getDiscount();
};
#endif /*COUPON_H_ */
