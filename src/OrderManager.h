/**
 * @brief Order Manager class. 
 * 
 * This class is used to manage the Orders made to a supplier to re-stock the inventory.
 * @author Kajal Patel
 * @date November 27, 2019
 */
#ifndef ORDERMANAGER_H_
#define ORDERMANAGER_H_

#include <string>
#include <vector>
#include "Order.h"

class OrderManager{
    private:
        int totalOrders;/**<Keeps track of the total orders made in order to create order ID's*/
        static OrderManager *_instance; /**< The class only allows one instance of the order manager */
        std::vector<Order> allOrders; /**< keeps track of all orders*/
        std::vector<Order> ordersPending; /**< keeps tack of order made and pending */
        std::vector<Order> ordersReceived; /**< keeps tack of orders made and received */
        std::vector<Order> orderCancelled;  /**< keeps tack of orders made and cancelled */

        //copy constructor
        OrderManager(OrderManager& other);
        //equals operator
        OrderManager& operator= (OrderManager other);

        //helper methods to create print statements
        void printOrderList(std::vector<Order> orderList); //helper method to print orderlists
        void printOrder(Order order); //helper method to print an order

    protected:
        //constructor
        OrderManager(); 

    public:
	    //retrieve an instance of the class
        static OrderManager& instance();

        //destructor
        virtual ~OrderManager();

        //get info methods 
        std::vector<Order> getOrdersPending();
        std::vector<Order> getOrdersReceived();
        std::vector<Order> getOrdersCancelled();

        //methods to manage orders
        int createOrder(std::string itemName, int quantity); 
        int cancelOrder(int orderId);
        int markOrderReceived(int orderId);

        //helper method to find an order by id
        Order * findOrderById(int orderId); 

        //printing methods
        void printAllOrdersPending();
        void printAllOrdersReceived();
        void printAllOrdersCancelled();
        void printAllOrders();
};

#endif /* ORDERMANAGER_H_ */
