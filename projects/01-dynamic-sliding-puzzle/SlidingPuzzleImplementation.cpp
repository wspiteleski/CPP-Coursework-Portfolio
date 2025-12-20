/*Author: William Stewart Piteleski
Description: The implementation file uses class syntax version 4 and is responsible for providing
definitions of the methods for the sliding tile game and its logic */

#include "SlidingPuzzleSpecification.h"
#include <windows.h>												 //windows API to be able to use colors 
#include <iomanip>													 //for formatting settings like setw()
#include <cstdlib>													 //for rand() function for psuedo random moves 
#include <ctime>													 //psuedo random will be genberated using the computer clock 
#include <conio.h>													 //for _getch() function 

#define PIVOT -1													 // used to mark the pivot spot (blank area) on the puzzle
#define PIVOT_SYMBOL "*"											 //used to show the pivot location when drawing the board

// direction codes (part of the slideTile() interface)
#define SLIDE_UP		1											 // pass to slideTile() to trigger UP movement
#define SLIDE_DOWN		2											 // pass to slideTile() to trigger DOWN movement
#define SLIDE_LEFT		3											 // pass to slideTile() to trigger LEFT movement
#define SLIDE_RIGHT		4											 // pass to slideTile() to trigger RIGHT movement
#define UNSET			-1											 // used to arbitrarily indicate an undetermined state in a constuct

#define COLOR_DEFAULT 7												 // white for Pivot location
#define COLOR_RED 12												 //red for wrong incorrect number position 
#define COLOR_GREEN 10												 //green for correct number position 


//CONSTRUCTOR
SlidingPuzzle::SlidingPuzzle() {									 //DEFAULT CONSTRUCTOR 
	numRows = 3;													 //initialized at default row size
	numCols = 3;													 //initialized at default column size 

	ppTheBoard = new int*[numRows];								     //allocating memory foor rows 

	for (int row = 0; row < numRows; row++) {
		ppTheBoard[row] = new int[numCols];							 //allocating memory for columns 
	}

	InitializeBoard();												 //build the board based on default values 
}

SlidingPuzzle::SlidingPuzzle(int width, int height) {				 //USER INPUT CONSTRUCTOR (overloading SlidingPuzzle) 
	numRows = height;												 //initialized numRows to user input height 
	numCols = width;												 //initialized numCols to user input width

	ppTheBoard = new int*[numRows];									 //allocating memory for rows based on user input 

	for (int row = 0; row < numRows; row++) {
		ppTheBoard[row] = new int[numCols];							 //allocating memory for columns based on user input
	}

	InitializeBoard();												 //build the board based on user input values 
}

//DESTRUCTOR
SlidingPuzzle::~SlidingPuzzle() {									 //deallocating memory used by double pointer to prevent memory leak 
	for (int row = 0; row < numRows; row++) {
		delete [] ppTheBoard[row];
	}
	delete [] ppTheBoard;
	ppTheBoard = NULL;												 //resetting double pointer back to null in case called on again 
}

//UTILITY DEFINITIONS FOR BOARD METHODS
void SlidingPuzzle::InitializeBoard() {
/*the following will fill the playing board with specified amount of spaces needed
and will use PIVOT to indicate the empty space for the tiles to move to*/
	int counter = 1;												 

	for (int row = 0; row < numRows; row++) {						 //this nested loop will iterate through 
		for (int col = 0; col < numCols; col++) {					 //rows and columns specified 

			if (row == numRows - 1 && col == numCols - 1) {
				ppTheBoard[row][col] = PIVOT;						 //this will be the empty space (PIVOT)
			}else {
				ppTheBoard[row][col] = counter;						 //this will count to needed amount based on board size
				counter++;
			}
		}
	}
}

void SlidingPuzzle::PrintBoard() {
/* the following will print the playing board using a nested for loop to iterate through
rows and columns of the array while checking to see what the appropriate color for each
character would be based on if it is in the correct / incorrect position or if it is the
PIVOT*/
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	cout << right;														       //direction of spacing for aesthetic
	for (int row = 0; row < numRows; row++) {
		for (int col = 0; col < numCols; col++) {

			if (ppTheBoard[row][col] == PIVOT) {						       //locatinig the blank space to insert the '*' character 
				SetConsoleTextAttribute(hConsole, COLOR_DEFAULT);              //setting the color of the '*' to default color (white)                         
				cout << setw(3) << PIVOT_SYMBOL;					           //inserting the '*' character in blank space  with aesthetic spacing (setw())
			}
			else if (ppTheBoard[row][col] == (row * numCols) + col + 1) {     // the equation will compare what is in each position, to what SHOULD be there to be correct
				SetConsoleTextAttribute(hConsole, COLOR_GREEN);				   //if the current number matches what is expected to be preset, the number will turn green
				cout << setw(3) << ppTheBoard[row][col];
			}
			else {
				SetConsoleTextAttribute(hConsole, COLOR_RED);				   //if the current number does NOT match what is expected, the number will turn red
				cout << setw(3) << ppTheBoard[row][col];
			}
		}
		cout << endl;							                               // this will create new row for each iteration of the loop
	}
	SetConsoleTextAttribute(hConsole, COLOR_DEFAULT);						   //reset console color to white (this would impact the isBoardSolved message
																			   //as well as the movement directions to the user which should not be color coded 	
}

