/*Author: William Stewart Piteleski
Description: This specification file uses class syntax version 4 and is responsible for describing
interfaces of the sliding tile game that will be implemented*/

#ifndef _GAME_BOARD_												 //START OF OBJECT
#define _GAME_BOARD_

#include <iostream>

using namespace std;

//CLASS GAME BOARD
class SlidingPuzzle {
private:
	int numRows = 0;												 //total number of rows 
	int numCols = 0;												 //total number of columns 
	int** ppTheBoard = NULL;										 //double pointer for dynamic 2d array so the puzzle can scale 					
	void scrambleMoves(int moves);
public:
	//CONSTRUCTORS 
	SlidingPuzzle();												 //DEFAULT 3X3 SIZE BOARD
	SlidingPuzzle(int width, int height);							 //USER INPUT SIZE BOARD (overloading SlidingPuzzle)

	//DESTRUCTOR
	~SlidingPuzzle();												 //used to deallocate memory 

	//UTILITIES FOR BOARD METHODS
	void InitializeBoard();
	void PrintBoard();
	bool slideTile(int directionCode);								 //controls for player to solve the puzzle 
	void scrambleBoard();
	bool isBoardSolved();
};
#endif																 //END OF OBJECT 