//*****************************************************************************
// Written by Christian Moncada
// Last Modified 23 March 2016
// Header file for the student record class
//*****************************************************************************

#ifndef STURECORD_H
#define STURECORD_H

#include <iostream>
#include <string>

// Class representing a student record
//
class studentRecord {
	std::string firstName, lastName;
	int IDnum;
	
	public:
		studentRecord();
		studentRecord(std::string, std::string, int);
	
		bool operator==(const studentRecord&);
		bool operator<(const studentRecord&);
		bool operator>(const studentRecord&);

		friend std::ostream& operator<<(std::ostream&, const studentRecord&);
};

#endif