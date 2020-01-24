/**
 *@brief FrmMain class
 
 *Builds a Graphical User Interface for the Restaurant Inventory Management system
 *using  the gtk library and project code
 *
 *@author Fahreen Bushra
 *@date November 29, 2019
*/


#include <iostream>
#include <string>
#include <algorithm>


#include "FrmMain.h"

#include "InventoryManager.h"
#include "ItemLoader.h"
#include "MenuItem.h"
#include "Price.h"
#include "StaffManager.h"
#include "User.h"
#include "UserDataLoader.h"
#include "PromoLoader.h"
#include "Coupon.h"
#include "CouponManager.h"
#include "Order.h"
#include "OrderManager.h"
#include "StockManager.h"
#include "Transaction.h"
#include "TransactionManager.h"
#include "FileLoader.h"
#include <sstream> 

using namespace std;


/**
 *@brief FrmMain constructor that inherits from Gtk::Window(cobject), builder(refGlade)
 *assigns widgets from teh glade file to the varables
 *@param BaseObjectType*
 *@param Glib::RefPtr
*/

FrmMain::FrmMain(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade) :
    Gtk::Window(cobject), builder(refGlade){
    
    /**build buttons for main page*/
    //builder->get_widget("btnStaff", btnStaff);
    //builder->get_widget("btnInventory", btnInventory);
    builder->get_widget("btnOrders", btnOrders);
    //builder->get_widget("btnCoupons", btnCoupons);
    
    /**build pop up windows*/
    builder->get_widget("popup_inventory", popup_inventory);
    builder->get_widget("popup_orders", popup_orders); //DELETE
    builder->get_widget("popup_coupons", popup_coupons);
    builder->get_widget("welcome", welcome);
    
    /**failed login window*/
    builder->get_widget("failed_login_window",failed_login_window);
    
    
    builder->get_widget("rb_a", rb_a);
    builder->get_widget("rb_m", rb_m);
    builder->get_widget("rb_e", rb_e);
    builder->get_widget("submit_btn", submit_btn);
    

    
    /**admin login page -------------------------------------------------*/
    builder->get_widget("login_window_admin", login_window_admin);
   
    builder->get_widget("admin_fn", admin_fn);
    
    builder->get_widget("admin_ln", admin_ln);
    builder->get_widget("admin_id", admin_id);
    builder->get_widget("login_admin_btn", login_admin_btn);
    /** -----------------------------------------------------------------*/
    
    /**admin action page ------------------------------------------------*/
    builder->get_widget("admin_action_page", admin_action_page);
    
    builder->get_widget("staff_initialize_btn", staff_initialize_btn);
    builder->get_widget("inventory_initialize_btn", inventory_initialize_btn);
    builder->get_widget("coupon_initialize_btn", coupon_initialize_btn);
    
    builder->get_widget("staff_file", staff_file);
    builder->get_widget("inventory_file", inventory_file);
    builder->get_widget("coupon_file", coupon_file);
    
    builder->get_widget("nofile_window", nofile_window);
    builder->get_widget("wrong_filetype_window", wrong_filetype_window);
    builder->get_widget("wrong_file_format_window", wrong_file_format_window);
    /** -----------------------------------------------------------------*/

    /**Manager login page -----------------------------------------------*/
   builder->get_widget("login_window_manager", login_window_manager);
    builder->get_widget("manager_fn", manager_fn);
    builder->get_widget("manager_ln", manager_ln);
    builder->get_widget("manager_id", manager_id);
    builder->get_widget("manager_p", manager_p);
    builder->get_widget("login_manager_btn", login_manager_btn);   
    /**-----------------------------------------------------------------*/
    
    
    /**Manager Action page -----------------------------------------------*/
    builder->get_widget("manager_action_window", manager_action_window);
    
    /**buttons*/
    builder->get_widget("manage_orders_manager_btn", manage_orders_manager_btn);
    builder->get_widget("manage_staff_btn", manage_staff_btn);
    builder->get_widget("manage_menu_btn", manage_menu_btn);
    builder->get_widget("manage_inventory_btn", manage_inventory_btn);
    builder->get_widget("manage_coupons_btn", manage_coupons_btn);






	/**Inventory ------------------------------------------------------------*/
    builder->get_widget("inventory_action_window", inventory_action_window);

    builder->get_widget("view_stock_btn",view_stock_btn );
    builder->get_widget("view_low_stock_btn", view_low_stock_btn);
    builder->get_widget("view_outofstock_btn",view_outofstock_btn );
    builder->get_widget("send_order_stock",send_order_stock );
    builder->get_widget("receive_order_stock",receive_order_stock );
    builder->get_widget("cancel_stock_order", cancel_stock_order);
    builder->get_widget("print_stock_orders", print_stock_orders);
    builder->get_widget("view_specificItem_btn", view_specificItem_btn);

    
    /**send a inventory order*/
    builder->get_widget("send_inventory_window",send_inventory_window );
    builder->get_widget("send_inventory_name", send_inventory_name);
    builder->get_widget("send_inventory_q", send_inventory_q);
    builder->get_widget("send_inventory_submit_btn",send_inventory_submit_btn );

    
    /**receive inventory order*/
    builder->get_widget("receive_inventory_window", receive_inventory_window);
    builder->get_widget("receive_inventory_ID", receive_inventory_ID);
    builder->get_widget("receive_inventory_btn", receive_inventory_btn);
    
    
    
    /**cancel inventory order*/
    builder->get_widget("cancel_inventory_window", cancel_inventory_window);
    builder->get_widget("cancel_inventory_ID",cancel_inventory_ID );
    builder->get_widget("cancel_inventory_btn", cancel_inventory_btn);
    
    
    /**get specific item inventory*/
    builder->get_widget("specific_inventory_window",specific_inventory_window );
    builder->get_widget("specific_inventory_btn", specific_inventory_btn);
    builder->get_widget("specific_inventory_name", specific_inventory_name); 
    
/**----------------------------------------------------------------------*/




/**Menu------------------------------------------------------------------*/
    
    builder->get_widget("menu_window", menu_window);
    builder->get_widget("menu_new_btn",menu_new_btn );
    builder->get_widget("menu_remove_btn",menu_remove_btn );
    builder->get_widget("menu_updatePrice_btn", menu_updatePrice_btn);
    builder->get_widget("menu_view_btn", menu_view_btn);
    builder->get_widget("menu_seeAll_btn",menu_seeAll_btn );
    
    
    /**Add new item*/
    builder->get_widget("menu_new_item_window",menu_new_item_window );
    builder->get_widget("menu_new_item_name", menu_new_item_name);
    builder->get_widget("menu_new_item_ID", menu_new_item_ID);
    builder->get_widget("menu_new_item_price",menu_new_item_price );
    builder->get_widget("menu_new_item_CI",menu_new_item_CI);
    builder->get_widget("menu_new_item_MI",menu_new_item_MI );
    builder->get_widget("menu_new_item_ing",menu_new_item_ing );
    builder->get_widget("menu_add_btn",menu_add_btn );

    /**remove item*/
    builder->get_widget("menu_remove_item_window",menu_remove_item_window );
    builder->get_widget("menu_remove_item_name", menu_remove_item_name);
    builder->get_widget("menu_remove_item_btn",menu_remove_item_btn );

    
    /**update item price*/
    builder->get_widget("menu_update_item_window",menu_update_item_window );
    builder->get_widget("menu_update_item_name",menu_update_item_name );
    builder->get_widget("menu_update_item_price", menu_update_item_price);
    builder->get_widget("menu_update_item_btn", menu_update_item_btn);
/**------------------------------------------------------------------





/**Staff-----------------------------------------------------------------*/
    builder->get_widget("staff_window", staff_window);
    builder->get_widget("btnAddStaff",btnAddStaff );
    builder->get_widget("btnRemoveStaff", btnRemoveStaff);
    builder->get_widget("btnSeeManagers",btnSeeManagers );
    builder->get_widget("btnSeeEmp", btnSeeEmp);
    builder->get_widget("btnSeeStaff", btnSeeStaff);
    
    /**add staff*/
    builder->get_widget("staff_new_member_window",staff_new_member_window );
    builder->get_widget("staff_new_member_ID", staff_new_member_ID);
    builder->get_widget("staff_new_member_fn", staff_new_member_fn);
    builder->get_widget("staff_new_member_ln", staff_new_member_ln);
    builder->get_widget("staff_new_member_type", staff_new_member_type);
    builder->get_widget("staff_new_member_pass",staff_new_member_pass );
    builder->get_widget("staff_new_member_btn", staff_new_member_btn);
    
    
    /** remove staff*/
    builder->get_widget("staff_remove_window",staff_remove_window );
    builder->get_widget("staff_remove_ID", staff_remove_ID);
    builder->get_widget("staff_remove_btn", staff_remove_btn);
    
    
/**----------------------------------------------------------------------*/


/**Transaction-----------------------------------------------------------*/
    builder->get_widget("transaction_window", transaction_window);
    builder->get_widget("transaction_create",transaction_create );
    builder->get_widget("transaction_fulfill", transaction_fulfill);
    builder->get_widget("transaction_see_pending", transaction_see_pending);
    builder->get_widget("transaction_see_completed",transaction_see_completed );
    builder->get_widget("transaction_see_all",transaction_see_all );
    builder->get_widget("transaction_see_revenue", transaction_see_revenue);

    /**create transaction*/
    builder->get_widget("create_transaction_window",create_transaction_window );
    builder->get_widget("create_transaction_name", create_transaction_name);
    builder->get_widget("create_transaction_q", create_transaction_q);
    builder->get_widget("create_transaction_btn", create_transaction_btn);
    
    
    /** fullfill transaction*/
     builder->get_widget("fulfill_transaction_window", fulfill_transaction_window); 
     builder->get_widget("fulfill_transaction_ID", fulfill_transaction_ID);
     builder->get_widget("fulfill_transaction_btn", fulfill_transaction_btn);

/**----------------------------------------------------------------------*/

    
    /**Employee login page -----------------------------------------------*/
    builder->get_widget("login_window_employee", login_window_employee);
    builder->get_widget("emp_fn", emp_fn);
    builder->get_widget("emp_ln", emp_ln);
    builder->get_widget("emp_id", emp_id);
    builder->get_widget("emp_p", emp_p);
    builder->get_widget("login_emp_btn", login_emp_btn); 
    builder->get_widget("employee_action_window", employee_action_window); 
    builder->get_widget("employee_manage_orders_btn", employee_manage_orders_btn); 

    /** -----------------------------------------------------------------*/

    
    /** BUILD SIGNALS ---------------------------------------------------*/
   
    btnOrders->signal_clicked().connect(sigc::mem_fun(*this, &FrmMain::on_btnOrders_clicked));
    submit_btn->signal_clicked().connect(sigc::mem_fun(*this, &FrmMain::on_submit_btn_clicked));
    login_admin_btn->signal_clicked().connect(sigc::mem_fun(*this, &FrmMain::on_login_admin_btn_clicked));
    staff_initialize_btn->signal_clicked().connect(sigc::mem_fun(*this, &FrmMain::on_staff_initialize_btn_clicked));
    inventory_initialize_btn->signal_clicked().connect(sigc::mem_fun(*this, &FrmMain::on_inventory_initialize_btn_clicked));
    coupon_initialize_btn->signal_clicked().connect(sigc::mem_fun(*this, &FrmMain::on_coupon_initialize_btn_clicked));
    login_manager_btn->signal_clicked().connect(sigc::mem_fun(*this, &FrmMain::on_login_manager_btn_clicked));
    login_emp_btn->signal_clicked().connect(sigc::mem_fun(*this, &FrmMain::on_login_emp_btn_clicked));
    
    /**manager action page buttons*/
    manage_orders_manager_btn->signal_clicked().connect(sigc::mem_fun(*this, &FrmMain::on_manage_orders_manager_btn_clicked));
    manage_staff_btn->signal_clicked().connect(sigc::mem_fun(*this, &FrmMain::on_manage_staff_btn_clicked));
    manage_menu_btn->signal_clicked().connect(sigc::mem_fun(*this, &FrmMain::on_manage_menu_btn_clicked));
    manage_inventory_btn->signal_clicked().connect(sigc::mem_fun(*this, &FrmMain::on_manage_inventory_btn_clicked));
    manage_coupons_btn->signal_clicked().connect(sigc::mem_fun(*this, &FrmMain::on_manage_coupons_btn_clicked));

    /**inventory*/
    view_stock_btn->signal_clicked().connect(sigc::mem_fun(*this, &FrmMain::on_view_stock_btn_clicked));
    view_low_stock_btn->signal_clicked().connect(sigc::mem_fun(*this, &FrmMain::on_view_low_stock_btn_clicked));
    view_outofstock_btn->signal_clicked().connect(sigc::mem_fun(*this, &FrmMain::on_view_outofstock_btn_clicked));
    send_order_stock->signal_clicked().connect(sigc::mem_fun(*this, &FrmMain::on_send_order_stock_clicked));
    receive_order_stock->signal_clicked().connect(sigc::mem_fun(*this, &FrmMain::on_receive_order_stock_clicked));
    cancel_stock_order->signal_clicked().connect(sigc::mem_fun(*this, &FrmMain::on_cancel_stock_order_clicked));
    print_stock_orders->signal_clicked().connect(sigc::mem_fun(*this, &FrmMain::on_print_stock_orders_clicked));
    send_inventory_submit_btn ->signal_clicked().connect(sigc::mem_fun(*this, &FrmMain::on_send_inventory_submit_btn_clicked));
    receive_inventory_btn->signal_clicked().connect(sigc::mem_fun(*this, &FrmMain::on_receive_inventory_btn_clicked));
    cancel_inventory_btn->signal_clicked().connect(sigc::mem_fun(*this, &FrmMain::on_cancel_inventory_btn_clicked));
    view_specificItem_btn->signal_clicked().connect(sigc::mem_fun(*this, &FrmMain::on_view_specificItem_btn_clicked));
    specific_inventory_btn->signal_clicked().connect(sigc::mem_fun(*this, &FrmMain::on_specific_inventory_btn_clicked));

    /** menu*/
    menu_new_btn->signal_clicked().connect(sigc::mem_fun(*this, &FrmMain::on_menu_new_btn_clicked));
    menu_remove_btn->signal_clicked().connect(sigc::mem_fun(*this, &FrmMain::on_menu_remove_btn_clicked));
    menu_updatePrice_btn->signal_clicked().connect(sigc::mem_fun(*this, &FrmMain::on_menu_updatePrice_btn_clicked));
    menu_view_btn->signal_clicked().connect(sigc::mem_fun(*this, &FrmMain::on_menu_view_btn_clicked));
    menu_seeAll_btn->signal_clicked().connect(sigc::mem_fun(*this, &FrmMain::on_menu_seeAll_btn_clicked));
    menu_add_btn->signal_clicked().connect(sigc::mem_fun(*this, &FrmMain::on_menu_add_btn_clicked));
    menu_remove_item_btn->signal_clicked().connect(sigc::mem_fun(*this, &FrmMain::on_menu_remove_item_btn_clicked));
    menu_update_item_btn->signal_clicked().connect(sigc::mem_fun(*this, &FrmMain::on_menu_update_item_btn_clicked));
    
    /**employee*/
    login_emp_btn->signal_clicked().connect(sigc::mem_fun(*this, &FrmMain::on_login_emp_btn_clicked));
    employee_manage_orders_btn->signal_clicked().connect(sigc::mem_fun(*this, &FrmMain::on_employee_manage_orders_btn_clicked));


    /**staff */
    btnAddStaff->signal_clicked().connect(sigc::mem_fun(*this, &FrmMain::on_btnAddStaff_clicked));
    btnRemoveStaff->signal_clicked().connect(sigc::mem_fun(*this, &FrmMain::on_btnRemoveStaff_clicked));
    btnSeeManagers->signal_clicked().connect(sigc::mem_fun(*this, &FrmMain::on_btnSeeManagers_clicked));
    btnSeeEmp->signal_clicked().connect(sigc::mem_fun(*this, &FrmMain::on_btnSeeEmp_clicked));
    btnSeeStaff->signal_clicked().connect(sigc::mem_fun(*this, &FrmMain::on_btnSeeStaff_clicked));
    staff_new_member_btn->signal_clicked().connect(sigc::mem_fun(*this, &FrmMain::on_staff_new_member_btn_clicked));
    staff_remove_btn->signal_clicked().connect(sigc::mem_fun(*this, &FrmMain::on_staff_remove_btn_clicked));


    /**transactions */
    transaction_create->signal_clicked().connect(sigc::mem_fun(*this, &FrmMain::on_transaction_create_clicked));
    transaction_fulfill->signal_clicked().connect(sigc::mem_fun(*this, &FrmMain::on_transaction_fulfill_clicked));
    transaction_see_pending->signal_clicked().connect(sigc::mem_fun(*this, &FrmMain::on_transaction_see_pending_clicked));
    transaction_see_completed->signal_clicked().connect(sigc::mem_fun(*this, &FrmMain::on_transaction_see_completed_clicked));
    transaction_see_all->signal_clicked().connect(sigc::mem_fun(*this, &FrmMain::on_transaction_see_all_clicked));
    create_transaction_btn->signal_clicked().connect(sigc::mem_fun(*this, &FrmMain::on_create_transaction_btn_clicked));
    fulfill_transaction_btn->signal_clicked().connect(sigc::mem_fun(*this, &FrmMain::on_fulfill_transaction_btn_clicked));
    transaction_create ->signal_clicked().connect(sigc::mem_fun(*this, &FrmMain::on_transaction_create_clicked));
    transaction_see_revenue->signal_clicked().connect(sigc::mem_fun(*this, &FrmMain::on_transaction_see_revenue_clicked));
    

    
    
    

    /** -----------------------------------------------------------------*/
    
}


