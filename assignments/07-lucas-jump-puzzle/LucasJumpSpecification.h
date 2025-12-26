/*Author: William Stewart Piteleski
Description: The following specification file uses class syntax version 4 and is resposible for describing
the LucasJump gameboard and its features like position, movement, ,solve state, and gimp state*/

#ifndef GAME_BOARD								 //preprocessor protection from multiple declarations
#define GAME_BOARD								 //preprocessor protection from multiple declarations 

//CLASS
class LucasJump {
private:										 //protecting from manipulation of the game board 
	char board[7];								 //total slots that make the board 
	int emptySlot;								  //the empty slot that allows tokens to move 

public:											 //methods that are allowed to be interacted with 
	//CONSTRCUTOR
	LucasJump();								 //instantiates the game 
	
	//GETTERS
	char getSlot(int index);					 //returns token at a location
	int getEmptySlot();							 //identifies current empty slot 

	//SETTERS
	void setSlot(int index, char token);		 //changes slot to token moved into position
	void setEmptySlot(int index);				 //changes slot to empty when token is moved current position

	//METHODS
	bool move(int position);					 //identifies if a token can legally move 
	bool isSolved();							 //identifies if the game is solved 
	bool isGimp();								 //identifies if game is unsolvable in current state 
};
#endif
