/*Author: William Stewart Piteleski
Description: the main driver file uses class syntax version 4 and is responsible for instantiating
and organizing the logic to produce the game board for the Lucas Jump game*/

#include <iostream>
#include "LucasJumpSpecification.h"					//uses specification file as a directory for calling methods 
#include <windows.h>						//for the pretty colors 
#include <conio.h>							//for _getch();
#include <iomanip>							//for formatting like setw()

#define COLOR_DEFAULT	7					//white for blank space 
#define COLOR_RED		12					//red for red token 
#define COLOR_BLUE		9					//blue for blue token 

using namespace std;

//PROTOTYPES
void displayBoard(LucasJump game);			//prints the board and its current status 
void cls(HANDLE hConsole);					//used to clear screen 

//MAIN
int main() {
	LucasJump game;

	displayBoard(game);
	cout << endl;
	cout << "Objective: " << endl;
	cout << "Move all blue tokens into red spaces, and red tokens into blue spaces" << endl << endl;
	cout << "Rules: " << endl;
	cout << "1.) Select a position with either a red or blue token to move." << endl;
	cout << "2.) Blue can only move right and red can only move left" << endl;
	cout << "3.) Tokens can jump one additional token when moving" << endl << endl;
	cout << "Press any key to begin the game..." << endl << endl;

	_getch();								//pause for user input 

	while (!game.isSolved() && !game.isGimp()) {										//when the game is not solved and not in gimp mode 
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		cls(hConsole);
		displayBoard(game);

		cout << endl;
		cout << "Enter the token you would like to move (you cannot move the *): ";

		int position;
		cin >> position;																 //take user position selection and apply it 

		bool moveSuccess = game.move(position);											 //checking if move is legal 

		if (!moveSuccess) {																 //reprompt user if move is not legal to make a legal one 
			cout << "Invalid input, please try again...";
			_getch();
		}
	}

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	cls(hConsole);
	displayBoard(game);

	if (game.isSolved()) {
		cout << "Victory!!! you have solved the Lucas Jump Puzzle" << endl;
	}else {
		cout << "You have run out of possible moves...GAME OVER" << endl;
	}

	_getch();
	return 0;
}

//PROROTYPE DEFINITIONS 
void displayBoard(LucasJump game) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	cout << "_________LUCAS JUMP GAME_________" << endl << endl;
	cout << "Positions:    0  1  2  3  4  5  6" << endl << endl;
	cout << "Board:      ";

	for (int tokenSlot = 0; tokenSlot < 7; tokenSlot++) {				  //iterating through board to identify all existing characters 
		char token = game.getSlot(tokenSlot);

		if (token == 'B') {												  //setting colors to tokkens based on thier character value 
			SetConsoleTextAttribute(hConsole, COLOR_BLUE);
		}else if (token == 'R') {
			SetConsoleTextAttribute(hConsole, COLOR_RED);
		}else {
			SetConsoleTextAttribute(hConsole, COLOR_DEFAULT);
		}

		cout << setw(3) << token ;										  //setw(3) for formatting tokens to align with position numbers 
	}
	SetConsoleTextAttribute(hConsole, COLOR_DEFAULT);
	cout << endl;
}

void cls(HANDLE hConsole) {								   //this is the API definition for clear the screen from Module 3 illustrated by the instructor
	COORD coordScreen = { 0, 0 };    					   //the API sets the cursor in the top left corner of the screen and then prints blanks throughout the whole screen
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