/**MAIN WINDOW-----------------------------------------------------------*/

/**
 *@brief button clicked
 */
void FrmMain::on_btnOrders_clicked(){
      welcome->show();
    
}

/**WELCOME PAGE, WHO AM I*/
/**
 *@brief welcome page, WHO AM I
 */
void FrmMain:: on_submit_btn_clicked(){
  
     if (rb_a -> get_active()) {
         login_window_admin -> show();
         admin_fn->set_text("");
         admin_ln->set_text("");
         admin_id->set_text("");
         welcome -> hide();}
       
    else if (rb_m -> get_active()) {
        login_window_manager -> show();
        manager_fn->set_text("");
        manager_ln->set_text("");
        manager_id->set_text("");
        manager_p->set_text("");
        welcome -> hide();}
       
    else if (rb_e -> get_active()) {
        login_window_employee -> show();
        emp_fn->set_text("");
        emp_ln->set_text("");
        emp_id->set_text("");
        emp_p->set_text("");
        welcome -> hide();
}
    }
    
/**Admin Login Page -----------------------------------------------------*/
/**
 *@brief admin login page
 */
void FrmMain:: on_login_admin_btn_clicked(){
    string FName;
    string LName;
    string ID;
    
    FName = admin_fn->get_text();
    LName = admin_ln->get_text();
    ID = admin_id->get_text();
    
    for_each(FName.begin(), FName.end(), [](char & c){
        c = ::tolower(c);});
    
    for_each(LName.begin(), LName.end(), [](char & c){
        c = ::tolower(c);});
   

     if (FName == "fahreen" && LName == "bushra" && ID == "123456"){
         login_window_admin -> hide();
         
         // show admin page
         admin_action_page -> show();
         
         }
         
    else
        failed_login_window -> show();
        
    }
