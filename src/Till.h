#ifndef TILL_H_
#define TILL_H_

#include <string>


/** Sets the definitions of the functions in terms of arguement length and type */
class Till{
    private:
        std::string name; 
        std::string id;
        double cashBalance;

    public:
        /** constructor to initilize what a menu item is composed of */
        Till();
		Till(string id, double cashBalance);
	    
        /** destructor method */
	    ~Till();
        
        /** get info methods */
        std::string getId();
        double getCashBalance();

        /** set attribute methods */
        void setCashBalance(double cashBalance);

};

#endif /* TILL_H_ */
