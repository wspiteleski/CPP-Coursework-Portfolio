/*Author: William Stewart Piteleski
Description: the driver file uses class syntax version 4 and is responsible for instantiating
and organizing the logic to produce the fractions calculations, reduction
and Greatest Common Divisor with operator overloading*/

#include <iostream>
#include "FractionSpecification.h"

using namespace std;

int main() {
	Fraction myFirstFraction(3, 4);						//setting custom fractions with arbitrary values
	Fraction mySecondFraction(1, 2);
	Fraction myTestFraction(5, 6);						//for setter test
	Fraction resultFraction;

	resultFraction = myFirstFraction + mySecondFraction;   //performing addition operation
	cout << myFirstFraction << " + " << mySecondFraction << " = " << resultFraction << endl;

	resultFraction = myFirstFraction - mySecondFraction;   //performing subtraction operation
	cout << myFirstFraction << " - " << mySecondFraction << " = " << resultFraction << endl;

	resultFraction = myFirstFraction * mySecondFraction;   //performing multiplication operation
	cout << myFirstFraction << " * " << mySecondFraction << " = " << resultFraction << endl;

	resultFraction = myFirstFraction / mySecondFraction;   //performing division operation
	cout << myFirstFraction << " / " << mySecondFraction << " = " << resultFraction << endl;

	myFirstFraction = mySecondFraction;					  //performing equals operation
	cout << "My first fraction now equals my second fraction: " << myFirstFraction << endl << endl;

	cout << "SETTER TESTING" << endl;					   //demonstrating bool return values
	cout << "My test fraction is: " << myTestFraction << endl;
	if (myTestFraction.SetDenominator(9)) {
		cout << "SetDenominator() is valid: " << myTestFraction << endl;

	}
	if (!myTestFraction.SetDenominator(0)) {
		cout << "SetDenominator(0) is invalid";
	}

	return 0;
}