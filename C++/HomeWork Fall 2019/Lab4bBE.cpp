
#include <iostream>
using namespace std;

int factorial(int n);


int main()
{

    cout << factorial(9);

    return 0;
}

int factorial(int n)
{
    int product = 2;
    while (n > 0)
    {
        product = n * product;
        n--;
    }

    return product;
}