/** ---------------------------------------------------------------------*/


/** Admin action page ---------------------------------------------------*/
/**
 * @brief initialize staff button
 */
    void FrmMain::on_staff_initialize_btn_clicked(){
        string name;
        string suffix;
        string f;
        suffix = ".csv";
        f = "employees.csv";
        name = staff_file -> get_filename();
        
        if (name.size() != 0){
            
            /**check if it is a csv file*/
            if ((name.compare( ((name.size() - suffix.size())) , 4, suffix)) == 0){
                
                /**if incorrect file format*/
                if((name.compare( ((name.size() - f.size())) , 13, f)) == 0){
                    FileLoader f1("src/employees.csv",'A');
                    popup_orders-> show();
                    }
                else
                    wrong_file_format_window -> show();
                }
            /** if wrong file type*/
            else
                wrong_filetype_window -> show();
                }
        /**if no file selected  */      
        else
            nofile_window -> show();
            }
            
    /**
     *@brief initialize inventory button
     */
    void FrmMain::on_inventory_initialize_btn_clicked(){
        string name;
        string suffix;
        string f;
        suffix = ".csv";
        f = "foodinventory.csv";  
        name = inventory_file -> get_filename();
    
        if (name.size() != 0){
            
            /**check if it is a csv file*/
            if ((name.compare( ((name.size() - suffix.size())) , 4, suffix)) == 0){
                
                /**if incorrect file format*/
                if((name.compare( ((name.size() - f.size())) , 17, f)) == 0){
                    FileLoader f1("src/foodinventory.csv",'B');
                    popup_inventory-> show();}
                else
                    wrong_file_format_window -> show();
                }
            /** if wrong file type*/
            else
                wrong_filetype_window -> show();
                }
        /**if no file selected  */      
        else
            nofile_window -> show();
            }       
        
    
    /**
     *@brief initialize coupon button
     */
    void FrmMain::on_coupon_initialize_btn_clicked(){
        string name;
        string suffix;
        string f;
        suffix = ".csv";
        f = "promos.csv";
        name = coupon_file -> get_filename();
        
        if (name.size() != 0){
            
            /**check if it is a csv file*/
            if ((name.compare( ((name.size() - suffix.size())) , 4, suffix)) == 0){
                
                /**if incorrect file format*/
                if((name.compare( ((name.size() - f.size())) , 10, f)) == 0){
                    FileLoader f1("src/promos.csv", 'C');

                    popup_coupons -> show();}
                else
                    wrong_file_format_window -> show();
                }
            /**if wrong file type*/
            else
                wrong_filetype_window -> show();
                }
        /**if no file selected     */   
        else
            nofile_window -> show();        
        }
