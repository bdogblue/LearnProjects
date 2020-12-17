/*
    (Algorithm)

    Varibles

    Use win to store if they won or not

    Use guess to store the guess that make

    Use trys to store the number of time the loop will run

    use  rand_num for the random number for the game

    use user_name for the name of the user

    Input

    prompt for name
        get name

    Comp

    Set trys to 5
    Set win to false

    get random number between 1 and 50 for rand_num

    print make 5 guesses at the random number

    begin loop while trys is more than 0

        prompt for guess
            get guess

        if guess is equal to rand_num

            set trys to less than 0
            Set win to true

        Otherwise if guess is less than rand_num

            print your guess is less than the number try again

            take one from trys

            return to begining of loop

        Otherwise if guess is more than rand_num

            print you guess is more than the number try again

            take one from trys

            return to begining of loop

    Output

    if win is true

print congratulations to the user_name

    otherwise

        print you ran out of trys

*/
//***************************************************************************
// CPSC 230 Fall 2019 Homework # 2
// Brogan Ehnis
// number guessing game
//***************************************************************************

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int main()
{

    srand(time(NULL));

    //vars
    int guess, trys, rand_num;
    string user_name;
    bool win;

    //title card
    cout << "Guess a number in five trys" << endl;
    cout << endl;

    //input
    cout << "Enter your user name." << endl;
    cin >> user_name;

    //comp

    trys = 5;
    win = false;

    //gets random number
    rand_num = (rand()%50)+1;

    cout << rand_num << endl;
    while(trys > 0)
    {
        cout << "Enter your guess." << endl;
        cin >> guess;

        if (guess == rand_num)
        {
            trys = 0;
            win = true;
        }
        else if (guess < rand_num)
        {
            cout << "Your guess is less than the number, try again." << endl;
            trys--;
        }
        else if (guess > rand_num)
        {
            cout << "Your guess is more than the number, try again." << endl;
            trys--;
        }
        else
        {
            cout << "Error, try again." << endl;
        }
    }

    //output

    if (win == true)
    {
        cout << endl;
        cout << "Congratulations " << user_name << " you won!" << endl;
    }
    else
    {
        cout << endl;
        cout << "You ran out of trys, Game Over" << endl;
    }

    return 0;

}

