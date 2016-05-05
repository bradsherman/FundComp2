all: main driver compDriver orders

orders: orders.o package.o overnight.o twodaypackage.o
	g++ orders.o package.o overnight.o twodaypackage.o -o orders
orders.o: orders.cpp
	g++ -c orders.cpp
compDriver: compDriver.o bankaccount.o boatloan.o
	g++ compDriver.o bankaccount.o boatloan.o -o compDriver 
compDriver.o: compDriver.cpp
	g++ -c compDriver.cpp	
main: main.o bankaccount.o boatloan.o creditcard.o
	g++ main.o bankaccount.o boatloan.o creditcard.o -o main
main.o: main.cpp
	g++ -c main.cpp
bankaccount.o: bankaccount.cpp bankaccount.h
	g++ -c bankaccount.cpp
boatloan.o: boatloan.cpp boatloan.h
	g++ -c boatloan.cpp
creditcard.o: creditcard.cpp creditcard.h
	g++ -c creditcard.cpp
driver: driver.o package.o overnight.o twodaypackage.o
	g++ driver.o package.o overnight.o twodaypackage.o -o driver
driver.o: driver.cpp
	g++ -c driver.cpp
package.o: package.cpp package.h
	g++ -c package.cpp
overnight.o: overnight.cpp overnight.h
	g++ -c overnight.cpp
twodaypackage.o: twodaypackage.cpp twodaypackage.h
	g++ -c twodaypackage.cpp
clean:
	rm -f *.o main driver compDriver orders
