
//*********************************************************************
// CPSC 230		Fall 2019	HW # 7C
// Brogan Ehnis
//looks at best out of a movie list
//****************************************************************************
#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <iomanip>

using namespace std;

int const MAX = 100;

int Search(const long income[]);
void processChoice(const long income[], const string title[], int x);
double average(long long sum, int num);
double round(double num);

int main()
{
	//vars

	long income[MAX];
	string title[MAX];
	int x = 0, quantity = 0;
	long sum = 0;
	double avg;

	ifstream inMovie;
	inMovie.open("TopMovies.txt");

	ofstream outMovie;
	outMovie.open("TheBest.txt");

	if (inMovie.fail())
	{
		cout << "This file didn't open\n";
		exit(1);
	}

	//in

	//reads the file and gets the title and the income
	while (!inMovie.eof())
	{
		getline(inMovie, title[x]);
		inMovie >> income[x];
		inMovie.ignore(1000, '\n');
		x++;
	}

	//out

	//comp

	cout << "These are the movies that made at least 300 million" << endl;

	//prints the movies that made at least 300 mil
	for (int j = 0; j < Search(income, title); j++)
	{
		cout << title[j] << endl;
	}

	//
	processChoice(income, title, x);

	inMovie.close();
	outMovie.close();

	return 0;
}

//searches incomes for highest under 300 mil
int Search(const long income[])
{
	int index = 0;
	bool found = false;
	while ((!found) && (index < MAX))
	{
		if (income[index] < 300000000)
		{
			found = true;
		}
		else
		{
			index++;
		}
	}

	if (found)
	{
		return index;
	}
	else
	{
		return -1;
	}
}

//gets a answer from the user and print to a file
void processChoice(const long income[], const string title[], int x)
{
	int quantity;
	long long sum = 0;
	int avg;

	ofstream outMovie;
	outMovie.open("TheBest.txt");

	cout << "Now we will give you the lest of top movies. Enter the quantity of movies to be processed (0 - " << x << "): ";
	cin >> quantity;

    //get total sum of the income of the movies
	for (int i = 0; i < quantity; i++)
	{
		sum += income[i];
	}

	avg = average(sum, quantity);

	cout << "The average income is " << avg << endl;

	outMovie << "The best " << quantity << " of movies" << endl;
	outMovie << endl;

	outMovie << "Title\t\t\tIncome\t\t\tComment" << endl;

	//prints the movies to the file
	for(int j = 0; j < quantity; j++)
	{
        outMovie << title[j] << "\t\t\t";
        outMovie << income[j] << "\t\t\t";

        if(income[j] > avg)
        {
            outMovie << "above average" << endl;
        }
        else if(income[j] < avg)
        {
            outMovie << "below average" << endl;
        }
        else
        {
            outMovie << "average" << endl;
        }
	}

	cout << "TheBest.txt is ready" << endl;

	outMovie.close();

	return;
}

//return the average of the numbers given
double average(long long sum, int num)
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

//rounds to the tenth
double round(double num)
{
	num *= 10;
	num += 0.5;
	num = static_cast<long>(num);
	num = static_cast<long double>(num);
	num *= 0.1;
	return num;
}
