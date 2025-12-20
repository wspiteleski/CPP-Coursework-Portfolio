/*Author: William Stewart Piteleski
Description: This main driver file uses class syntax version 4 and is responsible for instantiating the specified object 
and organizing logic ot produce a triangle displpay and  the pythagorean theorem results including:
hypotenuse, area, and perimeter based on the data entered for adjacent and opposite side 
lengths*/

#include <iostream>
#include <conio.h>								 //for _getch() function to pause the screen and take key entry from user 
#include <iomanip>								 //included for setw() function for spacing formating
#include "triangleSpecification.h"

using namespace std;

int main() {
	Triangle newTriangle;																		   //instantiate the object 

	if (newTriangle.setOppositeSide(4.6) == false) {
		cout << "Invalid call to setOppositeSide()... value must be greater than 0" << endl;	   //bool comparisons makes sure the entered value is greater than 0
	}
														
	if (newTriangle.setAdjacentSide(8.3) == false) {
		cout << "Invalid call to setAdjacentSide... value must be greater than 0" << endl;		   //bool comparisons makes sure the entered value is greater than 0
	}
	
	//DISPLAY THE TRIANGLE AND VALUES WITH EXPECTED FORMATTING 

	cout << setw(21) << "*" << endl;
	cout << setw(22) << "**" << endl;
	cout << setw(23) << "* *" << endl;													 //ASCII art for triangle 
	cout << setw(24) << "*  *" << endl;
	cout << setw(25) << "*   *" << endl;
	
	float opposite = newTriangle.getOppositeSide();										 //conditional used to format whole number display versus decimal number display sp triangle doesn't lose shap 
	cout << "Opposite Side = ";															  
	if (opposite == (int)opposite){														 //comparison conditional to identify whole number 
		cout << opposite << "   " << "*    *";
	}else {
		cout << fixed << setprecision(1) << opposite << " " << "*    *";				 //setprecision(1) locks decimal numbers to one decimal place
	}

	float hypotenuse = newTriangle.getHypotenuse();										 //conditional used to format whole number display versus decimal number display  
	cout << "   Hypotenuse Side = ";													  
	if (hypotenuse == (int)hypotenuse) {												 //comparison conditional to identify whole number 
		cout << hypotenuse << endl;
	}else {
		cout << fixed << setprecision(1) << hypotenuse << endl;							 //setprecision(1) locks decimal numbers to one  decimal place 
	}

	cout << setw(27) << "*     *" << endl;
	cout << setw(28) << "*      *" << endl;
	cout << setw(29) << "*       *" << endl;										     //ASCII art for triangle 
	cout << setw(30) << "**********" << endl << endl;
	cout << setw(36) << "Adjacent Side = " << newTriangle.getAdjacentSide() << endl << endl;
	cout << "The area of the triangle is" << setw(7) << ": " << newTriangle.getArea() << endl;
	cout << "The perimeter of the triangle is: " << newTriangle.getPerimeter() << endl;
	cout << "Press any key to continue";

	_getch();																			 //pauses screen until user presses a key to be able to observe the program without completing prematurely 

	return 0;
}