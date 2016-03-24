//*****************************************************************************
// Written by Christian Moncada
// Last Modified 23 March 2016
// Definition file for the student record class
//*****************************************************************************

#include "StudentRecord.h"

// Default constructor with no arguments
//
studentRecord::studentRecord() {
	firstName = "";
	lastName = "";
	IDnum = -1;
}

// Constructor that takes three arguments and initializes all of the fields 
// in the record
studentRecord::studentRecord(std::string newFirst, std::string newLast, int newID) {
	firstName = newFirst;
	lastName = newLast;
	IDnum = newID;
}

// Equivalence operator for student records
// Compares every member within the structure for equivalence
//
bool studentRecord::operator==(const studentRecord& b) {
	return (firstName.compare(b.firstName) == 0 && lastName.compare(b.lastName) == 0 && IDnum == b.IDnum);
}

// Less than operator for student records
// Compares every member within the structure in the order lastName, firstName, then IDnum
// order chosen because it will result in the most humanly useful form
//
bool studentRecord::operator<(const studentRecord& b) {
	int compare = lastName.compare(b.lastName);
	if(compare != 0) return (compare < 0);
	compare = firstName.compare(b.firstName);
	if(compare != 0) return (compare < 0);
	return (IDnum < b.IDnum);
}

// Greater than operator for student records
// Does the same thing as less than but with greater than
//
bool studentRecord::operator>(const studentRecord& b) {
	int compare = lastName.compare(b.lastName);
	if(compare != 0) return (compare > 0);
	compare = firstName.compare(b.firstName);
	if(compare != 0) return (compare > 0);
	return (IDnum > b.IDnum);
}

// Insertion operator for student records into an out stream
// Can be used with any ostream but designed to make a readable output
// to cout
//
std::ostream& operator<<(std::ostream& os, const studentRecord& sr) {
	os << "Name: " << sr.firstName << " " << sr.lastName << std::endl;
	os << "ID: " << sr.IDnum << std::endl;
	return os;
}