/** ---------------------------------------------------------------------*/

/** MANAGER==============================================================*/
    
/** Manager Login Page --------------------------------------------------*/
    /**
     *@brief manager login button
     */
   void FrmMain:: on_login_manager_btn_clicked(){
       
    string FName;
    string LName;
    string ID;
    string password;
    string type = "manager";
    FName = manager_fn->get_text();
    LName = manager_ln->get_text();
    ID = manager_id->get_text();
    password = manager_p->get_text();
    
    
    User user(ID, FName, LName, type,password);
    User emp = StaffManager::instance().getStaff(user);
    
    if (emp.getUID() == "000000")
        failed_login_window -> show();
    else {
        if ( emp.getUType().compare(type) == 0 ){
         manager_action_window -> show();
         login_window_manager -> hide();}
         
        else{    
    failed_login_window -> show();}
    }}

/**----------------------------------------------------------------------*/

/** Manager Action Page --------------------------------------------------*/
    /**
     *@brief manager orders manager button
     */
    void FrmMain::on_manage_orders_manager_btn_clicked(){
        transaction_window->show();
        
        }
    /**
     *@brief manager staff button
     */
    void FrmMain::on_manage_staff_btn_clicked(){
        staff_window ->show();
        }
         
    /**
     *@brief manager menu button
     */
    void FrmMain::on_manage_menu_btn_clicked(){
        menu_window-> show();
        }
        
    /**
     *@brief manager inventory burron
     */
    void FrmMain::on_manage_inventory_btn_clicked(){
        inventory_action_window -> show();
        }
    /**
     *@brief manager coupons button
     */
    void FrmMain::on_manage_coupons_btn_clicked(){
        }
