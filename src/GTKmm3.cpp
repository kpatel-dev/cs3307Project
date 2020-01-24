

/**
 *@brief GTKmm3 class
 *
 *main function for the Restaurant Inventory Managementprogram
 *runs the interface by linking the frmMain class with the gio.glade file and builds the parent widget for the gui
 *
 *@author Fahreen Bushra
 *@date Novembre 29,2019
 */

#include <iostream>
#include <gtkmm.h>
#include "FrmMain.h"


using namespace std;

/**
 *@brief main function for the Restaurant Inventory Management program
 *runs the interface by linking the frmMain class with the gio.glade file and builds the parent widget for the gui
 *call the main function using the arguments from this class
 *@param int number commands the user puts
 *@param char ** the commands that the user enters
 *@return int  0 on success
*/
int main(int argc, char **argv) {
	cout << "Started" << endl;

	Gtk:: Main kit(argc,argv);
	Glib::RefPtr<Gtk::Builder> builder = Gtk::Builder::create_from_file("gui.glade");

	FrmMain *frm = 0;
	builder->get_widget_derived("frmMain", frm);
	kit.run(*frm);

	cout << "End" << endl;

	return 0;
}
