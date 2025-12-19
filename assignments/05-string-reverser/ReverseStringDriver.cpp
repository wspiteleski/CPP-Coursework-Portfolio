/*Author: William Stewart Piteleski
Description: The following program will utilize non-tail recursive technique to reverse a string input.
This will be done with restrictions stated by the instructor (one integer / one character declarative and no additional libraries).
*/

// INCLUES AND NAMESPACES
#include <iostream>
#include <conio.h>		//added for _gethc() 

using namespace std;

// CONSTANTS
const int STRING_SIZE = 100;

// PROTOTYPES
int ReverseStringRecursive(char*);

// MAIN
int main() {
	// create a string
	char someString[STRING_SIZE] = "onamonapea";

	// display the string before being reversed
	cout << "The string contains: " << endl;
	cout << someString << endl << endl;

	// make the call to the recursive function
	cout << "CALL THE REVERSING FUNCTION" << endl << endl;
	ReverseStringRecursive(someString);

	// display the string after being reversed
	cout << "The string contains: " << endl;
	cout << someString << endl;
	cout << "Press any key to continue...";

	// exit program
	_getch();																   //added to pause the program from ending before the user is done 
	return 0;
}

// FUNCTION IMPLEMENTATIONS
int ReverseStringRecursive(char* pReverseMe) {								   //altered reverseMe to pReverseMe to illustrate that it is a pointer for easier understanding 
	int stringLength = 0;													   //declaring and initializing our one integer variable, this will keep track of the length of the sting (26 in this case)
	char currentLetter = 0;													   //declaring and initializing our one character variable, this will store a letter for later usage 
																			   //both are initialized to 0 for basic secure programming practices
	if (*pReverseMe == 0) {
		return 0;															   //base case (1) is 0: if we iterate through and do not have a character this will end the recursion
	}

	while (*(pReverseMe + stringLength) != 0) {								   //we will use a simple while loop to count how larger the string actually is,
		stringLength++;														   //0 represents the first blank space it will run into to stop counting 
	}

	if (stringLength <= 1) {												   //base case (2) if stringLength is less than or equal to one there is nothing to reverse 
		return stringLength;
	}

	currentLetter = *pReverseMe;											   //saving the character to memory for later use 
	*pReverseMe = *(pReverseMe + stringLength - 1);							   //moving to the last point in the array (the -1 is because the array position 0 is the first actual position)
	*(pReverseMe + stringLength - 1) = currentLetter;						   //placing the saved character into the last valid slot of the array 

	*(pReverseMe + stringLength - 1) = 0;									   //setting the NEW last character to 0 so it is not part future recursions

	ReverseStringRecursive(pReverseMe + 1);									   //this is the recursion 

	*(pReverseMe + stringLength - 1) = currentLetter;						   //we can now replace the characters set to zero so we can see them because the recursion has ended

	return stringLength;
}																			   
