// Spider Solitaire (1 Suit)
// Brogan Ehnis

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

//Print functions
void printBoard(int wStacks, int cType[], bool cVis[], int cPos[52][2]);
void printCard(int xPos, int yPos, int cType[], bool cVis[], int cPos[52][2]);
void printRow(int rPos, int cType[], bool cVis[], int cPos[52][2]);

//genrates starting board
void newBoard(bool cVis[], int cPos[52][2], int& wStacks);
void setEndCsVis(bool cVis[], int cPos[52][2]);

//intraction
void moveCard(int card, int newXPos, int newYPos, int cPos[52][2]);
bool createStack(int xPos, int yPos, int stack_[], int cType[], bool cVis[], int cPos[52][2]);
bool moveStack(int xPos, int yPos, int stack_[], int cType[], int cPos[52][2]);
void dealDeck(int cPos[52][2]);

int converAnswer(string choice);

void userAction(bool cVis[], int cType[], int cPos[52][2]);

void checkBoard(int& wStacks, int cType[], bool cVis[], int cPos[52][2]);

//base check tools
bool checkPos(int xPos, int yPos, int cPos[52][2]);
bool checkPos(int xPos, int yPos, int& card, int cPos[52][2]);
int checkType(int xPos, int yPos, int cPos[52][2], int cType[]);
bool checkVis(int xPos, int yPos, int cPos[52][2], bool cVis[]);

void openScreen();

int main()
{
	// vars
	bool running = true;
	int winstacks;
	bool win = false;
	string user_name;
	char choice;

	//Card Array Varibles
	int card_Pos[52][2];
	int card_Types[52] = { 1,1,1,1,2,2,2,2,3,3,3,3,4,4,4,4,5,5,5,5,6,6,6,6,7,7,7,7,8,8,8,8,
							9,9,9,9,10,10,10,10,11,11,11,11,12,12,12,12,13,13,13,13 };
	bool card_Vis[52];

	// Prints opening screen for the player
	openScreen();

	cout << "Enter your name to begin: ";
	cin >> user_name;

	//sets up opening board
	newBoard(card_Vis, card_Pos, winstacks);

	cout << "Hello " << user_name << "!" << endl;

	while (running) //main game loop
	{

		if(winstacks >= 4)
		{
			cout << endl;
			cout << "   ********************************************************" << endl;
			cout << "   * Congradulations " << user_name << "! You have won the game " << endl;
			cout << "   ********************************************************" << endl;
			cout << endl;
			
			cout << "Would you like to play again?: ";
			cin >> choice;
			
			choice = tolower(choice);

			if(choice == 'y')
			{
				newBoard(card_Vis, card_Pos, winstacks);
			}
			else
			{
				running = false;
			}
			
			
		}
		else
		{
			setEndCsVis(card_Vis, card_Pos);
			
			printBoard(winstacks, card_Types, card_Vis, card_Pos);

			cout << "Would you like to (M)ove a card or stack, (R)eset or (P)rint the crruent Board, (D)eal out new cards, or (Q)uit." << endl;
			cin >> choice;

			choice = tolower(choice);

			switch (choice)
			{
			case 'm':
				userAction(card_Vis, card_Types, card_Pos);
				break;
			case 'r':
				newBoard(card_Vis, card_Pos, winstacks);
				break;
			case 'p':
				printBoard(winstacks, card_Types, card_Vis, card_Pos);
				break;
			case 'd':
				dealDeck(card_Pos);
				break;
			case 'q':
				running = false;
				break;
			default:
				cout << "Error. Please try again!" << endl;
				break;
			}
		}
		
	}




	return 0;
}

void printBoard(int wStacks, int cType[], bool cVis[], int cPos[52][2])
{
	string wStack;

	//check win stacks
	switch (wStacks)
	{
	case 0:
		wStack = "|  |  |  |  |  |  |  |";
		break;
	case 1:
		wStack = "|A#|  |  |  |  |  |  |";
		break;
	case 2:
		wStack = "|A#|  |A#|  |  |  |  |";
		break;
	case 3:
		wStack = "|A#|  |A#|  |A#|  |  |";
		break;
	case 4:
		wStack = "|A#|  |A#|  |A#|  |A#|";
		break;
	default:
		wStack = "|  |  |  |  |  |  |  |";
		break;
	}

	cout << endl;
	cout << "        ______________________________________________ " << endl;
	cout << "       |       __          __    __    __    __       |" << endl;
	cout << "       |      |  |        " << wStack << "      |" << endl;
	cout << "       |      |__|        |__|  |__|  |__|  |__|      |" << endl;
	cout << "       |       __    __    __    __    __    __       |" << endl;

	for (int i = 0; i < 21; i++)
	{
		//prints row on the board with the given number
		printRow(i, cType, cVis, cPos);
		cout << endl;
	}

	cout << "       |______________________________________________|" << endl;
	cout << endl;


	return;
}

