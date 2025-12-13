/*Author: William Stewart Piteleski
DescriptionL: the following will print a dynamic multiplication table.
The user will be prompted to enter the number of rows and columns they would 
like to see to a maximum of 10 x 10.  The design pattern will also be dynamic,
growing and shrinking with the multiplication table while maintaining a specific
format.*/

#include <iostream>
#include <iomanip>			 //for using the setw() feature for uniform spacing and aesthetic 
#include <conio.h>			 //for using the _getch() feature

using namespace std;

int main() {
	int rows = 0;													 //intializing variable row and column as intergers to represent the array                                               
	int columns = 0;
	int** ppTimesTable = NULL;										 //initializing the double pointer that will be used for making the array dynamic (able to grow) 

	//user input and validation
	cout << "Please enter a number of rows on the interval [1, 10]: ";					 //this will print out expectations of the user 
	cin >> rows;																		 //stowing the new value into int rows so it is no longer zero 
	cout << endl;
	while(rows < 1 || rows > 10){														 //this will help by rejecting numbers not between 1-10 and reprompt the user to try again
		cout << "That is not within the range [1-10]. Please try again..." << endl;
		cout << "Please enter a number of rows on the interval [1, 10]: ";
		cin >> rows;																	 
		cout << endl;
	}
	cout << "Please enter a number of columns on the interval [1, 10]: ";
	cin >> columns;
	cout << endl;																		 //stowing the new value into int columns so it is no longer zero 
	while(columns < 1 || columns > 10){
		cout << "That is not within the range [1-10]. Please try again..." << endl;
		cout << "Please enter a number of columns on the interval [1, 10]: ";
		cin >> columns;
		cout << endl;
	}

	//allocating arrays 
	ppTimesTable = new(int* [rows]);								 //this will create an array of pointers from the double pointer 
	for (int numRow = 0; numRow < rows; numRow++) {
		ppTimesTable[numRow] = new(int[columns]);
	}

	for (int numRow = 0; numRow < rows; numRow++) {							   //this will iterate through both the rows and columns based on their value 
		for (int numCol = 0; numCol < columns; numCol++) {					   //the formula applied will multiply the values, we are adding one because of array notation
			ppTimesTable[numRow][numCol] = (numRow + 1) * (numCol + 1);		   //example: [0][0] would equal one so we want to add one for the multiplcation 
		}
	}

	//printing header labels 
	cout << "   |";													 //this is the spacing and beginning of the header labels with pipe seperator 
	for (int numCol = 1; numCol <= columns; numCol++) {				 //this is counting through to header labels needed 
		if (numCol < columns) {
			cout << setw(3) << numCol << "|";						 //this is printing the header labels with the piping until the last number
		}else {
			cout << setw(3) << numCol;								 //this is negating the pipe seperator for the last number in the table header 
		}
	}
	cout << endl;

	for (int numCol = 0; numCol <= columns; numCol++) {				 //this is counting through the total number of columns (<=) to implement the gridwork design feature
		if (numCol < columns) {										 //setting numCol to less than columns will stop the ---+ design before reaching the very end of the table 
			cout << "---+";
		}else {
			cout << "----";											 //the else statement will allow us the open ended design at the far right of the table 
		}
	}
	cout << endl;

	//printing the array of multiplications 
	cout << right;												          //this will set the numbers to align to the right for better aesthetic for larger tables 
	for (int numRow = 0; numRow < rows; numRow++) {
		cout << setw(3) << (numRow + 1) << "|";							  //this will make the row labels while using setw(4) for proper spacing 
		for (int numCol = 0; numCol < columns; numCol++) {
			if (numCol < columns - 1) {									  //setw(3) is being used for spacing based off of room needed for design elements
				cout << setw(3) << ppTimesTable[numRow][numCol] << "|";
			}
			else {
				cout << setw(3) << ppTimesTable[numRow][numCol];
			}
		}

		if (numRow < rows - 1) {									      //this will count through the rows while negating the last row to keep it open like in the example provided 
			cout << endl;
			for (int numCol = 0; numCol <= columns; numCol++) {
				if (numCol < columns) {
					cout << "---+";
				}
				else {
					cout << "----";
				}
			}
		}
		cout << endl;												     //this will break the line after number of columns are met and start a new line until 
		}																 //rows are fulfilled as well 
		cout << "Press and key to continue. . .";
		_getch();

		//memory managment 
		for (int numRow = 0; numRow < rows; numRow++) {					 //this is the memory clean up need to prevent memory leaks in the program 
			delete[] ppTimesTable[numRow];								 //this will delete the integer arrays  
		}
		delete[] ppTimesTable;											 //this will delete the array of pointers 

		_getch();
		return 0;
	}
	