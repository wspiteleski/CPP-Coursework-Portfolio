/*Author: William Stewart Piteleski
Description: This main driver file uses class syntax version 4 and is responsible for istantiated 
an object and methods to produce a scalable sliding tile puzzle game. The driver will ask for input 
from the user to determine the size of the puzzle board to solve*/

#include <iostream>
#include <iomanip>								 //for formatting with function setw()
#include <conio.h>								 //for _getch() function 
#include <windows.h>							 //windows API for color 
#include <ctime>								 //using system clock to seed rand()
#include "SlidingPuzzleSpecification.h"			 //includes the header file for calling on methods specified

// direction codes (part of the slideTile() interface)
#define SLIDE_UP 1								 // pass to slideTile() to trigger UP movement
#define SLIDE_DOWN 2							 // pass to slideTile() to trigger DOWN movement
#define SLIDE_LEFT 3							 // pass to slideTile() to trigger LEFT movement
#define SLIDE_RIGHT 4							 // pass to slideTile() to trigger RIGHT movement
#define UNSET -1								 // used to arbitrarily indicate an undetermined state in a constuct

using namespace std;

//PROTOTYPES
void cls(HANDLE);								 //will handle screen clearing ability 

//MAIN
int main() {
	//DECLARATIONS
	int width = 0;
	int height = 0;

	srand(time(NULL));							 //Seed the Pseudo-Random Number Generator (system clock)

	//DRIVER LOGIC
	while (width < 3) {
		cout << "Please enter the number of columns you would like (at least 3): ";				   //promtping user for width input
		cin >> width;

		if (cin.fail() == true) {																   //handling malformed data 
			cout << "Invalid entry please try again..." << endl;								   //explain invalid character to user 
			cin.clear();																		   //clear out cin flags
			rewind(stdin);															               //purge bad input 
			width = 0;																			   //keep looping width input request until correct entry is given by user  
		}
		else if (width < 3) {
			cout << "Columns must be at least 3..." << endl;									   //explain invalid number to user 
		}
	}

	while (height < 3) {
		cout << "Please enter the number of rows you would like (at least 3): ";				   //promtping user for height input
		cin >> height;

		if (cin.fail() == true) {																   //handling malformed data 
			cout << "Invalid entry please try again..." << endl;								   //explain invalid character to user 
			cin.clear();																		   //clear out cin flags
			rewind(stdin);															               //purge bad input 
			height = 0;																			   //keep looping width input request until correct entry is given by user 
		}
		else if (height < 3) {
			cout << "Rows must be at least 3..." << endl;										   //explain invalid number to user 
		}
	}

	SlidingPuzzle myPuzzle(width, height);											//instantiating the object 

	myPuzzle.PrintBoard();
	cout << endl << "Press any key to begin.";
	_getch();

	myPuzzle.scrambleBoard();

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	while (!myPuzzle.isBoardSolved()) {
		cls(hConsole);
		myPuzzle.PrintBoard();
	

	cout << endl;
	cout << "<W -> UP  :  A -> LEFT  :  S -> DOWN  :  D -> RIGHT  :  Q -> Quit  :>" << endl;
	cout << "Which Way To Slide:" << endl;

	char keyStroke = _getch();
	int directionCode = UNSET;
			
	if (keyStroke == 'q' || keyStroke == 'Q') {									 //allows for an escape sequence from the program without having to hard shutdown 
		cout << endl << "Your are now exiting the game..." << endl << "Come back soon!";
		return 0;
	}

	if (keyStroke == 'w' || keyStroke == 'W') {									 //capturing the keystrokes and setting their value in directionCode for movement 
		directionCode = SLIDE_UP;												 //we are capturing lowercase and uppercase to eliminate a silly end to the program 
	}
	else if (keyStroke == 'a' || keyStroke == 'A') {
		directionCode = SLIDE_LEFT;
	}
	else if (keyStroke == 's' || keyStroke == 'S') {
		directionCode = SLIDE_DOWN;
	}
	else if (keyStroke == 'd' || keyStroke == 'D') {
		directionCode = SLIDE_RIGHT;
	}

	if (directionCode != UNSET) {
		myPuzzle.slideTile(directionCode);
	}
	}

	//WAAAGH (VICTORY)!!!
	cls(hConsole);
	myPuzzle.PrintBoard();
	cout << endl << "CONGRATULATIONS! YOU SOLVED THE PUZZLE!" << endl;
	cout << "Press any key to exit...";
	_getch();
	

	return 0;
}

//DEFINITION FOR PROTOTYPE FUNCTION 
void cls(HANDLE hConsole) {						 //this is the API definition for clear the screen from Module 3 illustrated by the instructor 
	COORD coordScreen = { 0, 0 };    			 //the API sets the cursor in the top left corner of the screen and then prints blanks throughout the whole screen
	BOOL bSuccess;
	DWORD cCharsWritten;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD dwConSize;

	bSuccess = GetConsoleScreenBufferInfo(hConsole, &csbi);
	dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

	bSuccess = FillConsoleOutputCharacter(hConsole, (TCHAR)' ',
		dwConSize, coordScreen, &cCharsWritten);

	bSuccess = GetConsoleScreenBufferInfo(hConsole, &csbi);

	bSuccess = FillConsoleOutputAttribute(hConsole, csbi.wAttributes,
		dwConSize, coordScreen, &cCharsWritten);

	bSuccess = SetConsoleCursorPosition(hConsole, coordScreen);
}