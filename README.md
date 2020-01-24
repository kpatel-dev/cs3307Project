# Cafe Team 38

## Instructions

### Compile our program using the command
	make 
    
make sure you are ~/team38
### Run the program using the command

	./run.out

## Administrator Use Case: 

### Log in as an administrator(Note - this must be done first, otherwise the manager employee data will not be initialized, and they will not be able to log in)
	- click on "Get Started"
    - choose administrator radio button, then press submit
    - To log in as an administrator use the following:
   	First Name : Fahreen 
    Last Name : Bushra 
    ID : 123456
    - If not entered correctly, the administrator should not be able to log in (a test case)


First command should be to initialize staff an inventory, enter the commands:

### Initialize the staff information in the system with details provided from the csv (employees.csv). Note this sample csv is provided with some sample data. It can be updated to include more data or remove some data but should follow the same format.
	- click on the file icon, and select "employees.csv" from src folder
    - click on initialize staff 
    - check terminal to see whether the staff has been initialized (data will be printed there)
    
    - test cases:
    	click on initialize staff without choosing a file(fail promt appears)
        choose a non csv file (fail prompt appears)
        choose a csv file, but not with incorrectly formatted information (fail prompt appears)

### Initialize the inventory information in the system with details provided from the csv (foodinventory.csv).Note this sample csv is provided with some sample data. It can be updated to include more data or remove some data but should follow the same format.
	- click on the file icon, and select "foodinventory.csv" from src folder
    - click on initialize Inventory 
    - check terminal to see whether the inventory has been initialized (data will be printed there)
    
    - test cases:
    	click on initialize inventory without choosing a file(fail promt appears)
        choose a non csv file (fail prompt appears)
        choose a csv file, but not with incorrectly formatted information (fail prompt appears)    
### Initialize the promo information in the system with details provided from the csv (promos.csv).Note this sample csv is provided with some sample data. It can be updated to include more data or remove some data but should follow the same format.
	- click on the file icon, and select "promos.csv" from src folder
    - click on initialize Coupons 
    - check terminal to see whether the coupon items have been initialized (data will be printed there)
    
    - test cases:
    	click on initialize Coupons without choosing a file(fail promt appears)
        choose a non csv file (fail prompt appears)
        choose a csv file, but not with incorrectly formatted information (fail prompt appears)     
You may now proceed use the application as Manager or Employee.  You can log in with information in the csv files, examples are listed below.  Close the "Get Started" window to exit the program

## Employee Use Case: 

### Log in as an Employee
	- click on "Get Started"
    - choose employee radio button, then press submit
    - To log in as an Employee you can use any of the profiles created by the administrator step
  	
    First Name : Monica
    Last Name : Geller 
    ID : 200110
    password: iknow
    
    - you can check the terminal and see that this profile is of type employee, thus login will be successful
    - if you enter with a manager profile, login will not be successful, example below
    
    First Name : Fahreen 
    Last Name : Bushra
    ID : 100410
    password: computer
    

### Manage Orders
	- this button allows the manager to interact with transactions of the resturant/cafe
    - this is the only option available for employees
    - refer to the "Manager Orders" under "Log in as a Manager" above

## Manager Use Case: 

### Log in as a Manager
	- click on "Get Started"
    - choose manager radio button, then press submit
    - To log in as an Manager you can use any of the profiles created by the administrator step
    - log ins are monitored by IDs, thus only a manager user should be able to log in
    - below we share an example from the CSV file
    - Due to time constraints, the system only checks user type and ID, thus a wrong password will still allow login at this time
  	
    First Name : Fahreen 
    Last Name : Bushra 
    ID : 100410
    password: computer
    
    - you can check the terminal and see that this profile is of type manager, thus login will be successful
    - if you enter with an employee profile, login will not be successful, example below
    
    First Name : Monica 
    Last Name : Geller 
    ID : 200110
    password: iknow
    

### Manage Orders
	- this button allows the manager to interact with transactions of the resturant/cafe
    - the following actions are availaible
    
#### 1) Create New Transaction 
	- this button allows you to create a new transaction
    - enter in the itemName the customer wants to order and the quantity of that item
    - then hit submit
    
    itemName: Tea
    quantity: 2
    
    -test cases:
    	Enter an item not on the menu (failed prompt appears)
        Enter a quantity of item greater than the stock inventory (failed prompt appears)
        Enter a quantity of item that is out of stock (failed prompt appears)

#### 2) Fullfill a Transaction
	- This button allows you to fulfill/ complete a transaction
    - Enter in a transaction id of a pending transaction
    - Then hit submit
    
    Transaction ID: 1
    
    -test cases:
    	Enter an integer that is not an ID of a pending transaction (failed prompt appears)
    
