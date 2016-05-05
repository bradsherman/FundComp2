// Brad Sherman
// Fundamentals of Computing 2
// Lab 9
// Node Class Interface
//

#include<iostream>
using namespace std;
#include<string>

#ifndef NODE_H
#define NODE_H
template <typename T> class BinaryTree;
template <typename T>
class Node {

	friend class BinaryTree<T>;

	public:
		Node();
		Node(const T &, string );
		T getData() const;
		string getLabel() const;
		Node* getRight() const;
		Node* getLeft() const;

	private:
		string label;
		T data;
		Node* right;
		Node* left;
};

template <typename T>
Node<T>::Node(){
	data = 0;
	label = "";
	right = NULL;
	left = NULL;
}

template <typename T>
Node<T>::Node( const T &info, string l ) {
	data = info;
	label = l;
	right = NULL;
	left = NULL;
}

template <typename T>
T Node<T>::getData() const {
	return data;
}

template <typename T>
string Node<T>::getLabel() const {
	return label;
}

template <typename T>
Node<T>* Node<T>::getRight() const {
	return right;
}

template <typename T>
Node<T>* Node<T>::getLeft() const {
	return left;
}
#endif


