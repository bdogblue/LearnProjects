#include <iostream>
#include "list.h"

using namespace std;

int main()
{
	int i;
    list a, b;

	a.append(3.14);
	for(i = 0; i < 5; i++)
		b.append(i*3.14);

	cout << b.avg();

	return 0;
}