/** =====================================================================*/
        
        

        
/** INVENTORY============================================================*/
    
    /**
     *@brief view stock button
     */
    void FrmMain::on_view_stock_btn_clicked(){
        StockManager::instance().printItemsInStock();
        }
        
    /**
     *@brief view low stock button
     */
    void FrmMain::on_view_low_stock_btn_clicked(){
        StockManager::instance().printItemsBelowThreshold();
        }
     /**
      *@brief view out of stick button
      */
    void FrmMain::on_view_outofstock_btn_clicked(){
        StockManager::instance().printItemsOutOfStock();
        }
        /**
         *@brief print stock orders button
         */
        void FrmMain::on_print_stock_orders_clicked(){
        OrderManager::instance().printAllOrders();
        }
/**send order------------------------------------------------------------*/
    /**
     *send order stock button
     */
    void FrmMain::on_send_order_stock_clicked(){
        send_inventory_window -> show();}
    /**
     *@send inventory submit button
     */
    void FrmMain:: on_send_inventory_submit_btn_clicked(){
        string itemName = send_inventory_name->get_text();
        int quantity = stoi(send_inventory_q->get_text());
        OrderManager::instance().createOrder(itemName, quantity);}
/**receive order---------------------------------------------------------*/
    /**
     *@brief recieve order stock clicked
     */
    void FrmMain::on_receive_order_stock_clicked(){
        receive_inventory_window -> show();}
     /**
      *@brief recieve inventory button
      */
    void FrmMain:: on_receive_inventory_btn_clicked(){
        int orderId = stoi(receive_inventory_ID -> get_text());
        OrderManager::instance().markOrderReceived(orderId);}
        