//prints a single card
void printCard(int xPos, int yPos, int cType[], bool cVis[], int cPos[52][2])
{
	int card;

	//check if there is a card in the pos and if so get the card number
	if (checkPos(xPos, yPos, card, cPos))
	{
		//check if the card is vissible
		if (cVis[card] == true)
		{
			// check type at the card given and print by type
			if (cType[card] < 10 && cType[card] > 1)
			{
				cout << "|" << cType[card] << "#|";
			}
			else if (cType[card] == 10)
			{
				cout << "|10|";
			}
			else if (cType[card] == 11)
			{
				cout << "|J#|";
			}
			else if (cType[card] == 12)
			{
				cout << "|Q#|";
			}
			else if (cType[card] == 13)
			{
				cout << "|K#|";
			}
			else if (cType[card] == 1)
			{
				cout << "|A#|";
			}
		}
		else
		{

			//check for card below
			if (checkPos(xPos, yPos + 1, cPos))
			{
				// print empty card with line if there is a card below
				cout << "|__|";
			}
			else
			{
				cout << "|  |";
			}
		}
	}
	else
	{
		//not card was found in this pos

		//check for card above
		if (checkPos(xPos, yPos - 1, cPos))
		{
			//prints cap on the card
			cout << "|__|";
		}
		else
		{
			cout << "    ";
		}
	}

	return;
}

//prints row on the board
void printRow(int rPos, int cType[], bool cVis[], int cPos[52][2])
{
	cout << "       |     ";
	for (int i = 0; i < 6; i++)
	{
		cout << " ";
		printCard(i, rPos, cType, cVis, cPos);
		cout << " ";
	}
	cout << "     |";
}

//genrates starting board
void newBoard(bool cVis[], int cPos[52][2], int& wStacks)
{
	srand(time(NULL));

	wStacks = 0;
	int randCard;
	bool look;

	//set up cards vis to all false
	for (int i = 0; i < 52; i++)
	{
		cVis[i] = false;
	}

	//set up cards in deck positions
	for (int j = 0; j < 52; j++)
	{
		cPos[j][0] = -5;
		cPos[j][1] = -5;
	}

	//set up cards in the starting positions on the board

	//loop through positions cols 0 - 5 rows 0 - 4
	for (int x = 0; x < 6; x++)
	{
		for (int y = 0; y < 5; y++)
		{
			look = true;

			while (look)
			{
				//choose random card out of the 52
				randCard = rand() % 52;

				//check if the card is at the position on the board
				if (cPos[randCard][0] == -5)
				{
					//if no then set the card to the new position on the board
					cPos[randCard][0] = x;
					cPos[randCard][1] = y;

					look = false;
				}
			}
		}
	}

	//loop through positions cols 0 - 2 row 5
	for (int a = 0; a < 3; a++)
	{
		look = true;

		while (look)
		{
			//choose random card out of the 52
			randCard = rand() % 52;

			//check if the card is at the position on the board
			if (cPos[randCard][0] == -5)
			{
				//if no then set the card to the new position on the board
				cPos[randCard][0] = a;
				cPos[randCard][1] = 5;

				look = false;
			}
		}
	}
	setEndCsVis(cVis, cPos);
}

//sets the cards on the end of the stacks to be vissible
void setEndCsVis(bool cVis[], int cPos[52][2])
{
	int card;

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 21; j++)
		{
			//checks card below
			if (checkPos(i, j, card, cPos) == true && checkPos(i, j + 1, cPos) == false)
			{
				cVis[card] = true;
			}
		}
	}

	return;
}

//sets card to new pos if there is no card there
void moveCard(int card, int newXPos, int newYPos, int cPos[52][2])
{
	if (!checkPos(newXPos, newYPos, cPos))
	{
		cPos[card][0] = newXPos;
		cPos[card][1] = newYPos;
	}

	return;
}

