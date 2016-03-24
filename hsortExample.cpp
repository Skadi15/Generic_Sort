//*****************************************************************************
// Written by Christian Moncada
// Last Modified 23 March 2016
// This is a program to demonstrate a template
// for a heapsort algorithm that works on both
// linked lists as defined here and standard
// arrays
//*****************************************************************************

#include <iostream>
#include <algorithm>
#include <vector>
#include "StudentRecord.h"
#include "LinkedList.h"

using namespace std;

//*****************************************************************************
// Heap class that is capable of sorting objects by simply inserting and 
// then removing from the heap
//*****************************************************************************
template<class T>
class heap {
	vector<T> nodes;
	
	public:
		// Constructors
		heap();
		heap(T&);
	
		void insert(T&);
		T& remove();
		bool isEmpty();
};

// Default constructor
//
template<class T>
heap<T>::heap() {}

// Constructor that takes a reference to an object as the original
// top of the heap. Adds to nodes twice to allow counting by 1
// which simplifies arithmatic later
//
template<class T>
heap<T>::heap(T& newHead) {
	nodes.push_back(T(newHead));
	nodes.push_back(newHead);
}

// Inserts the new node at the end of the heap and then
// reorganizes to maintain the little-end up heap property
//
template<class T>
void heap<T>::insert(T& newNode) {
	nodes.push_back(newNode);
	int current = nodes.size() - 1;
	T temp;
	
	// Swap the child with the parent as long as the child is less
	// than the parent
	while(current > 1 && nodes[current] < nodes[current / 2]) {
		temp = nodes[current];
		
		nodes[current] = nodes[current / 2];
		
		nodes[current / 2] = temp;
		
		current /= 2;
	}
}

// Removes the object at the top of the heap, places the last element
// at the top of the heap, and then reorganizes to maintain the 
// little-end up heap property
//
template<class T>
T& heap<T>::remove() {
	T *rtrnVal = new T(nodes[1]);
	T temp;
	nodes[1] = nodes.back();
	nodes.pop_back();
	int current = 1;
	
	// While the parent is less than a child, swap with the
	// smaller child
	while(2 * current + 1 < nodes.size()) {
		if(nodes.at(current * 2) < nodes.at(current * 2 + 1))
			current *= 2;
		else current = current * 2 + 1;
		
		if(nodes.at(current) < nodes.at(current / 2)) {
			temp = nodes.at(current);
			
			nodes.at(current) = nodes.at(current / 2);
			
			nodes.at(current / 2) = temp;
		}
	}
	
	// If the last node had only one child, check that child
	if(2 * current < nodes.size() && nodes[current] > nodes[current * 2]) {
		temp = nodes[current];
		nodes[current] = nodes[current * 2];
		nodes[current * 2] = temp;
	}
	
	return *rtrnVal;
}

// Predicate function to check if the vector inside the heap (virtually
// the heap) is empty
//
template<class T>
bool heap<T>::isEmpty() {
	return (nodes.size() < 2);
}

// Generic heapsort function that can take in either an array or a
// pointer to a list item
//
template<class T>
void heapsort(T *array, int size) {
	
	heap<T> sorter(*array);
	
	cout << "Before sorting: " << endl;
	cout << array[0] << endl;
	for(int i = 1; i < size; i++) {
		// Operator overloading makes this work
		// See LinkedList.h for details
		cout << (&(*array))[i] << endl;
		sorter.insert((&(*array))[i]);
	}
	
	cout << "After sorting : " << endl;
	while(!sorter.isEmpty())
		cout << sorter.remove() << endl;
}

//*****************************************************************************
// Main
//*****************************************************************************

main() {
	// Initialize the example array
	studentRecord records[] = {studentRecord("Christian", "Moncada", 42),
							 studentRecord("Anthony", "Islas", 100),
							 studentRecord("Alan", "Islas", 10000),
							 studentRecord("Blake", "Thacker", 562),
							 studentRecord("Ryan", "Claus", 25689),
							 studentRecord("Tyler", "Graveline", 356),
							 studentRecord("Jacob", "Berge", 502),
							 studentRecord("Sam", "Siewert", 1),
							 studentRecord("Matt", "Jaffe", 236),
							 studentRecord("Brian", "Davis", 377)};
	
	// Make an example list out of the example array
	listitem<studentRecord> recordList = listitem<studentRecord>::arrayToList(records, 10);
	
	bool loop = true;
	char input;
	
	// Loop while user continues
	while(loop) {
		cout << "List(l), Array(a), or Quit(q): ";
		cin >> input;
		
		switch (input) {
			// Use list
			case 'l':
				// ! is an overloaded operator for listitem
				// It acts as an address of operator
				heapsort(!recordList, 10);
				break;
				
			// Use array
			case 'a':
				heapsort(records, 10);
				break;
				
			// End
			case 'q':
				loop = false;
			default: ;
		}
	}
}