/**cancel order----------------------------------------------------------*/
    /**
     *@brief cancel stock order button clicked
     */
    void FrmMain::on_cancel_stock_order_clicked(){
       cancel_inventory_window-> show();
        }
    /**
     *@brief cancel inventory button
     */
    void FrmMain:: on_cancel_inventory_btn_clicked(){
        int orderId = stoi(cancel_inventory_ID ->get_text());
        OrderManager::instance().cancelOrder(orderId);
        }
        
/** view specific item stock --------------------------------------------*/
    
    /**
     *@brief view specific items inventory
     */
    void FrmMain::on_view_specificItem_btn_clicked(){
            specific_inventory_window -> show();
            }
            
    /**
     *@brief specific inventory button click
     */
    void FrmMain::on_specific_inventory_btn_clicked(){
            string itemName = specific_inventory_name ->get_text();
            InventoryManager::instance().printMenuItem(itemName);
            }


/**======================================================================*/




/** MENU=================================================================*/

    /**see all items ----------------------------------------------------*/
    /**
     *@brief see all items on menu button
     */
    void FrmMain::on_menu_seeAll_btn_clicked(){
        InventoryManager::instance().printAllMenuItems();
        }
   /**see a item -------------------------------------------------------*/
/**
 *@brief view items on menu button click
 */
   void FrmMain::on_menu_view_btn_clicked(){
       specific_inventory_window -> show();
       }
   
    /**add item ---------------------------------------------------------*/
