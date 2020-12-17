/***********************************
 * Program 02
 * Written by Mark M Bowman
 ***********************************/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "People.h"

/***********************************
 * Main
 * Test function - DO NOT CHANGE
 ***********************************/
int main()
{ string fname,first,last;
  person temp;
  people p,q,r;
  fstream infile;

// Get file name

  cout << "Enter first file name: ";
  cin >> fname;
  cout << endl;

// Read from file

  infile.open(fname,ios::in);
  while(temp.get(infile)) p.insert(temp);
  infile.close();

// Display list

  cout << "Initial List" << endl << endl;
  p.display(cout);
//  cout << p.length() << " persons" << endl << endl;

// Test find

  temp = person("David","Bowman");
  cout << "Find \"Bowman, David\" = " << p.find(temp) << endl;

  temp = person("Mark","Bowman");
  cout << "Find \"Bowman, Mark\" = " << p.find(temp) << endl;

  temp = person("Carlos","Morales");
  cout << "Find \"Morales, Carlos\" = " << p.find(temp) << endl;

  temp = person("Santa","Claus");
  cout << "Find \"Claus, Santa\" = " << p.find(temp) << endl;
  cout << endl;

// Test remove

  temp = person("Mark","Bowman");
  cout << "Remove \"Bowman, Mark\" = ";
  cout << p.remove(temp) << endl;

  temp = person("David","Bowman");
  cout << "Remove \"Bowman, David\" = ";
  cout << p.remove(temp) << endl;

  temp = person("Santa","Claus");
  cout << "Remove \"Claus, Santa\" = ";
  cout << p.remove(temp) << endl << endl;

// Display updated list

  cout << "Updated List" << endl << endl;
  p.display(cout);

// Get file name

  cout << "Enter second file name: ";
  cin >> fname;
  cout << endl;

// Read from file

  infile.open(fname,ios::in);
  while(temp.get(infile)) q.insert(temp);
  infile.close();

// Display updated list

  cout << "Second List" << endl << endl;
  q.display(cout);

// Add together

  r = p+q;

// Display updated list

  cout << "Combined List" << endl << endl;
  r.display(cout);

  return 0;
}
