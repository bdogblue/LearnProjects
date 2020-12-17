// person code
// Brogan Ehnis

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>


#include "person.h"

using namespace std;

//Constructor - no parameters
person::person()
{

}

//Constructors - all parameters
person::person(string f, string l, int a)
{
    firstName = f;
    lastName = l;
    age = a;
}

// *********
// ** Get **
// *********
// PRE: Needs string, string, and int in a row from a file
// POST: sets them to vars in the object
bool person::get(istream& in)
{
    in >> firstName;
    in >> lastName;
    in >> age;

    return in.good();
}

// *********
// ** Put **
// *********
// PRE: needs the string string and int set and to be no longer then 15
// POST: outputs them in colum format
void person::put(ostream& out)
{
    out << left << setw(15) << lastName << setw(15) << firstName << setw(15) << age << endl;
}

// ************
// ** Lesser **
// ************
// PRE: requires two person objects to compare with a string lastname and firstname and an int age
// POST: Checks if person is lesser to another person by last to first to age and returns true or false
bool person::operator < (person a)
{
    if(lastName < a.lastName)
    {
        return true;
    }
    else if(lastName == a.lastName)
    {
        if(firstName < a.firstName)
        {
            return true;
        }
        else if(firstName == a.firstName)
        {
            if(age < a.age)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

// *************
// ** Greater **
// *************
// PRE: requires two person objects to compare with a string lastname and firstname and an int age
// POST: Checks if person is greater to another person by last to first to age and returns true or false
bool person::operator > (person a)
{
    if(lastName > a.lastName)
    {
        return true;
    }
    else if(lastName == a.lastName)
    {
        if(firstName > a.firstName)
        {
            return true;
        }
        else if(firstName == a.firstName)
        {
            if(age > a.age)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

// ***********
// ** equal **
// ***********
// PRE: requires two person objects to compare with a string lastname and firstname and an int age
// POST: Checks if person is equal to another person by last to first to age and returns true or false
bool person::operator == (person a)
{
    if(lastName == a.lastName)
    {
        if(firstName == a.firstName)
        {
            if (age == a.age)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}
