/*Author: Willliam Stewart Piteleski
Description: The following program will simulate the classic sliding tile puzzle game
while utilizing imperative programming paradigm, pseudo-random program behavior and
Windows API calls: console color modification and display refreshing / keystroke processing.
This project includes a starter code boiler plate produced by the instructor*/

#include <iostream>
#include <iomanip>

using namespace std;

#include <string.h>				// for strcpy()
#include <conio.h>				// for getche()

#include <windows.h>			// for COLOR!

#define NUM_ROWS		3		// should not be changed for this solution
#define NUM_COLS		3		// should not be changed for this soultion

#define PIVOT -1				// used to mark the pivot spot (blank area) on the puzzle
#define PIVOT_SYMBOL	"*"		// used to show the pivot location when drawing the board

// direction codes (part of the slideTile() interface)
#define SLIDE_UP		1		// pass to slideTile() to trigger UP movement
#define SLIDE_DOWN		2		// pass to slideTile() to trigger DOWN movement
#define SLIDE_LEFT		3		// pass to slideTile() to trigger LEFT movement
#define SLIDE_RIGHT		4		// pass to slideTile() to trigger RIGHT movement

#define UNSET			-1		// used to arbitrarily indicate an undetermined state in a constuct

#define COLOR_DEFAULT	7
#define COLOR_RED		12
#define COLOR_GREEN		10


// PROTOTYPES
void InitializeBoard(int[NUM_ROWS][NUM_COLS]);
void PrintBoard(int[NUM_ROWS][NUM_COLS]);
bool slideTile(int[NUM_ROWS][NUM_COLS], int);
void scrambleMoves(int[NUM_ROWS][NUM_COLS], int);   //added for using number of moves made as the recursion technique 
void scrambleBoard(int[NUM_ROWS][NUM_COLS]);		// depends upon slideTile()
bool isBoardSolved(int[NUM_ROWS][NUM_COLS]);		// indicates if the board is in the SOLVED state
void cls(HANDLE);									//added for screen clearing ability 
bool takeUserMoves(int theBoard[NUM_ROWS][NUM_COLS]);									//added to capture user move input

// DEVELOPMENT EXTRAS
void printTheRainbow();								// A little reminder on how to do color with the Windows API.


int main() {
	// Declarations
	int slidingBoard[NUM_ROWS][NUM_COLS];		// the board that holds the sliding tiles
	char keyStroke = ' ';						// holds the user's keystrokes as they come in
	int directionCode = UNSET;					// used to build a direction code to be sent to slideTile()

	// Seed the Pseudo-Random Number Generator (system clock)
	srand(time(NULL));
	// Driver Logic
	// 1.) This is the part where you show the board, get the moves, process the moves, and re-draw
	//  the board each time something changes.  This is the core logic of the simulation and
	//  none of the problem specific calculations should take place in main().  Instead,
	//  main() should consist of a series of controlled calls to your functions that
	//  orchestrate the top-level behavior of the simulation.
	
	InitializeBoard(slidingBoard);
	PrintBoard(slidingBoard);
	isBoardSolved(slidingBoard);

	cout << "Press any Key to begin..." << endl;
	_getch();

	scrambleBoard(slidingBoard);
	while (!isBoardSolved(slidingBoard)) {												 //this will loop through the provided functions: 
		HANDLE currentConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);					 //actively  clear the board, reprint the board, and take user input 		 
		cls(currentConsoleHandle);														 //until isBoardSolved() reports back that it is solved (true).
		PrintBoard(slidingBoard);
		isBoardSolved(slidingBoard);

		cout << endl;
		cout << "<W -> UP  :  A -> LEFT  :  S -> DOWN  :  D -> RIGHT  :  >" << endl;
		cout << "Which Way To Slide:" << endl;

		takeUserMoves(slidingBoard);
	}

	cout << endl;
	cout << "<W -> UP  :  A -> LEFT  :  S -> DOWN  :  D -> RIGHT  :  >" << endl;
	cout << "Which Way To Slide:" << endl;
	
	// Exit
	_getch();
	return 0;
}
//DEFINITIONS FOR THE PROTOTYPE FUNCTIONS:

void InitializeBoard(int theBoard[NUM_ROWS][NUM_COLS]) {
	/*the following will fill the playing board with 1 - 8 and will use PIVOT 
	to indicate the empty space for the tiles to move to*/

	int counter = 1;

	for (int row = 0; row < NUM_ROWS; row++) {		//this nested loop will iterate through 
		for (int col = 0; col < NUM_COLS; col++) {  //rows and columns to get 1-8
			
			if (row == 2 && col == 2) {
				theBoard[row][col] = PIVOT;         //this will be the empty space (PIVOT)
			}else {
				theBoard[row][col] = counter++;     //this will count 1- 8 
			}	
		}
	}
}
	 
