// Brad Sherman
// Fundamentals of Computing 2
// Lab 9
// Main Driver Program
//


#include<iostream>
using namespace std;
#include"ndvector.h"
#include<string>

int main() {

	NDVector<int> myvec;
	myvec.addtoBack(4);
	myvec.addtoBack(3);
	myvec.addtoBack(8);

	cout << "The third element in myvec is: " << myvec[2] << endl;
	cout << "The size of myvec is: " << myvec.getsize() << endl;
	myvec.removefromBack();
	cout << "The size of myvec is: " << myvec.getsize() << endl;
	cout << "The last element of myvec is: " << myvec.getLast() << endl;
	myvec.clear();
	cout << "The size of myvec is: " << myvec.getsize() << endl;
	
	NDVector<int> myvec2(5);
	cout << endl << "The size of myvec2 is: " << myvec2.getsize() << endl;
	myvec2.addtoBack(2);
	myvec2.addtoBack(4);
	myvec2.addtoBack(3);
	myvec2.addtoBack(8);
	myvec2.addtoBack(10);
	// make sure the reallocation works
	myvec2.addtoBack(35);
	cout << "The last element of myvec2 is: " << myvec2.getLast() << endl;
	cout << "The size of myvec2 is: " << myvec2.getsize() << endl;
	
}
