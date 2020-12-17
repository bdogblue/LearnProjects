/***********************************
 * Lab 01 Box driver
 * Written by Mark Bowman 09-Nov-06
 * Updated by YOUR NAME HERE
 ***********************************/

#include <iostream>
using namespace std;

#include "Box.h"

/***********************************
 * Main()
 ***********************************/
int main()
{ class box a,b,c;

// Display empty boxes

  cout << "a = "; a.put(cout); cout << endl;
  cout << "b = "; b.put(cout); cout << endl;
  cout << "c = "; c.put(cout); cout << endl;

// Initialize

  a = box(3,5);
  b = box(4,6);

// Display boxes

  cout << "a = "; a.put(cout); cout << endl;
  cout << "b = "; b.put(cout); cout << endl;

  return 0;
}

