/*Author: William Stewart Piteleski
Description: the specification file uses class syntax version 4 and is responsible for describing the
fraction object and its features in conjunction with overloading*/

#ifndef _FRACTION_
#define _FRACTION_

#include <iostream>
#include <math.h>

using namespace std;

//CLASS SPECIFICATION
class Fraction {
private:
	//DATA MEMBERS 
	int _numerator;
	int _denominator;
	
	//HELPER METHODS
	void Reduce();				   //reduce fraction to lowest terms 
	int FindGCD(int a, int b);	   // greatest common divisor needed to reduce value to lowest terms 

public:
	//CONSTRCUTORS
	Fraction();
	Fraction(int _numerator, int _denominator);

	// GETTERS
	int GetNumerator();
	int GetDenominator();

	//SETTERS
	bool SetNumerator(int numerator);				//meaningful return values of true / false 
	bool SetDenominator(int denominator);		    //instead of void returns from vector assignment 


	//OVERLOADS
	void operator=(Fraction value);

	Fraction operator+(Fraction addMe);

	Fraction operator-(Fraction subtractMe);

	Fraction operator*(Fraction multiplyMe);

	Fraction operator/(Fraction divideMe);

	friend ostream& operator<<(ostream& outputStream, Fraction& theFraction);
};
#endif
