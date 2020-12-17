/*************************
** Project 1
** Brogan Ehnis
** lists out people sorted and in columns
**************************/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

#include "person.h"

using namespace std;

/***************
** Main driver
****************/

int main()
{
    // **********
    // ** Vars **
    // **********

    string fileName;
    int line = 0, j = 0;
    bool swapp = true;

    //stores the people in the file
    person pr[20];

    //gets and opens the file that will be output to
    ofstream outFile;
    outFile.open("outName.txt");

    // ********
    // ** In **
    // ********

    //get the name of the file
    cout << "Enter the name the file you would like to open: ";
    cin >> fileName;

    //opens that file
    ifstream inFile;
    inFile.open(fileName + ".txt");

    //if it cant find or open the file it fails out
    if (inFile.fail())
    {
        cout << "Could not open file." << endl;
        exit(1);
    }

    //gets the info from the file given
    while (!inFile.eof())
    {
        pr[line].get(inFile);
        line++;
    }

    // **********
    // ** Comp **
    // **********

    //BubbleSort the list

    line--;
    while(swapp)
    {
        swapp = false;
        j++;
        for(int i = 0; i < line - j; i++)
        {
            if(pr[i] > pr[i + 1])
            {
                swap(pr[i], pr[i+1]);
                swapp = true;
            }
        }
    }

    // *********
    // ** Out **
    // *********

    cout << endl;
    cout << "Last           First          Age" << endl;
    cout << "-------------  -------------  ---" << endl;

    //outputs all the people in the array
    for (int i = 0; i < line; i++)
    {
        pr[i].put(cout);
    }

    //outputs all the people in the array into the outfile
    for (int j = 0; j < line; j++)
    {
        pr[j].put(outFile);
    }


    //closes both files
    inFile.close();
    outFile.close();

    return 0;

}