void PrintBoard(int theBoard[NUM_ROWS][NUM_COLS]) {
	/* the following will print the playing board using a nested for loop to iterate through
	rows and columns of the array while checking to see what the appropriate color for each
	character would be based on if it is in the correct / incorrect position or if it is the 
	PIVOT*/
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	cout << right;														    //direction of spacing for aesthetic
	for (int row = 0; row < NUM_ROWS; row++) {
		for (int col = 0; col < NUM_COLS; col++) {

			if (theBoard[row][col] == PIVOT) {						         //locatinig the blank space to insert the '*' character 
				SetConsoleTextAttribute(hConsole, COLOR_DEFAULT);            //setting the color of the '*' to default color (white)                         
				cout << setw(3) << PIVOT_SYMBOL;					         //inserting the '*' character in blank space  with aesthetic spacing (setw())
			}else if (theBoard[row][col] == (row * NUM_COLS) + col + 1){    // the equation will compare what is in each position, to what SHOULD be there to be correct
				SetConsoleTextAttribute(hConsole, COLOR_GREEN);				//if the current number matches what is expected to be preset, the number will turn green
					cout << setw(3) << theBoard[row][col];			   
			}else {
				SetConsoleTextAttribute(hConsole, COLOR_RED);				//if the current number does NOT match what is expected, the number will turn red
				cout << setw(3) << theBoard[row][col];
			}	
		}
		cout << endl;							                            // this will create new row for each iteration of the loop
	}											                             
	SetConsoleTextAttribute(hConsole, COLOR_DEFAULT);						//reset console color to white (this would impact the isBoardSolved message
																		    //as well as the movement directions to the user which should not be color coded 	
}

bool slideTile(int theBoard[NUM_ROWS][NUM_COLS], int slideDirection) {
	/*the following will find the PIVOT to then assess if a tile can move into it lgeally
	(not going beyond the wall / edge case).  We will ensure we are moving a number into the 
	space, not replacing a number with the PIVOT*/
	int pivotRow = -1;														     //setting values to -1 to ensure the program does a search for PIVOT
	int pivotCol = -1;															 //instead of assuming its location.  (0,0 could equal [0][0] in the array)

	for (int row = 0; row < NUM_ROWS; row++) {
		for (int col = 0; col < NUM_COLS; col++) {

			if (theBoard[row][col] == PIVOT) {									 //once the PIVOT is found we will change the values of the delcarations to where 
				pivotRow = row;													 //the PIVOT actually is 
				pivotCol = col;
			}
		}
	}
	
	if (slideDirection == SLIDE_UP) {											 //we are looking for a tile directly below the PIVOT 
		int tileRow = pivotRow + 1;												 // this will bump us to the next row down by adding one
		int tileCol = pivotCol;													 //this will keep us in the same column as we are looking directly below the PIVOT 
	
		if (tileRow < NUM_ROWS) {												 //this will ensure we do not go out of bounds by keeping the value less than 3 (bottom edge case)
			theBoard[pivotRow][pivotCol] = theBoard[tileRow][tileCol];			 //the PIVOT and tile are swapping locations by making PIVOT
			theBoard[tileRow][tileCol] = PIVOT;									 //equal to number and setting PIVOT in the numbers old spot 

			return true;														 //indicate to the program that it was a valid move 
		}

	}else if (slideDirection == SLIDE_DOWN) {
		int tileRow = pivotRow - 1;												 //this will bump us to the previous row up by subtracting one 
		int tileCol = pivotCol;

		if (tileRow >= 0) {														 //this will ensure we dont go out of bounds by keeping the value no less than 0 (top edge case)
			theBoard[pivotRow][pivotCol] = theBoard[tileRow][tileCol];
			theBoard[tileRow][tileCol] = PIVOT;

			return true;
		}
	}else if (slideDirection == SLIDE_LEFT) {									 //we are looking for a tile directly left of the PIVOT
		int tileRow = pivotRow;													 //this will keep us in the same row as we are looking directly to the left of the PIVOT 
		int tileCol = pivotCol - 1;												 //this will bump to the previous column (left) by subtracting one

		if (tileCol >= 0) {														 //this will ensure do not go out of bounds by keeping the value no less than 0 (left edge case)
			theBoard[pivotRow][pivotCol] = theBoard[tileRow][tileCol];
			theBoard[tileRow][tileCol] = PIVOT;

			return true;
		}
	}else if (slideDirection == SLIDE_RIGHT) {
		int tileRow = pivotRow;
		int tileCol = pivotCol + 1;												 //this will bump to the next column (right) by adding one 

		if (tileCol < NUM_COLS){												 //this will ensure do not go out of bounds by keeping the value  less than 3 (right edge case)
			theBoard[pivotRow][pivotCol] = theBoard[tileRow][tileCol];
			theBoard[tileRow][tileCol] = PIVOT;

			return true;
		}
	}

	return false;																 //if none of the above conditions are met than the move is not legal represented by a false return
}

