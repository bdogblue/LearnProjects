#include <iostream>
using namespace std;

#include "Box.h"

/**************************************
 * Constructor - no parameters
 **************************************/
box::box()
{ cout << "Box " << this << " created\n";
  height = 0;
  width = 0;
}

/**************************************
 * Constructor - all parameters
 **************************************/
box::box(int h,int w)
{ cout << "Box " << this << " created\n";
  height = h;
  width = w;
}

/**************************************
 * Destructor - optional
 **************************************/
box::~box()
{ cout << "Box " << this << " destroyed\n";
}

/**************************************
 * Get
 **************************************/
bool box::get(istream &in)
{ in >> height;
  in >> width;
  return in.good();
}

/**************************************
 * Put
 **************************************/
void box::put(ostream &out)
{
	//if (this->get(&out))
	{
		out << height;
		out << " X ";
		out << width << endl;
	}
	return;
}