#### 3)See pending Transactions
	- This button allows you to see all the pending transactions
    
#### 4)See Completed Transactions
	- This button allows you to see all the completed transactions
    
#### 5)See All Transactions 
	- This button allows you to see all the transactions that are pending and completed
    
#### 6)See Revenue
	- This button allows you to see the revenue made 

### Manage Staff
	- this button allows the manager to interact with database of employees in the system
    - the staff data can only be managed by managers
    - All actions and their results will be logged in the terminal. Any errors and outputs will be shown in the terminal. 
    - the following actions are available:

#### 1) Add Staff Member
    - you can create a new employee to the system by providing the employee id, firstname, lastname, type of employee (employee or manager) and password
    - the only valid inputs for type is 'employee' and 'manager' in all lowercase letters
    - the example below will create a manager

    id: 1
    FirstName: Kajal
    LastName: Patel
    Type: manager
    password: password

#### 2) Remove Staff Member
    - you can remove a employee in the system by inputting the employee ID
    - recall, that the output will be logged in the terminal if there is an error performing this action
    - the example below will delete the employee with id 1

    employee id: 1

#### 3) See All Managers
    - a list of all staff that are type 'manager' will be outputted to the terminal with their details

#### 4) See All Employees
    - a list of all staff that are type 'employee' will be outputted to the terminal with their details

#### 5) See All Staff
    - all staff employees and manager will be outputted to the terminal with their details

### Manage Menu
	- this button allows the manager to interact with the menu items available from the cafe/restaurant
    - the Menu Items data can only be managed by managers
    - All actions and their results will be logged in the terminal. Any errors and outputs will be shown in the terminal. 
    - the following actions are available:

#### 1) Add new Item to Menu
    - you can create a new item in the system by providing the Name, ItemId, Price, Current Inventory, Minimum Inventory and Ingredients
    - the inventory values must be whole number integers and the price should be a double
    - the minimum inventory indicates the minimum quantity of that item that should be available in the restaurant at all times
    - the example below will add 'egg' as a menu item

    Name: Omlette
    Item ID: 124
    Price: 3.00
    Current Inventory: 200
    Minimum Inventory: 100
    Ingredients: egg

#### 2) Remove an Item from Menu
    - an item can be removed from the system by providing the item's name
    - the example below will remove the item with the name "Omlette"

    Item Name: Omlette

#### 3) Update Menu Item Price
    - an items price can be updated by providing the name of the item and a new price for it
    - the example below will update the price of the item with the name "Omlette" to $12.00

    Item Name: Omlette
    New Price: 12.00

#### 4) View Menu Item 
    - the details of the menu item can be shown by inputting the Item's name
    - the example below will show the details of "Omlette" in the terminal

    Item Name: Omlette

#### 5) See all Menu Items
    - all the menu items available in the cafe will be outputted to the terminal with their details

### Manage Inventory
	- this button allows the manager to manage the inventory/stock levels of menu items of the cafe/restaurant
    - items can be re-ordered from supplies and marked as received as they arrive
    - All actions and their results will be logged in the terminal. Any errors and outputs will be shown in the terminal. 
    - the following actions are availaible

#### 1) View Items in Stock 
    - all the items that are in stock (inventory above 0) will be outputted to the terminal

#### 2) View All items Low in Stock
    - all the items that are available (inventory above 0), but belows its minimum threshold will be outputted to the terminal

#### 3) View All Items Out of stock
    - all the items that are out of stock (inventory is 0) will be outputted to the terminal

#### 4) View Inventory of Specific Item
    - the inventory information of a specific menu item will be outputted to the terminal
    - the item name should be provide as input
    - the following example will output the information for the menu item "Omlette":

    Item Name: Omlette

#### 5) Cancel Inventory Order  
    - a previously created order can be cancelled be inputting the order id as long as its pending
    - any errors will be outputted to the terminal
    - the following example will delete the order with order id 1

    Order Id: 1

#### 6) Send Inventory Order  
    - an inventory order can be created by inputting the item name and the quantity
    - any errors will be outputted to the terminal
    - the following example will order 50 Omlettes

    Item Name: Omlette
    Quantity: 10

#### 7) Receive Inventory Order  
    - an inventory order can be marked as received by its order Id
    - any errors will be outputted to the terminal
    - the following example will mark the order with id 1 as received

    Order Id: 1

#### 8) Print All Orders  
    - all pending, received and cancelled orders will be outputted to the terminal
