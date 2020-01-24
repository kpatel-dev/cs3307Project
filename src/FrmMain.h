/**
 *@brief FrmMain class
 *
 *Builds a Graphical User Interface for the Restaurant Inventory Management system
 *using  the gtk library and project code
 *@author Fahreen Bushra
 *@date November 29, 2019
*/

#include <gtkmm.h>

class FrmMain : public Gtk::Window{
protected:
    Glib::RefPtr<Gtk::Builder> builder;
    Gtk::Button *btnOrders;
    Gtk :: Window *popup_inventory;
    Gtk :: Window *popup_orders;
    Gtk :: Window *popup_coupons;
    Gtk :: Window *welcome;
    Gtk :: Window *failed_login_window;

    //radio buttons toggled
    Gtk::ToggleButton *rb_a;
    Gtk::ToggleButton *rb_m;
    Gtk::ToggleButton *rb_e;

// ---------------------------------------------------------------------    
    //admin login page
    Gtk :: Window *login_window_admin;
    Gtk :: Entry *admin_fn;
    Gtk :: Entry *admin_ln;
    Gtk:: Entry *admin_id;
    Gtk::Button *login_admin_btn;
    
    //admin action page
    Gtk :: Window *admin_action_page;
    
    Gtk::Button *staff_initialize_btn;
    Gtk::Button *inventory_initialize_btn;
    Gtk::Button *coupon_initialize_btn;
    
    Gtk :: FileChooserButton *staff_file;
    Gtk :: FileChooserButton *inventory_file;
    Gtk :: FileChooserButton *coupon_file;
    
    
    Gtk :: Window *wrong_filetype_window;
    Gtk :: Window *wrong_file_format_window;
    Gtk :: Window *nofile_window;
//------------------------------------------------------------------   
    
    
// ---------------------------------------------------------------------
    
    //manager login page
    Gtk :: Window *login_window_manager;
    Gtk :: Entry *manager_fn;
    Gtk :: Entry *manager_ln;
    Gtk:: Entry *manager_id;
    Gtk::Entry *manager_p;
    Gtk :: Button *login_manager_btn;
        
    //manager action page
    Gtk :: Window *manager_action_window;
    
    Gtk :: Button *manage_orders_manager_btn;
    Gtk :: Button *manage_staff_btn;
    Gtk :: Button *manage_menu_btn;
    Gtk :: Button *manage_inventory_btn;
    Gtk :: Button *manage_coupons_btn;
    
// -----------------------------------------------------------------

    
//Inventory---------------------------------------------------------
    Gtk :: Window *inventory_action_window;
    
    Gtk :: Button *view_stock_btn;
    Gtk :: Button *view_low_stock_btn;
    Gtk :: Button *view_outofstock_btn;
    Gtk :: Button *send_order_stock;
    Gtk :: Button *receive_order_stock;
    Gtk :: Button *cancel_stock_order;
    Gtk :: Button *print_stock_orders;
    Gtk :: Button *view_specificItem_btn;
 
    // make order
    Gtk :: Window *send_inventory_window;
    Gtk :: Entry *send_inventory_name;
    Gtk :: Entry *send_inventory_q;
    Gtk :: Button *send_inventory_submit_btn;
    
    //receive order
    Gtk :: Window *receive_inventory_window;
    Gtk :: Entry *receive_inventory_ID;
    Gtk :: Button *receive_inventory_btn;
    
    //cancel order
    Gtk :: Window *cancel_inventory_window;
    Gtk :: Entry *cancel_inventory_ID;
    Gtk :: Button *cancel_inventory_btn;
    
    //see specific item
    Gtk :: Window *specific_inventory_window;
    Gtk :: Button *specific_inventory_btn;
    Gtk :: Entry *specific_inventory_name;
//----------------------------------------------------------------------




//Menu------------------------------------------------------------------
    Gtk :: Window *menu_window;
    Gtk :: Button *menu_new_btn;
    Gtk :: Button *menu_remove_btn;
    Gtk :: Button *menu_updatePrice_btn;
    Gtk :: Button *menu_view_btn;
    Gtk :: Button *menu_seeAll_btn;
    
    //Add new item
    Gtk :: Window *menu_new_item_window;
    
    Gtk :: Entry *menu_new_item_name;
    Gtk :: Entry *menu_new_item_ID;
    Gtk :: Entry *menu_new_item_price;
    Gtk :: Entry *menu_new_item_CI;
    Gtk :: Entry *menu_new_item_MI;
    Gtk :: Entry *menu_new_item_ing;
    
    Gtk :: Button *menu_add_btn;
      
    //Remove item
     Gtk :: Window *menu_remove_item_window;
     Gtk :: Entry *menu_remove_item_name;
     Gtk :: Button *menu_remove_item_btn;
    