bool takeUserMoves(int theBoard[NUM_ROWS][NUM_COLS]) {
	/*the following will translate the user input of 'W,A,S,D' to the directionCode defined by the instructor,
	and control the active state of multiple inputs from the user until stated by the program that it is no longer needed.
	*/
	char keyStroke = _getch();													 //pausing to wait for user input and then capture user input 
	int directionCode = UNSET;													 //resetting values to UNSET for a fresh start for each input 

	if (keyStroke == 'w' || keyStroke == 'W') {									 //capturing the keystrokes and setting their value in directionCode for movement 
		directionCode = SLIDE_UP;												 //we are capturing lowercase and uppercase to eliminate a silly end to the program 
	}else if (keyStroke == 'a' || keyStroke == 'A') {
		directionCode = SLIDE_LEFT;
	}else if (keyStroke == 's' || keyStroke == 'S') {
		directionCode = SLIDE_DOWN;
	}else if (keyStroke == 'd' || keyStroke == 'D') {
		directionCode = SLIDE_RIGHT;
	}
	
	if (directionCode != UNSET) {												  //this will take the user input and apply it to directionCode, clear the screen, reprint board
		slideTile(theBoard, directionCode);										 //and return a true condition to start the beginning of the function again 
		HANDLE currentCosoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
		cls(currentCosoleHandle);
		PrintBoard(theBoard);
		return true;
	}

	return false;
}


void scrambleBoard(int theBoard[NUM_ROWS][NUM_COLS]) {
	/*the following will scramble the board using a recursive technique
	and using the random number generator seeded in main*/
	cout << endl;
	cout << "Scrambling the tiles..." << endl;
	cout << "Scrambling complete, press any key to begin solving.";
	_getch();
	
	scrambleMoves(theBoard, 10);										       //this will perform 1000 random slides to ensure thorough shuffle
																			   //change this to a smaller number like 30 for an easier solve while testing 

}

void scrambleMoves(int theBoard[NUM_ROWS][NUM_COLS], int moves) {
	if (moves <= 0) {							 //base case, we are couting backwards from number 
		return;									 //of moves wanted (1000).
	}

	int randomSlide = rand() % 4 + 1;		     //achieve one of four random possible directions (+1 because modulo could poptentially equal 0 which we do not want(that would be nothing moving))
	slideTile(theBoard, randomSlide);			 //apply the random move to the board 

	scrambleMoves(theBoard, moves - 1);			 //this is the recursion: recalling the function but with 
												 //a change to the number of moves left by one each time 
												 //it is called on 
}

bool isBoardSolved(int amISolved[NUM_ROWS][NUM_COLS]) {
	/*the following will check against the position of each number to see if it is currently solved or not.
	after checking the condition this will then print out a statement for the user weather isBoardSolved(): 
	is true or false*/
	
	/*the equation(row * NUM_COLS) + col + 1 will be used to check if the correct value is present
	EX for #1: row and col  would be [0][0] because of array, and NUM_COLS is 3 as defined 
	so: (0 * 3) + 0 + 1 = 1*/
	for (int row = 0; row < NUM_ROWS; row++) {
		for (int col = 0; col < NUM_COLS; col++) {

			if (row == 2 && col == 2) {											 //checking the special condition of the PIVOT first  
				if (amISolved[row][col] != PIVOT) {								 //since it is not a numerical value of 1 -8 and returning
					cout << "isBoardSolved(): false" << endl;					 // false if not in the bottom right corner [2][2] (the only way a win coul be achieved);
					return false;
				}
			}
			else if (amISolved[row][col] != (row * NUM_COLS) + col + 1) {		 //checking the numerical value of each position and returning
				cout << "isBoardSolved(): false" << endl;						 //false if not in the correct position (example [0][0] should be 1)
				return false;
			}
		}
	}

	cout << "isBoardSolved(): true" << endl;									 //returning true if the above conditions pass through without 
	return true;																 //meeting false conditions (everything is where it belongs)
}

void cls(HANDLE hConsole) {														 //this is the API definition for clear the screen from Module 3 illustrated by the instructor 
	COORD coordScreen = { 0, 0 };    											 //the API sets the cursor in the top left corner of the screen and then prints blanks throughout the whole screen
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




// EXTRAS
void printTheRainbow() {
	int currentColor = 7;

	// get the handle for the console
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	// exhaustively print the colors
	cout << left;
	for (currentColor = 0; currentColor <= 255; currentColor++) {
		SetConsoleTextAttribute(hConsole, currentColor);
		cout << setw(5) << currentColor << "Look at the pretty COLORS!" << endl;
	}
}