bool SlidingPuzzle::slideTile(int directionCode) {
	/*the following will find the PIVOT to then assess if a tile can move into it lgeally
	(not going beyond the wall / edge case).  We will ensure we are moving a number into the
	space, not replacing a number with the PIVOT*/
	bool moveValid = false;													   //default bool 
	int pivotRow = -1;														   //setting values to -1 to ensure the program does a search for PIVOT
	int pivotCol = -1;														   //instead of assuming its location.  (0,0 could equal [0][0] in the array)

	for (int row = 0; row < numRows; row++) {
		for (int col = 0; col < numCols; col++) {

			if (ppTheBoard[row][col] == PIVOT) {							   //once the PIVOT is found we will change the values of the delcarations to where 
				pivotRow = row;												   //the PIVOT actually is 
				pivotCol = col;
			}
		}
	}

	if (directionCode == SLIDE_UP) {												//we are looking for a tile directly below the PIVOT 
		int tileRow = pivotRow + 1;													// this will bump us to the next row down by adding one
		int tileCol = pivotCol;														//this will keep us in the same column as we are looking directly below the PIVOT 

		if (tileRow < numRows) {													//this will ensure we do not go out of bounds by keeping the value less than bottom edge case
			ppTheBoard[pivotRow][pivotCol] = ppTheBoard[tileRow][tileCol];			//the PIVOT and tile are swapping locations by making PIVOT
			ppTheBoard[tileRow][tileCol] = PIVOT;									//equal to number and setting PIVOT in the numbers old spot 

			moveValid = true;														//indicate to the program that it was a valid move 
		}

	}
	else if (directionCode == SLIDE_DOWN) {
		int tileRow = pivotRow - 1;											    //this will bump us to the previous row up by subtracting one 
		int tileCol = pivotCol;

		if (tileRow >= 0) {													   //this will ensure we dont go out of bounds by keeping the value no less than 0 (top edge case)
			ppTheBoard[pivotRow][pivotCol] = ppTheBoard[tileRow][tileCol];
			ppTheBoard[tileRow][tileCol] = PIVOT;

			moveValid = true;
		}
	}
	else if (directionCode == SLIDE_LEFT) {									   //we are looking for a tile directly left of the PIVOT
		int tileRow = pivotRow;												   //this will keep us in the same row as we are looking directly to the left of the PIVOT 
		int tileCol = pivotCol - 1;											   //this will bump to the previous column (left) by subtracting one

		if (tileCol >= 0) {													   //this will ensure do not go out of bounds by keeping the value no less than 0 (left edge case)
			ppTheBoard[pivotRow][pivotCol] = ppTheBoard[tileRow][tileCol];
			ppTheBoard[tileRow][tileCol] = PIVOT;

			moveValid = true;
		}
	}
	else if (directionCode == SLIDE_RIGHT) {
		int tileRow = pivotRow;
		int tileCol = pivotCol + 1;											   //this will bump to the next column (right) by adding one 

		if (tileCol < numCols) {											   //this will ensure do not go out of bounds by keeping the value  less than right edge case
			ppTheBoard[pivotRow][pivotCol] = ppTheBoard[tileRow][tileCol];
			ppTheBoard[tileRow][tileCol] = PIVOT;

			moveValid = true;
		}
	}

	return moveValid;													       //if none of the above conditions are met than the move is not legal represented by a default false return
}

void SlidingPuzzle::scrambleBoard() {
	/*the following will scramble the board using a recursive technique
	and using the random number generator seeded in main*/
	cout << endl;
	cout << "Scrambling the tiles..." << endl;
	cout << "Scrambling complete, press any key to begin solving.";
	_getch();

	scrambleMoves(10);															//this will perform 1000 random slides to ensure thorough shuffle
																				    //change this to a smaller number like 30 for an easier solve while testing 

}

void SlidingPuzzle::scrambleMoves(int moves) {
	if (moves > 0) {							 //base case, we are couting number of moves wanted (1000)
		int randomSlide = rand() % 4 + 1;		 //achieve one of four random possible directions (+1 because modulo could poptentially equal 0 which we do not want(that would be nothing moving))
		slideTile(randomSlide);					 //apply the random move to the board 
		scrambleMoves(moves - 1);			     //this is the recursion: recalling the function but with 
												 //a change to the number of moves left by one each time 
												 //it is called on 
	}

}

bool SlidingPuzzle::isBoardSolved() {
	/*the following will check against the position of each number to see if it is currently solved or not.
	after checking the condition this will then print out a statement for the user weather isBoardSolved():
	is true or false*/

	/*the equation(row * numCols) + col + 1 will be used to check if the correct value is present
	EX for #1: row and col  would be [0][0] because of array, and numCols is 3 as defined
	so: (0 * 3) + 0 + 1 = 1*/
	bool solved = true;

	for (int row = 0; row < numRows; row++) {
		for (int col = 0; col < numCols; col++) {

			if (row == numRows - 1 && col == numCols - 1) {					     //checking the special condition of the PIVOT first  
				if (ppTheBoard[row][col] != PIVOT) {						     //since it is not a numerical value and returning
					solved = false;						                         // false if not in the bottom right corner (the only way a win coul be achieved);
				}
			}
			else if (ppTheBoard[row][col] != (row * numCols) + col + 1) {		 //checking the numerical value of each position and returning
				solved = false;													 //false if not in the correct position (example [0][0] should be 1)
			}
		}
	}
																				 //returning true if the above conditions pass through without 
	return solved;																 //meeting false conditions (everything is where it belongs)
}