//creates a valid stack of cards
bool createStack(int xPos, int yPos, int stack_[], int cType[], bool cVis[], int cPos[52][2])
{
	int card, stackPos = 0, rowDown, cardType;
	bool run = true;

	//fill the stack with empty cards
	for (int i = 0; i < 13; i++)
	{
		stack_[i] = -1;
	}

	if (checkPos(xPos, yPos, card, cPos) && checkVis(xPos, yPos, cPos, cVis))
	{
		//add the first card to array
		stack_[stackPos] = card;
		stackPos++;
		
		rowDown = yPos + 1;

		cardType = checkType(xPos, yPos, cPos, cType);

		//start loop to check the next card below
		while(run)
		{
			//checks if there is a card at this pos 
			if(checkPos(xPos, rowDown, cPos))
			{
				//checks the type of the card bellow
				if(checkType(xPos, rowDown, cPos, cType) == cardType - 1)
				{
					//add the card to array
					stack_[stackPos] = card;
					stackPos++;
					
					//moves the new check type
					cardType--;

					//moves down on the board
					rowDown++;
				}
				else
				{
					return false;

					run = false;
				}
				
			}
			else
			{
				//if not 

				return true;

				run = false;
			}
		}
	}
	else
	{
		return false;
	}

}

//moves a stack of cards to a valid pos
bool moveStack(int newXPos, int newYPos, int stack_[], int cType[], int cPos[52][2])
{
	bool move = false;
	int card, ssize = 0;

	//check the first card can go in the new pos
	//checks if the card above is empty and is a king or if the card is one type above
	if((checkPos(newXPos, newYPos - 1, card, cPos) == false && checkType(cPos[stack_[0]][0], cPos[stack_[0]][1], cPos, cType) == 13 && newYPos == 0) || 
	(checkPos(newXPos, newYPos - 1, card, cPos) == true && checkType(cPos[stack_[0]][0], cPos[stack_[0]][1], cPos, cType) == checkType(newXPos, newYPos - 1, cPos, cType) - 1))
	{
		//gets size of the stack
		for(int i = 0; i < 13; i++)
		{
			if(!(stack_[i] == -1))
			{
				ssize++;
			}
			else
			{
				break;
			}
			
		}
		
		//check the card stack fits on the board
		if((ssize + newYPos) < 21)
		{
			//true then move all the cards to the new pos
			for(int j = 0; j < ssize; j++)
			{
				moveCard(stack_[j], newXPos, newYPos + j, cPos);
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

//deals out the deck of card that are not in the board
void dealDeck(int cPos[52][2])
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 21; j++)
		{
			//checks card below
			if (checkPos(i, j, cPos) == true && checkPos(i, j + 1, cPos) == false)
			{
				for(int c = 0; c < 52; c++)
				{
					if(cPos[c][0] == -5)
					{
						moveCard(c, i, j + 1, cPos);
						break;
					}
				}
				break;
			}
		}
	}
	return;
}

int converAnswer(string choice)
{
	if(choice == "A")
		{
			return 1;
		}
		else if (choice == "2")
		{
			return 2;
		}
		else if (choice == "3")
		{
			return 3;
		}
		else if (choice == "4")
		{
			return 4;
		}
		else if (choice == "5")
		{
			return 5;
		}
		else if (choice == "6")
		{
			return 6;
		}
		else if (choice == "7")
		{
			return 7;
		}
		else if (choice == "8")
		{
			return 8;
		}
		else if (choice == "9")
		{
			return 9;
		}
		else if (choice == "10")
		{
			return 10;
		}
		else if (choice == "J")
		{
			return 11;
		}
		else if (choice == "Q")
		{
			return 12;
		}
		else if (choice == "K")
		{
			return 13;
		}
		else
		{
			return -1;
		}
}

//gets the action from the user on the board
void userAction(bool cVis[], int cType[], int cPos[52][2])
{
	bool run = true;
	string choice;
	int choices[4], stack_[13], cardnum; 
	int check, sPos = 0, card, newchoice;

	while(run)
	{
		cout << "What card would you like to move?: ";
		cin >> choice;

		check = converAnswer(choice);

		if(check == -1)
		{
			cout << "Error. try again" << endl;
		}		
		
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 26; j++)
			{
				if(checkVis(i, j, cPos, cVis) && check == checkType(i, j, cPos, cType) && checkPos(i, j, card, cPos))
				{
					choices[sPos] = card;
					sPos++;

				}
			}
		}
	
		if(sPos == 1)
		{
			if(!createStack(cPos[choices[0]][0], cPos[choices[0]][1], stack_, cType, cVis, cPos))
			{
				cout << "This card or stack cannot be moved" << endl;
			}
			else
			{
				cout << "What card would you like to move to?: ";
				cin >> newchoice;
				
				run = false;
			}
			
	
		}
		else
		{
			cout << "Choose which " << choice << " you would like to move (top to bottom/left to right): ";
			cin >> cardnum;

			if(cardnum >= 0 && cardnum <= sPos)
			{
				if(!createStack(cPos[choices[cardnum]][0], cPos[choices[cardnum]][1], stack_, cType, cVis, cPos))
				{
					cout << "This card or stack cannot be moved" << endl;
				}
				else
				{
					run = false;
				}
				
			}
			else
			{
				cout << "This card is not on the board" << endl;
			}
			
		}
		
	}
	
	return;
}

