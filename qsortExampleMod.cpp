//*****************************************************************************
// Written by Christian Moncada
// Last Modified 23 March 2016
// This is a program to demonstrate a template
// for a quicksort algorithm that works on both
// linked lists as defined here and standard
// arrays
//*****************************************************************************

using namespace std;

#include <algorithm>	// For standard swap function
#include <iostream>		
#include "StudentRecord.h"
#include "LinkedList.h"

//*****************************************************************************
// Quicksort functions
//*****************************************************************************

// Swap function for list item objects. All other types use the swap function
// from the included algorithm class. This function only swaps the data contained
// by the items to preserve the object order while changing data order
//
template<class T>
void swap(listitem<T>& a, listitem<T>& b) {
	listitem<T> temp(a.data, a.next);
	a.data = b.data;
	b.data = temp.data;
}

// Partitions the array/list into two sections with all things less than the
// end object before the object and all things greater than the end object 
// after the object. Recursively called on the partitions until sorted
//
template<class T>
int partition(T& array, int start, int end) {
	T pivotVal = array[end];
	int pivotPos = start;

	for(int pos = start; pos < end; pos++) {
		if(array[pos] < *pivotVal) {
			swap(array[pivotPos], array[pos]);
			pivotPos++;
		}
	}
	swap(array[pivotPos], array[end]);
	return pivotPos;
}

// Sorts the array/list from element start to element end by recursively
// calling itself with smaller regions until array/list is sorted
//
template<class T>
void quicksort(T& array, int start, int end) {
	if(start < end) {
		int p = partition(array, start, end);
		quicksort(array, start, p - 1);
		quicksort(array, p + 1, end);
	}
}

//*****************************************************************************
// Main
//*****************************************************************************

main() {
	
	// Initialize sample array of student records
	studentRecord records[10] = {{.firstName = "Christian", .lastName = "Moncada", .IDnum = 42},
												{.firstName = "Anthony", .lastName = "Islas", .IDnum = 65},
												{.firstName = "Jacob", .lastName = "Berge", .IDnum = 10003},
												{.firstName = "Blake", .lastName = "Thacker", .IDnum = 25},
												{.firstName = "Ryan", .lastName = "Claus", .IDnum = 563},
												{.firstName = "Tyler", .lastName = "Graveline", .IDnum = 245},
												{.firstName = "Alan", .lastName = "Islas", .IDnum = 5642},
												{.firstName = "Sam", .lastName = "Siewert", .IDnum = 2001},
												{.firstName = "Matt", .lastName = "Jaffe", .IDnum = 8653},
												{.firstName = "Brian", .lastName = "Davis", .IDnum = 8650}};
	
	// Make list using student record array
	listitem<studentRecord> recordList = listitem<studentRecord>::arrayToList(records, 10);
	
	bool loop = true;
	char input;
	
	// Loop while user continues. Multiple uses of list or array will result in sorting an already sorted
	// structures. Demonstrates that algorithm works on already sorted structures.
	while(loop) {
		cout << "List(l), Array(a), or Quit(q): ";
		cin >> input;
		
		switch (input) {
			// Use list
			case 'l':
				cout << "List before sorting:\n";
				for(int i = 0; i < 10; i++) {
					cout << recordList[i].data << endl;
				}
						 
				quicksort(recordList, 0, 9);

				cout << "After sorting:\n";
				for(int i = 0; i < 10; i++) {
					cout << recordList[i].data << endl;
				}
				
				break;
				
			// Use array
			case 'a':
				cout << "Array before sorting:\n";
				for(int i = 0; i < 10; i++)
					cout << records[i] << endl;
						 
				quicksort(records, 0, 9);
				
				cout << "After sorting:\n";
				for(int i = 0; i < 10; i++)
					cout << records[i] << endl;
				break;
				
			// End
			case 'q':
				loop = false;
			default: ;
		}
	}
}






