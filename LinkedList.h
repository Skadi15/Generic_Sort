//*****************************************************************************
// Written by Christian Moncada
// Last Modified 23 March 2016
// Header file for the linked list item class. Includes implementations
// because it is required for the template functions
//*****************************************************************************

#ifndef LISTITEM_H
#define LISTITEM_H

#include <iostream>

// Template list item class to make a linked list with any type of data
//
template<class T>
class listitem {
	public:
		T data;
		listitem<T> *next;
		
		// Constructors
		listitem();
		listitem(T , listitem<T> *);
		
		// Conversion methods
		static listitem<T>& arrayToList(T array[], int);
		void listToArray(T[], int);
		
		// Overloaded operators
		listitem<T>& operator[](int);
		listitem<T>& operator*();
		listitem<T>& operator&();
		listitem<T> * operator!();
		bool operator<(const listitem&);
		bool operator>(const listitem&);
};

// Default constructor with no arguments
//
template<class T>
listitem<T>::listitem(){};

// Constructor that initializes both data and next with arguments
//
template<class T>
listitem<T>::listitem(T newData, listitem<T> *newNext) {
	data = newData;
	next = newNext;
}

// Converts an array of type T to a linked list of type T. Returns a
// reference to the start of the list
//
template<class T>
listitem<T>& listitem<T>::arrayToList(T array[], int size) {
	listitem<T> *start = new listitem(array[0], NULL);
	listitem<T> *holder = start;
	for(int i = 1; i < size; i++) {
		holder->next = new listitem(array[i], NULL);
		holder = holder->next;
	}
	return *start;
}

// Converts a list to an array using the calling object as the first
// element in the array. Takes in an array of type T and size size
// which is the destination array after conversion
//
template<class T>
void listitem<T>::listToArray(T array[], int size) {
	listitem<T> *current = this;
	for(int i = 0; i < size; i++) {
		array[i] = (current->data);
		free(current);
		current = current->next;
	}
}

// Array subscript operator that allows a list item to be accessed
// through another list item in an array like fashion (e.g. item[2]
// will return the item two entries further into the list from item)
//
template<class T>
listitem<T>& listitem<T>::operator[](int idx) {
	listitem<T> *current = this;
	for(int i = 0; i < idx; i++)
		current = current->next;
	return *current;
}

// Overload for dereferencing operator which allows the partition
// function to work with either arrays or list items. This and the
// [] operator allow a list item object to be treated fully like
// an array
template<class T>
listitem<T>& listitem<T>::operator*() {
	return *this;
}

// Overload for the address of operator. This allows the heapsort
// alogrithm to work and does not affect quicksort. This allows
// a dereferenced array to return its base address but a listitem
// to return itself.
//
template<class T>
listitem<T>& listitem<T>::operator&() {
	return *this;
}

// Because address of operator is overloaded, this acts as one
// in its place. Normally these overloads shouldn't be done, but
// this is merely to demonstrate a concept rather than make a
// reusable module.
//
template<class T>
listitem<T> * listitem<T>::operator!() {
	return this;
}

// Less than operator that compares the data within the list items
// to determine precedence
//
template<class T>
bool listitem<T>::operator<(const listitem<T>& b) {
	return data < b.data;
}

// Greater than operator that compares the data within the list itemjs
// to determine precedence
//
template<class T>
bool listitem<T>::operator>(const listitem<T>& b) {
		return data > b.data;
}

// Insertion operators for list item objects into ostreams. Inserts
// the data contained by the list item into the given ostream. Meant
// for use with cout
//
template<class T>
std::ostream& operator<<(std::ostream& os, const listitem<T>& li) {
	os << li.data;
	return os;
}

#endif