//****needs testing****
//checks the board for wining stack from 13 to 1
void checkBoard(int& wStacks, int cType[], bool cVis[], int cPos[52][2])
{
	bool val = true, full = false;
	int nexType = 12, stackPos = 0, card;
	int rowDown;
	int stack[13];

	//find a King that is vissible
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			rowDown = j + 1;

			//if so loop down the postions
			if (checkType(i, j, cPos, cType) == 13 && checkVis(i, j, cPos, cVis) && checkPos(i, j, card, cPos))
			{
				//begins the new stack
				stack[stackPos] = card;
				stackPos++;

				while (val)
				{
					//first check if the stack is full
					if (nexType == 0)
					{
						full = true;
					}

					//checks the card under the new card
					if (checkType(i, rowDown, cPos, cType) == nexType && checkVis(i, rowDown, cPos, cVis) == true && checkPos(i, rowDown, card, cPos) == true)
					{
						stack[stackPos] = card;
						stackPos++;

						nexType--;
						rowDown++;
					}
					else
					{
						val = false;
					}

				}
				
				//check if the stack is full of card from 13 to 1
				if (full)
				{
					//add a cout to the win stacks
					wStacks++;
					
					//move the cards off the board
					for (int i = 0; i < 13; i++)
					{
						cPos[stack[i]][0] = -1;
						cPos[stack[i]][1] = -1;
					}
				}
			}
		}
	}
}

//check if there is a card in the pos
bool checkPos(int xPos, int yPos, int cPos[52][2])
{
	bool check = false;

	for (int i = 0; i < 52; i++)
	{
		if (cPos[i][0] == xPos && cPos[i][1] == yPos)
		{
			check = true;
			break;
		}
	}

	return check;
}

//check if there is a card in the pos and if so get the card number
bool checkPos(int xPos, int yPos, int& card, int cPos[52][2])
{
	bool check = false;
	card = 0;

	for (int i = 0; i < 52; i++)
	{
		if (cPos[i][0] == xPos && cPos[i][1] == yPos)
		{
			check = true;
			break;
		}

		card++;
	}

	return check;
}

//checks the type of the card at the position givin or says there is no card
int checkType(int xPos, int yPos, int cPos[52][2], int cType[])
{
	int card;

	if (checkPos(xPos, yPos, card, cPos))
	{
		return cType[card];
	}
	else
	{
		return -1;
	}
}

//checks the visiblity of the card at the givin position
bool checkVis(int xPos, int yPos, int cPos[52][2], bool cVis[])
{
	int card;

	if (checkPos(xPos, yPos, card, cPos))
	{
		return cVis[card];
	}
	else
	{
		return false;
	}
}

void openScreen()
{
	cout << endl;
	cout << " ____________________________________________________________ " << endl;
	cout << "|                                                            |" << endl;
	cout << "|Programmed by                                               |" << endl;
	cout << "|Brogan Ehnis                                                |" << endl;
	cout << "|\t                       \t __________________          |" << endl;
	cout << "|\t      / _ \\         \t|                  |         |" << endl;
	cout << "|\t    \\_\\(_)/_/       \t| Spider Solitaire |         |" << endl;
	cout << "|\t     _//o\\\\_        \t| One Suit         |         |" << endl;
	cout << "|\t      /   \\         \t|__________________|         |" << endl;
	cout << "|\t                                                     |" << endl;
	cout << "|Title screen art by                                         |" << endl;
	cout << "|Max Strandberg                                              |" << endl;
	cout << "|____________________________________________________________|" << endl;
	cout << endl;
}



