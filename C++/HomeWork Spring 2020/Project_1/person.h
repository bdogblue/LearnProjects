// Person header
// Brogan Ehnis

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>


using namespace std;

class person
{
public:
	person();					 // Constructor
	person(string, string, int); // Contstructor with the names and age
	bool get(istream&);			 // Input
	void put(ostream&);			 // Output
	bool operator < (person);    // Checks if person a is less than b
	bool operator > (person);    // Checks if person a is more than b
	bool operator == (person);	 // Checks if person a is the same as b

private:
	string firstName;
	string lastName;
	int age;
};

