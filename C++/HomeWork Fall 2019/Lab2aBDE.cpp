
/*
CPSC 230 MW Fall 2019  Lab 2A
Brogan Ehnis
Acceleration calculator
*/

/*

varibles
a is acceleration in meters per second
v is velocity in miles per hour
t is time in seconds
MPH2MPS is a constent that contans 1609/3600

input

prompt for veleocity and get veleocity

prompt for time and get time

comp

calculate the formula given a = (1609/3600) * v/t

then round to 2 decimal places

output

display the velocity givin and the seconds

then the acceleration formated to 2 decimal places

*/

#include <iostream>
#include <iomanip>

using namespace std;

const double MPH2MPS = (1609.0 / 3600.0);

int main()
{

	//Varibles

	double a, v, t;

	//Input

	cout << "Acceleration calculator\n";

	cout << "Pease enter the velocity in miles per hour: ";
	cin >> v;
	cout << "\nPlease enter the time in seconds: ";
	cin >> t;
    cout << "\n";

	//Comp

	a = MPH2MPS * (v / t);

                //rounding
	a *= 10;
	a += 0.5;
	int acc = static_cast<int>(a);
	a = static_cast<double>(acc) / 10;

	//Output
    cout << fixed << showpoint;
    cout << setprecision(2);    //formating to 2 decimals
	cout << "The acceleration required by a vehicle to reach a velocity\n of " << v << " Miles per hour in " << t << " seconds is " << a << " meters per second\n";

	return 0;
}