/**
 *@brief add new item button clicked
 */
    void FrmMain::on_menu_new_btn_clicked(){
        menu_new_item_window -> show();
        }
    /**
     *@brief add new item button clicked
     */
    void FrmMain::on_menu_add_btn_clicked(){
        string name = menu_new_item_name ->get_text();
        string id = menu_new_item_ID -> get_text();
        double price =stof(menu_new_item_price->get_text());
        int currentInventory =stoi(menu_new_item_CI ->get_text());
        int minimumInventory =stoi(menu_new_item_MI->get_text());
        string ingredients =menu_new_item_ing->get_text();
        
        MenuItem item1(name,id,price,currentInventory,minimumInventory,ingredients);
        InventoryManager::instance().addMenuItem(item1);
        }
        
        
    /**Remove Item ------------------------------------------------------*/
/**
 *@brief remove a menu item button
 */
    void FrmMain::on_menu_remove_btn_clicked(){
        menu_remove_item_window ->show();
        }
        /**
         *@brief remove a menu item button
         */
    void FrmMain::on_menu_remove_item_btn_clicked(){
        string itemName = menu_remove_item_name -> get_text();
        InventoryManager::instance().removeMenuItem(itemName);
        
        }
    /**Update price------------------------------------------------------*/
/**
 *@brief update price of menuitem button
 */
    void FrmMain::on_menu_updatePrice_btn_clicked(){
        menu_update_item_window -> show();
        }
        /**
         *@brief update price of menuitem button
         */
    void FrmMain::on_menu_update_item_btn_clicked(){
        string itemName = menu_update_item_name-> get_text();
        double price = stof(menu_update_item_price-> get_text());
        MenuItem *item = InventoryManager::instance().findMenuItem(itemName);
        item->setPrice(price);
        }

/**======================================================================*/



/**Staff================================================================*/
    
    
    /** add staff--------------------------------------------------------*/
/**
 *@brief add staf button
 */
    void FrmMain::on_btnAddStaff_clicked(){
        staff_new_member_window  -> show();
        }
    /**
     *@brief add new member button clicked
     */
    void FrmMain::on_staff_new_member_btn_clicked(){
        
     string id =  staff_new_member_ID-> get_text();
     string fname =   staff_new_member_fn-> get_text();
     string lname =  staff_new_member_ln -> get_text();
     string type = staff_new_member_type -> get_text();
     string password = staff_new_member_pass  -> get_text();
    User user(id, fname, lname, type,password);
    StaffManager::instance().addStaff(user);}
        
        
    /**remove staff-----------------------------------------------------*/
