// Brad Sherman
// Fundamentals of Computing 2
// Lab 9
// Binary Tree Driver Program
//

#include<iostream>
using namespace std;
#include<string>
#include<cmath>
#include"node.h"
#include"binarytree.h"

int main(){
	BinaryTree<int> myTree;
	myTree.print();
	cout << endl;
	int found;
	int go = 1;
	while( go ){
		cout << "What value would you like to search for?" << endl;
		int val;
		cin >> val;
		found = myTree.search(myTree.getRoot(),val);
		if( found ) cout << "Found the value." << endl;
		else cout << "Did not find the value." << endl;
		cout << "Continue? (1/0)" << endl;
		cin >> go;
	}
	cout << endl << "The tree in order." << endl;
	myTree.inorder(myTree.getRoot());
	cout << endl << endl << "The tree in preorder." << endl;
	myTree.preorder(myTree.getRoot());
	cout << endl << endl << "The tree in postorder." << endl;
	myTree.postorder(myTree.getRoot());
	cout << endl << endl;
	myTree.finalfour();
}
