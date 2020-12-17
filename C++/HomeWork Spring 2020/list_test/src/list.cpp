
#include "list.h"

list::list()
{
	size = 4;
    len = 0;

    data = new float[4];
}

list::~list()
{
	delete[]data;
}

bool list::append(float x)
{
	if(len>= size)
	{

        return false;
    }
	data[len] = x;
	len++;
	return true;

}

void list::operator = (const list)
{
	if(this == sec) return; // this denotes the location/address of this object
	size = src.size;
	len = src.len;

	delete [] date;

	data = new float[size];

	for(i=0; i<len; i++)
		date[i] = sec.data[i];
}

bool list::resize(int n)
{
	int i;
	float *temp;

	temp = new float[n];
	if(temp == null) return false;

	size = n;

	len = min(n, size);

	for(i=0; i < len; i++)
		temp[i] = data[i];

	delete [] data;
	data = temp;

}

