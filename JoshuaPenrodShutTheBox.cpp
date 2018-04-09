//Josh Penrod
//Shut The Box Sumbission 2
//Due: 1/24/19
//This is a program that simulates a one person game of Shut the Box.

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <ctype.h>
using namespace std;

void displayInstructions( );// displays the game instructions
void generateDiceNumbers( int &randomNum1, int &randomNum2 );// generates random numbers for the "rolled" die
bool checkIfGameWon( int playerBoard[] );// checks if the game is over
void printBoard( int playerBoard[] );// prints the contents of the playerBoard array with an index above 


int main()
{
	srand( time( NULL ) );
	int playerBoard[9] = {0};// the board of nine boxes  
	int answer = -1; //The users decision to see the instructions, to play with the two numbers they rolled or the combined total 
	int die1 = 0; // The number rolled on the first die
	int die2 = 0; // The number rolled on the second die
	int dieTotal = 0; // The number that is the result of the die being added
	int turnTotal = 0; // the number of rolls the player made

	cout << " Welcome to Shut The Box! \n Would you like to learn the rules of the game? \n 1. Yes \n 2. No" << endl;
	cin >> answer;
	cout << endl;

	while (answer >2 || answer < 1 )
	{
		cout << "Please enter a valid answer: " << endl;
		cin >> answer;
		cout << endl;
	}
	if (answer == 1 )
	{
		displayInstructions( );
	}
	
	while (checkIfGameWon( playerBoard ) == false )
	{
		generateDiceNumbers( die1, die2 );
		dieTotal = die1 + die2;
		printBoard( playerBoard );
		if ( dieTotal < 2 || dieTotal > 9 )
		{
			cout << "You will use box " << die1 << " and " << die2 << "." << endl;

			if ( playerBoard[die1 - 1] == 88 )
			{
				playerBoard[die1 - 1] = 0;
			}
			else
			{
				playerBoard[die1 - 1] = 88;
			}
			if ( playerBoard[die2 - 1] == 88 )
			{
				playerBoard[die2 - 1] = 0;
			}
			else
			{
				playerBoard[die2 - 1] = 88;
			}
		}
		else
		{
			cout << "You will use box " << die1 << " and " << die2 << ". Or you can use box " << dieTotal << ". Will you use the sum of your rolls or the individual boxes?" << endl;
			cout << "1. Sum\n2. Individual" << endl;
			cin >> answer;
			while ( answer > 2 || answer < 1  )
			{
				cout << "Please enter a valid answer: " << endl;
				cin >> answer;
			}
			if (answer == 1 )
			{

				if ( playerBoard[dieTotal - 1] == 88 )
				{
					playerBoard[dieTotal - 1] = 0;
				}
				else
				{
					playerBoard[dieTotal - 1] = 88;
				}
			}
			else
			{
				if ( playerBoard[die1 - 1] == 88 )
				{
					playerBoard[die1 - 1] = 0;
				}
				else
				{
					playerBoard[die1 - 1] = 88;
				}
				if ( playerBoard[die2 - 1] == 88 )
				{
					playerBoard[die2 - 1] = 0;
				}
				else
				{
					playerBoard[die2 - 1] = 88;
				}
			}
		}
		turnTotal++;
	}
	printBoard( playerBoard );
	cout << "Congratulations! You finished the game in " << turnTotal << " rolls!";

	cout << endl;
	system( "pause" );
	return 0;
}

/*displayInstructions: This function opens an input file stream, reads the file and displays the instructions, then closes the file stream*/
void displayInstructions( )
{
	string instructions; // string that contains input from instruction file
	ifstream inputFile;
	inputFile.open( "shutTheBoxInstructions.txt" );
	if ( !inputFile )
	{
		cout << "Input Failed, Exiting Program" << endl;
		system( "pause" );
		exit( 1 );
	}
	while ( !inputFile.eof( ) )
	{
		getline( inputFile, instructions );
		cout << instructions << endl;
	}
	inputFile.close( );
}

/*generateDiceNumber: This function generates two random numbers, one for each die.
randomNum1: The variable in the function that die1 is passed by reference to die1
randomNum2: The variable in the function that die2 is passed by reference to die2 */
void generateDiceNumbers( int &randomNum1, int &randomNum2 )
{
	int max = 6;// the max random number that can be generated
	int min = 1;// the minimum random number that can be generated
	randomNum1 = rand( ) % (max - min + 1) + min;
	randomNum2 = rand( ) % (max - min + 1) + min;
}

/*checkIfGameWon: This function returns a true if all boxes have been closed based off of the total in the playerBoard array
int playerBoard: the board of nine boxes */
bool checkIfGameWon(int playerBoard[] )
{
	bool returnVal = false;// The value which means if the game is over
	int boardTotal = 0;// the value of playerBoard array totaled together
	for ( int i = 0; i < 9; i++ )
	{
		boardTotal += playerBoard[i];
	}
	if ( boardTotal == 792 )
	{
		returnVal = true;
	}
	return returnVal;
}

/*printBoard: This function prints the contents of the players board array (in ASCII) with an index of numbers one through nine above the boxes to be opened or closed
 int playerBoard: the board of nine boxes  */
void printBoard( int playerBoard[] )
{
	cout << "-------------------------------------" << endl;
	cout << "| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |" << endl;
	cout << "| " << (char)playerBoard[0] << " | " << (char)playerBoard[1] << " | " << (char)playerBoard[2] << " | " << (char)playerBoard[3] << " | " << (char)playerBoard[4] << " | " << (char)playerBoard[5] << " | " << (char)playerBoard[6] << " | " << (char)playerBoard[7] << " | " << (char)playerBoard[8] << " |" << endl;
	cout << "-------------------------------------" << endl;
}





/*Problems: I didn't have too many problems creating this program but I did make a couple stupid mistakes which just took me looking back over the code to fix.
 For instance I first seeded rand in generateDiceNumbers rather than in main, so the same random numbers were generated multiple times.
 Another silly mistake I made was in the while loop that checked if the user wanted to display the instructions i used the or operator rather than the and operator.*/