/**
 *@brief remove staff button
 */
    void FrmMain::on_btnRemoveStaff_clicked(){
        staff_remove_window ->show();
        }
/**
 *@brief remove staff button
 */
     void FrmMain::on_staff_remove_btn_clicked(){
         
         string userId = staff_remove_ID-> get_text();
         StaffManager::instance().removeStaff(userId);
         }

    /** see Managers-----------------------------------------------------*/
/**
 *@brief see managers button
 */
    void FrmMain::on_btnSeeManagers_clicked(){
         StaffManager::instance().printAllManagers();
        }
    
        
    /** see Employees----------------------------------------------------*/
/**
 *@brief see employees button
 */
    void FrmMain::on_btnSeeEmp_clicked(){
        StaffManager::instance().printAllEmployees();
        }
        
    /** see Staff--------------------------------------------------------*/
/**
 *@brief see all staff button
 */
    void FrmMain::on_btnSeeStaff_clicked(){
        StaffManager::instance().printAllStaff();
        }

/**======================================================================*/

    
/** Transactions ========================================================*/
    
    /** Create transaction-----------------------------------------------*/
/**
 *@brief create transaction button
 */
    void FrmMain::on_transaction_create_clicked(){
        create_transaction_window ->show();
        }
/**
 *@brief create transaction buton clicked
 */
    void FrmMain::on_create_transaction_btn_clicked(){
    string itemName = create_transaction_name-> get_text();
    int quantity = stoi(create_transaction_q ->get_text());
    TransactionManager::instance().createTransaction(itemName,quantity);}
    
    
    /** fullfill transaction-----------------------------------------------*/
/**
 *@brief fulfill transaction button
 */
    void FrmMain::on_transaction_fulfill_clicked(){
        fulfill_transaction_window ->show();
        }
/**
 *@brief fulfill transaction button clicked
 */
    void FrmMain::on_fulfill_transaction_btn_clicked(){
    int transactionID = stoi(fulfill_transaction_ID-> get_text());
    TransactionManager::instance().fulfillTransaction(transactionID);
        }  
        
    /** Views------------------------------------------------------------*/
/**
 *@brief see pending transactions button
 */
    void FrmMain::on_transaction_see_pending_clicked(){
        TransactionManager::instance().printAllPendingTransactions();
        }
/**
 *@brief see completed transactions
 */
    void FrmMain::on_transaction_see_completed_clicked(){
        TransactionManager::instance().printAllCompletedTransactions();
        }
/**
 *@brief see all transaction button
 */
    void FrmMain::on_transaction_see_all_clicked(){
        TransactionManager::instance().printAllTransactions();
        }
    /**
     *@brief see the revenue from transaction button
     */
     void FrmMain::on_transaction_see_revenue_clicked(){
         TransactionManager::instance().printTotalProfit();
     }
/**======================================================================   */
        
    

/** Employee login page --------------------------------------------------*/
/**
 *@brief employee login page
 */
    void FrmMain:: on_login_emp_btn_clicked(){
    string FName;
    string LName;
    string ID;
    string password;
    string type = "employee";
    FName = emp_fn->get_text();
    LName = emp_ln->get_text();
    ID = emp_id->get_text();
    password = emp_p->get_text();
    
    
    User user(ID, FName, LName, type,password);
    User emp = StaffManager::instance().getStaff(user);
    
    if (emp.getUID() == "000000")
        failed_login_window -> show();
    else {
        if ( emp.getUType().compare(type) == 0 ){
         employee_action_window -> show();
         login_window_manager -> hide();}
         
        else{    
    failed_login_window -> show();}
    }}
/**----------------------------------------------------------------------*/


/** Employee action page ------------------------------------------------*/
/**
 *@brief employee action page
 */
void FrmMain::on_employee_manage_orders_btn_clicked(){
     transaction_window->show();
    
    }






/**----------------------------------------------------------------------*/







/**MAIN WINDOW-----------------------------------------------------------*/
/**
 *@brief main window
 */
void FrmMain::on_btnInitializeStaff_clicked(){
   // lblNotice->set_text("YAY IT WORKED");
    //initilize staff
    FileLoader f1("src/employees.csv",'A');
    
}
    
