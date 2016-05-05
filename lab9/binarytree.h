// Brad Sherman
// Fundamentals of Computing 2
// Lab 9
// Binary Tree Class
//

#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
#include<cmath>
#include"node.h"
#include"ndvector.h"

#ifndef BINARYTREE_H
#define BINARYTREE_H
template <typename T>
class BinaryTree {


	public:
		BinaryTree();
		~BinaryTree();
		void deleteNode( Node<T> * );
		void acceptParent( Node<T>& );
		void print();
		int search( Node<T> *, T );
		Node<T>* getRoot();
		void inorder( Node<T> * );
		void preorder( Node<T> * );
		void postorder( Node<T> * );
		void finalfour();

	private:
		Node<T>* root;
		int treeSize; // This is the n in 2^n
		vector< vector< Node<T> > > Tree;
};
#endif

template <typename T>
BinaryTree<T>::BinaryTree() {
	cout << "Please enter the text file that you would like to get your data from." << endl;
	string infile;
	cin >> infile;

	ifstream myfile(infile.c_str());
	string line;
	vector< pair<T,string> > data;
	string label;
	T val;
	// Read in data
	while( getline(myfile,line) ) {
		istringstream ss(line);
		ss >> val >> label;
		data.push_back(make_pair(val,label));
	}
	treeSize = log2(data.size()) + 1;
	int i,width;
	// Resize 2d vector based on how much data is read in
	Tree.resize(treeSize);
	width = data.size();
	for( i = 0; i < treeSize; i++){
		Tree[i].resize(width);
		width = width / 2;  // Each successive row has half of the nodes as the previous
	}
	// Make base nodes in the vector from the data
	for( i = 0; i < data.size(); i++ )Tree[0][i] = *(new Node<T>(data[i].first,data[i].second));

	// Use pairs of nodes in the base layer to find out which one goes to the next level
	int j;
	for( i = 1; i < treeSize; i++ ){
		for( j = 0; j < Tree[i].size(); j++ ){
			Tree[i][j] = *(new Node<T>);
			Tree[i][j].right = &Tree[i-1][2*j+1];
			Tree[i][j].left = &Tree[i-1][2 * j];
			acceptParent(Tree[i][j]);
		}
	}
	root = &Tree[treeSize-1][Tree[treeSize-1].size()-1];
}

template <typename T>
void BinaryTree<T>::print() {
	int i,j;
	for( i = treeSize-1; i >= 0; i-- ){
		for( j = 0; j < Tree[i].size(); j++ ){
			cout << Tree[i][j].data << " ";
		}
		cout << endl;
	}
}

template <typename T>
Node<T> * BinaryTree<T>::getRoot(){
	return root;
}

template <typename T>
int BinaryTree<T>::search( Node<T> * root, T val ){
	int found = 0;
	// Check to see if current node has matching value
	if(root->getData() == val) {
		found = 1;
		cout << root->getData() << " " << root->getLabel() << endl;
		return found;
	}
	// if the node is a leaf return found
	if( root->getRight() == NULL && root->getLeft() == NULL ) return found;
	// Otherwise search the left and right
	else{
		found = search(root->getLeft(), val);
		// If the value is found after searching the left, we do 
		// not want to change the value of found, so return found
		// if it is one
		if( found == 1 ) return found;
		found = search(root->getRight(), val);
	}
	// if we make it to the end without returning found, then 
	// found is zero, so return it
	return found;
}

template <typename T>
void BinaryTree<T>::acceptParent( Node<T> &parent  ) {
     if( parent.right->data > parent.left->data   ) {
         parent.data = parent.right->data;
         parent.label = parent.right->label;
	 }
     else if( parent.left->data > parent.right->data  ){
         parent.data = parent.left->data;
         parent.label = parent.left->label;   
	 }
     else {
         parent.data = parent.left->data;
         parent.label = parent.left->data;
	 }
 }

template <typename T>
void BinaryTree<T>::inorder(Node<T>* root){
	if( root == NULL ) return;
	inorder(root->getLeft());
	cout << root->getData() << " ";// << endl;
	inorder(root->getRight());
}

template <typename T>
void BinaryTree<T>::preorder(Node<T> * root){
	if( root == NULL  ) return;
	cout << root->getData() << " ";// << endl;
	preorder(root->getLeft());
	preorder(root->getRight());
}

template <typename T>
void BinaryTree<T>::postorder(Node<T> * root){
	if( root == NULL  ) return;
	postorder(root->getLeft());
	postorder(root->getRight());
	cout << root->getData() << " ";// << endl;
}

template <typename T>
void BinaryTree<T>::finalfour(){
	int i;
	for( i = treeSize-3; i < treeSize; i++ ){
		if( i == treeSize-3 ) {
			cout << "Final four: " << endl;
			cout << root->getRight()->getRight()->getLabel() << " vs. " << root->getRight()->getLeft()->getLabel() << endl;
			cout << root->getLeft()->getRight()->getLabel() << " vs. " << root->getLeft()->getLeft()->getLabel() << endl;
		}else if( i == treeSize-2 ){
			cout << "Championship: " << endl;
			cout << root->getRight()->getLabel() << " vs. " << root->getLeft()->getLabel() << endl;
		}else if( i == treeSize-1 ) {
			cout << "Champion: " << endl;
			cout << root->getLabel() << endl;
		}
	}
}

template <typename T>
void BinaryTree<T>::deleteNode( Node<T> * root) {
	deleteNode(root->getRight());
	deleteNode(root->getLeft());
	delete root;
}

template <typename T>
BinaryTree<T>::~BinaryTree(){
	deleteNode(root);
}
