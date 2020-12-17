
//***********************************************************************************
// CPSC 230 MW Fall 2019 Homework # 3
// Brogan Ehnis
// Swords and Monsters Game
//**********************************************************************************

/*

(Algorithm)

//Variables

Use user_name for the name of the user
Use weaponChoice to store the weapon the user chooses
Use weaponPower to store the power of the weapon
Use playerHealth for the Health points of the player
Use monsterHealth for the health points of the monster
Use win store whether the player beats the monster of not
Use endStatement for the final message

//Input

Ask for the player's name and get the name

//Computation

Set win to true

Generate starting health for the player
Generate the starting health for the monster

Start for loop that will run five times

	Print out the weapons and the player's health and get the choice from the player

	Then check the weapon that was chosen and had that power to weaponPower

	If the player’s health plus the weapon power is more than the monster’s health

        Then print that the player as defeated the monster with the weapon
        Then add to the monsters health
        Then add to the player's health

Otherwise

	Set win to false
	end for loop

Check if win is false
	Set endStatment to the message name you were lost in the pit of despair
Otherwise
Set endStatment to the message you have made it out alive with this health

//Output

Print out the end statment

*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>

using namespace std;

int main()
{

srand(time(NULL));

//varibles

int weaponPower, playerHealth, monsterHealth;
string user_name, endStatement, weaponName;
char weaponChoice;
bool win;

//input

cout << "What is the name of the hero traped in the pit?" << endl;
cin >> user_name;

//comp

win = true;

//starting health
playerHealth = (rand()%15)+1;
monsterHealth = (rand()%10)+1;

for(int x = 5; x >= 0; x--)
{
    cout << "A monster aproches " << user_name << " from out of the darkness." << endl;
    cout << user_name << " has " << playerHealth << " HP" << endl;
    cout << "Choose a weapon to attack: " << endl;
    cout << " A = Long Stick" << endl;
    cout << " B = Fists" << endl;
    cout << " C = Dagger" << endl;
    cout << " D = Torch" << endl;

    cin >> weaponChoice;
    weaponChoice = toupper(weaponChoice);


    //adds power and name to the choice made
    switch(weaponChoice)
    {
    case 'A' :
        weaponPower = 6;
        weaponName = "Long Stick";
        break;
    case 'B' :
        weaponPower = 2;
        weaponName = "Fists";
        break;
    case 'C' :
        weaponPower = 5;
        weaponName = "Dagger";
        break;
    case 'D' :
        weaponPower = 4;
        weaponName = "Torch";
        break;
    default :
        weaponPower = 0;
        weaponName = "Nothing";
    }

    cout << (playerHealth + weaponPower) << endl;
    cout << monsterHealth << endl;

    //desides who wins
    if ((playerHealth + weaponPower) >= monsterHealth)
    {
        endStatement = user_name + " has done well and defeated this moster with " + weaponName + " and moves forward.";

        //buffs the player and the new monster
        playerHealth += (rand()%5)+1;
        monsterHealth += (rand()%5)+3;
    }
    else
    {
        win = false;
        x = -1;
        endStatement = user_name + " has been defeated by the monster.";
    }

    cout << endStatement << endl;
}

if (win == false)
{
    endStatement = " was lost in the pit of despair.";
}
else
{
    endStatement = " made it out of the pit alive.";
}

//output

cout << user_name << endStatement;

return 0;

}











