// Brad Sherman
// Fundamentals of Computing 2
// Lab 9 
// NDVector Class Interface
//

#ifndef NDVECTOR_H
#define NDVECTOR_H
#include<iostream>
using namespace std;
#include<string>
#include<vector>


template <typename T>
class NDVector{

	public:
		NDVector(int size = 10);
		NDVector(NDVector<T>&);
		T& operator[](int);
		const NDVector<T>& operator=(const NDVector<T> & );
		void addtoBack(T);
		void removefromBack();
		const int getsize();
		T getLast();
		void clear();
		~NDVector();
	private:
		int size;
		T* ndvector;
		int numelements;
};
#endif


template <typename T>
NDVector<T>::NDVector(int n) {
	numelements = 0;
	// make sure it is a positive size
	if( n > 0 ) size = n;
	else size = 10;
	ndvector = new T[size];
}
template <typename T>
NDVector<T>::NDVector( NDVector<T>& vec){
	// copy constructor
	size = vec.size;
	delete[] ndvector;
	ndvector = new T[vec.size];
	ndvector = vec.ndvector;
}

template <typename T>
const NDVector<T>& NDVector<T>::operator=( const NDVector<T>& right  ) {
	if ( &right != this  ) { // avoid self-assignment
		if ( size != right.size  ) {
			delete [] ndvector; // release space
		  	size = right.size; // resize this object
		  	ndvector = new T[ size  ]; // create space for array copy
		} 
		int i;
	    for ( i = 0; i < size; i++  )
	    	ndvector[i] = right.ndvector[i]; // copy array into object
	    } 
	    return (*this); // enables x = y = z
} 
template <typename T>
T& NDVector<T>::operator[](int index) {
	// check to make sure the value has been assigned by the user
	if( index >= size ) cout << "Index out of bounds." << endl; 
	else if( index >= numelements ) cout << "No value there yet." << endl;
	else return ndvector[index];
}

template <typename T>
void NDVector<T>::addtoBack( T valtoadd ) {
	if( numelements == size ) {
		// reallocate space if vector was full
		size = size*2;
		vector<T> temp(size);
		int i;
		for( i = 0; i < numelements; i++ )temp[i] = ndvector[i];
		delete ndvector;
		ndvector = new T[size];
		for( i = 0; i < numelements; i++ ) ndvector[i] = temp[i];
		ndvector[numelements] = valtoadd;
		numelements++;
	}else{
		ndvector[numelements] = valtoadd;
		numelements++;
	}
}

template <typename T>
void NDVector<T>::removefromBack() {
	ndvector[numelements-1] = 0;
	numelements--;
}

template <typename T>
const int NDVector<T>::getsize() {
	return numelements;
}

template <typename T>
T NDVector<T>::getLast() {
	return ndvector[numelements-1];
}

template <typename T>
void NDVector<T>::clear() {
	int i;
	for( i = 0; i < numelements; i++ ) {
		ndvector[i] = 0;
	}
	numelements = 0;
}

template <typename T>
NDVector<T>::~NDVector() {
	delete[] ndvector;
}
