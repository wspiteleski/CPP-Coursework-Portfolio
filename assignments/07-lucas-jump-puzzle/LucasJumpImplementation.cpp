/*Author: William Stewart Piteleski
Description: The implementation file uses class syntax version 4 and is responsible for providing
constructor, getter, setter, and  method definitions for items stated in sepcifrication file */

#include "LucasJumpSpecification.h"						 //calls on specification file for methods being defined 

//CONSTRUCTOR definition
LucasJump::LucasJump() {						 //instantiating the board with 7 slots
	board[0] = 'B';								 //blue token slots represented by B
	board[1] = 'B';
	board[2] = 'B';
	board[3] = '*';								 //empty slot 
	board[4] = 'R';								 //red token slots represented by R
	board[5] = 'R';
	board[6] = 'R';

	emptySlot = 3;								 //telling the board which position is considered empty 
}

//GETTERS definitions 
int LucasJump::getEmptySlot() {				     //will return the value of the astrisk to define which slot is empty after changes 

	return emptySlot;
}

char LucasJump::getSlot(int index) {			 //will return character 'B' '*' or 'R' based on return

	return board[index];					
}

//SETTERS definitions 
void LucasJump::setSlot(int index, char token) { //sets the index number to the represented token 
	board[index] = token;
}

void LucasJump::setEmptySlot(int index) {		 //sets the index number to the empty position 
	emptySlot = index;
}

//METHODS
bool LucasJump::move(int position) {			 //ensures the player cannot make a move outside of the board slots
	if (position < 0 || position > 6) {
		return false;							 //this is an illegal move so it returns false 
	}

	if (position == emptySlot) {				 //ensures the player cannot move the empty slot 
		return false;							 //this is an illegal move so it returns false 
	}

	if (position == emptySlot - 1 && board[position] == 'B') {       //if the position to the left of empty is blue
		setSlot(emptySlot, board[position]);						 //replace empty slot with blue token 
		setSlot(position, '*');										 //replace blue token slot with empty slot (*)
		setEmptySlot(position);										 //reset with new empty slot position 
		
		return true;												      //this is a legal move so it returns true 
	}else if (position == emptySlot + 1 && board[position] == 'R') {      //if the position to the right of empty is red
		setSlot(emptySlot, board[position]);						      //replace empty slot with red token 
		setSlot(position, '*');										      //replace red token slot with emtpy slot (*)
		setEmptySlot(position);										      //reset with new empty slot position 
		
		return true;												      // this is a legal move so it retruns true 
	}else if (position == emptySlot - 2 && board[position] == 'B' && board[emptySlot - 1] != '*') {     //if the position two to the left of empty are blue (neighbor jumping)
		setSlot(emptySlot, board[position]);													        //replace empty slot with blue token
		setSlot(position, '*');																	        //replace blue token slot with empty slot (*)
		setEmptySlot(position);																	        //reset with new empty slot position 

		return true;																			        //this is a legal move so it returns true 
	}else if (position == emptySlot + 2 && board[position] == 'R' && board[emptySlot + 1] != '*') {	    //if the position two to the right of empty are red (neighbor jumping)
		setSlot(emptySlot, board[position]);													        //replace empty slot with red token
		setSlot(position, '*');																	        //replace red token slot with empty slot (*)
		setEmptySlot(position);																	        //reset with new empty slot position 

		return true;																			        //this is a legal move so it returns true 
	}else {

		return false;								 //if we check through move and no true returns ocurr default to false 
	}
}

bool LucasJump::isSolved() {															 //if the board is in this exact configuration the puzzle is solved 
	if (board[0] == 'R' && board[1] == 'R' && board[2] == 'R' && board[3] == '*'
		&& board[4] == 'B' && board[5] == 'B' && board[6] == 'B') {
		return true;																	 //board is solved, statement returns true 
	}else {
		return false;																	 //board is not solved, statement returns false 
	}
}

bool LucasJump::isGimp() {																							   //checks to see if any legal moves are still available by following the same move rules as move();
	for (int legalMove = 0; legalMove < 7; legalMove++) {
		if (legalMove == emptySlot - 1 && board[legalMove] == 'B') {
			
			return false;																							   //if and if else these moves are possible the game is not "gimped" so return false 
		}else if (legalMove == emptySlot + 1 && board[legalMove] == 'R') {
			
			return false;
		}else if (legalMove == emptySlot - 2 && board[legalMove] == 'B' && board[emptySlot - 1] != '*') {

			return false;
		}else if (legalMove == emptySlot + 2 && board[legalMove] == 'R' && board[emptySlot + 1] != '*') {

			return false;
		}
	}
	return true;																								       //if no false returns come back from condition checking then the game must be gimped, return true 
}