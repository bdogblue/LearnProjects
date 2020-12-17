



//******************************************************************************
// CPSC 230 MW Fall 2019 Lab # 2B
// Brogan Ehnis
// Compares to tests
//******************************************************************************


/* Algorithim

Vars

creat varibles for the users letter and the other persons letter
also creat varibles for the users grade and the other persons grade

Input

begin loop here

then ask for your grade and get it and ask for their grade and get it

Comp

convert the grades to a single digit

then set the letters according to the grades received

Output

then output according to the letters received

at the end ask the user if he want to continue
if so the end the loop here otherwise go back to the begining

*/

#include <iostream>;

using namespace std;

int main()
{

	//vars

	char yourletter, theirletter;
	int yourgrade, theirgrade;

	while (true)
	{

        //input

        cout << "Enter your grade percentage... ";
        cin >> yourgrade;
        cout << endl;

        cout << "Enter their grade percentage... ";
        cin >> theirgrade;
        cout << endl;

        //comp

        //convert to single digit
        yourgrade /= 10;
        theirgrade /= 10;

        // sets letters
        if (yourgrade == 9 || yourgrade == 10)
        {
            yourletter = 'A';
        }
        else if (yourgrade == 8)
        {
            yourletter = 'B';
        }
        else if (yourgrade == 7)
        {
            yourletter = 'C';
        }
        else if (yourgrade == 6)
        {
            yourletter = 'D';
        }
        else if (yourgrade >= 0 && yourgrade <= 5)
        {
            yourletter = 'F';
        }
        else
        {
            yourletter = 'E';
        }

        // sets letters
        if (theirgrade == 9 || theirgrade == 10)
        {
            theirletter = 'A';
        }
        else if (theirgrade == 8)
        {
            theirletter = 'B';
        }
        else if (theirgrade == 7)
        {
            theirletter = 'C';
        }
        else if (theirgrade == 6)
        {
            theirletter = 'D';
        }
        else if (theirgrade >= 0 && theirgrade <= 5)
        {
            theirletter = 'F';
        }
        else
        {
            theirletter = 'E';
        }

        //output

        if (yourletter == 'E' || theirletter == 'E')
        {
            cout << "Invalid input data, cannot determine who did better in the test!" << endl;
            return 1;
        }
        else if (yourletter < theirletter)
        {
            cout << "You did better in the test, you need to help your partner" << endl;
        }
        else if (yourletter > theirletter)
        {
            cout << "Your partner did better in the test, he needs to help you" << endl;
        }

        //checks ties
        else if (yourletter == 'A'|| yourletter == 'B')
        {
            cout << "Both did very good, congratulations!" << endl;
        }
        else if (yourletter == 'C')
        {
            cout << "Not bad but both could be better" << endl;
        }
        else if (yourletter == 'D')
        {
            cout << "Both should improve to avoid seeing me again next semester!" << endl;
        }
        else if (yourletter == 'F')
        {
            cout << "Have you considered another major?" << endl;
        }

        cout << "Your grade is " << yourletter << endl;
        cout << "Their grade is " << theirletter << endl;
        cout << endl;

        char answer;
        cout << "Would you like to continue? (y/n)" << endl;
        cin >> answer;
        if (answer == 'n')
            break;
	}

	return 0;


}
