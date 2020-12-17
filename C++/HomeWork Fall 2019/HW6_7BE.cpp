
//*********************************************************************
// CPSC 230	    Fall 2019     HW # 6-7
// Brogan Ehnis
// gets grades from list and gets the sum and average
//****************************************************************************
#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <iomanip>

using namespace std;

int const MAX = 600;

double average(int sum, int num);
double round(double num);

int main()
{
	//vars

	string name[MAX];
	int grade[MAX];
	int quantity=0, x=0, sum=0;
	double avg;

	ifstream inFile;
	inFile.open("data7.txt");

	ofstream outFile;
	outFile.open("results.txt");

	if (inFile.fail())
	{
		cout << "This file didn't open\n";
		exit(1);
	}

	//in

	while (!inFile.eof())
	{
		inFile >> name[x];
		inFile >> grade[x];
		x++;
	}

	cout << "Enter quantity of grades to be processed (0 – " << x << "):  ";
	cin >> quantity;

	for (int i = 0; i < x; i++)
	{
		sum += grade[i];
	}

	//comp

	avg = average(sum, quantity);

	//out

    outFile << "Name\tGrade\tComment"<< endl;
    for (int j = 0; j < quantity; j++)
    {
        outFile << name[j] << "\t";
        outFile << grade[j] << "\t";

        if (grade[j] > avg)
        {
            outFile << "above average" << endl;
        }
        else if (grade[j] < avg)
        {
            outFile << "below average" << endl;
        }
        else
        {
            outFile << "average" << endl;
        }
    }

    cout << "The average grade is " << avg << endl;

    cout << "results.txt is ready!" << endl;

	inFile.close();
	outFile.close();

	return 0;
}

// gives back the average
double average(int sum, int num)
{
	if (num == 0)
	{
        return 0;
	}
	else
	{
        return round(static_cast<double>(sum) / num);
    }
}


double round(double num)
{
    num *= 10;
	num += 0.5;
	num = static_cast<int>(num);
	num = static_cast<double>(num) / 10;
	return num;
}
