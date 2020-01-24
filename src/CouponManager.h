#ifndef COUPONMANAGER_H_
#define COUPONMANAGER_H_
#include <vector>
#include <map>
#include <string>
#include <fstream>
#include "Coupon.h"

/**
 * @brief Coupon Manager class
 * 
 * This class is used to manage the list of coupons in the system
 * @author Kyra Hinnegan
 * @date November 22, 2019
 */
class CouponManager{
    private:
        static CouponManager *_instance; /**<Allows an instance of CouponManager to be created */
        std::vector<Coupon> listOfCoupons; /**<List of the current Coupon objects in the system */
  	    CouponManager(CouponManager& other); 
        CouponManager& operator = (CouponManager other);
    
    protected:
        //Protected constructor
        CouponManager();
    
    public:
        //Instance creators/constructors
        static CouponManager & instance();
        virtual ~CouponManager();
        //Returns the list of all coupons in the system
        std::vector<Coupon> getCoupons();
        //Sets a new list of coupons
        void setCoupons(std::vector<Coupon> coupons);
        //Adds a given coupon to the system
        void addCoupon(Coupon coupon);
        //Removes a coupon from the system, given its code
        void removeCoupon(std::string couponCode);
        //Removes a coupon from the system
        void removeCoupon(Coupon coupon);
        //Print a list of all the coupons in the system
        void printAllCoupons();
        //Prints a coupon given its code
        void printCoupon(std::string couponCode);
        //Finds and returns a coupon object from the list given its code
        Coupon * findCoupon(std::string couponCode);


};
#endif /*COUPONMANAGER_H_ */
