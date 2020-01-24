run: src/FrmMain.cpp  src/GTKmm3.cpp  src/OrderManager.cpp src/Order.cpp src/User.cpp src/StaffManager.cpp src/FileLoader.cpp  src/ItemLoader.cpp  src/UserDataLoader.cpp  src/InventoryManager.cpp  src/Price.cpp  src/MenuItem.cpp src/PromoLoader.cpp src/Coupon.cpp  src/CouponManager.cpp src/InventoryManager.cpp src/StockManager.cpp  src/TransactionManager.cpp src/Transaction.cpp
	@echo creating application...
	g++ src/FrmMain.cpp src/GTKmm3.cpp src/OrderManager.cpp src/Order.cpp src/User.cpp src/StaffManager.cpp src/FileLoader.cpp  src/ItemLoader.cpp  src/UserDataLoader.cpp  src/InventoryManager.cpp  src/Price.cpp  src/MenuItem.cpp src/PromoLoader.cpp src/Coupon.cpp  src/CouponManager.cpp src/StockManager.cpp src/TransactionManager.cpp src/Transaction.cpp -o run.out `pkg-config gtkmm-3.0 --cflags --libs`

clean:
	rm *.out