    //update menu price
    Gtk :: Window *menu_update_item_window;
    Gtk :: Entry *menu_update_item_name;
    Gtk :: Entry *menu_update_item_price;
    Gtk :: Button *menu_update_item_btn;
//----------------------------------------------------------------------




//Staff-----------------------------------------------------------------
    Gtk :: Window *staff_window;
    Gtk :: Button *btnAddStaff;
    Gtk :: Button *btnRemoveStaff;
    Gtk :: Button *btnSeeManagers;
    Gtk :: Button *btnSeeEmp;
    Gtk :: Button *btnSeeStaff;
    
     //add staff
     Gtk :: Window *staff_new_member_window;
     Gtk :: Entry *staff_new_member_ID;
     Gtk :: Entry *staff_new_member_fn;
     Gtk :: Entry *staff_new_member_ln;
     Gtk :: Entry *staff_new_member_type;
     Gtk :: Entry *staff_new_member_pass;
     Gtk :: Button *staff_new_member_btn;
     
    // remove staff
    Gtk :: Window *staff_remove_window;
    Gtk :: Entry *staff_remove_ID;
    Gtk :: Button *staff_remove_btn;
    
//----------------------------------------------------------------------
    
    
//Transaction-----------------------------------------------------------
    Gtk :: Window *transaction_window;
    Gtk :: Button *transaction_create;
    Gtk :: Button *transaction_fulfill;
    Gtk :: Button *transaction_see_pending;
    Gtk :: Button *transaction_see_completed;
    Gtk :: Button *transaction_see_all;
    Gtk :: Button *transaction_see_revenue;
    //create transaction
    Gtk :: Window *create_transaction_window;
    Gtk :: Entry *create_transaction_name;
    Gtk :: Entry *create_transaction_q;
    Gtk :: Button *create_transaction_btn;

    // fullfill transaction
    Gtk :: Window *fulfill_transaction_window;
    Gtk :: Entry *fulfill_transaction_ID;
    Gtk :: Button *fulfill_transaction_btn;
    

//----------------------------------------------------------------------
   //employee login page
    Gtk :: Window *login_window_employee;
    Gtk :: Entry *emp_fn;
    Gtk :: Entry *emp_ln;
    Gtk:: Entry *emp_id;
    Gtk::Entry *emp_p;
    Gtk :: Button *login_emp_btn;
    Gtk:: Button *btnInitializeStaff;
    Gtk::Button *submit_btn;
    //employee action page
    Gtk :: Window *employee_action_window;
    Gtk::Button *employee_manage_orders_btn;
//----------------------------------------------------------------------
   


public:
    FrmMain(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade);//constructor

protected: 
    //signal handlers
    void on_btnOrders_clicked();
    void on_btnInitializeStaff_clicked();
    
    //radio button signal handlers
    void on_submit_btn_clicked();
    
    //admin login button
    void on_login_admin_btn_clicked();
    
    //admin action buttons
    void on_staff_initialize_btn_clicked();
    void on_inventory_initialize_btn_clicked();
    void on_coupon_initialize_btn_clicked();
    
    // manager login and actions
    void on_login_manager_btn_clicked();
    void on_manage_orders_manager_btn_clicked();
    void on_manage_staff_btn_clicked();
    void on_manage_menu_btn_clicked();
    void on_manage_inventory_btn_clicked();
    void on_manage_coupons_btn_clicked();
    
    //employee Login and actions
    void on_employee_manage_orders_btn_clicked();
    
    //inventory
    void on_view_stock_btn_clicked();
    void on_view_low_stock_btn_clicked();
    void on_view_outofstock_btn_clicked();
    void on_send_order_stock_clicked();
    void on_receive_order_stock_clicked();
    void on_cancel_stock_order_clicked();
    void on_print_stock_orders_clicked();
    
    void on_view_specificItem_btn_clicked();
    void on_specific_inventory_btn_clicked();
    
    void on_send_inventory_submit_btn_clicked();
    void on_receive_inventory_btn_clicked();
    void on_cancel_inventory_btn_clicked();
    
    // menu
    void on_menu_new_btn_clicked();
    void on_menu_remove_btn_clicked();
    void on_menu_updatePrice_btn_clicked();
    void on_menu_view_btn_clicked();
    void on_menu_seeAll_btn_clicked();
    void on_menu_add_btn_clicked();
    void on_menu_remove_item_btn_clicked();
    void on_menu_update_item_btn_clicked();
    
    // staff
    void on_btnAddStaff_clicked();
    void on_btnRemoveStaff_clicked();
    void on_btnSeeManagers_clicked();
    void on_btnSeeEmp_clicked();
    void on_btnSeeStaff_clicked();
    void on_staff_new_member_btn_clicked();
    void on_staff_remove_btn_clicked();
    
    //transaction
    void on_transaction_create_clicked();
    void on_transaction_fulfill_clicked();
    void on_transaction_see_pending_clicked();
    void on_transaction_see_completed_clicked();
    void on_transaction_see_all_clicked();
    void on_create_transaction_btn_clicked();
    void on_fulfill_transaction_btn_clicked();
    void on_transaction_see_revenue_clicked();
    
    //employee login button
    void on_login_emp_btn_clicked();
    
   
    
};
