#include <iostream>

using namespace std;

void getNumber(int *n);

int main()
{

    int *num;

    int *p1, *p2;
    p1 = new int;
    p2 = new int;
    *p1 = 10;
    *p2 = 20;
    cout << *p1 << " " << *p2 << endl;
    *p1 = *p2;
    cout << *p1 << " " << *p2 << endl;
    *p1 = 30;
    cout << *p1 << " " << *p2 << endl;

    double value = 29.7;

    double *ptr = &value;

    cout << *ptr << endl;

    getNumber(num);

    cout << *num << endl;

    return 0;
}

void getNumber(int *n)
{
    cout << "Enter a number: ";

    cin >> *n;
}
