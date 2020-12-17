// Brogan E.
// Profit Counter

#include <iostream>

using namespace std;

int main()
{
	//varibles
	
	double profitDay, profitYear;
	int cases;

	//input

	cout << "How meny cases where sold today?\n";
	cin >> cases;

	//comp
	
	profitDay = cases * 12 * 0.20;
	profitYear = profitDay * 365;
	
	//output

	cout << "The profit for day is... $";
	cout << profitDay;
	cout << "\n";
	cout << "The profit for the upcoming year is... $";
	cout << profitYear;
	cout << "\n";

	return 0;
}

