/*Author: William Stewart Piteleski
Description: the implementation file uses class syntax version 4 and is responsible for providing
constrcutor, getter, setter, method, and overload definitions*/

#include "FractionSpecification.h"

//METHOD IMPLEMENTATIONS

//helper methods
int Fraction::FindGCD(int a, int b) {			
	if (b == 0) {								// if there are no remainders, current a is greatest
		return a;								//common divisor 
	}
	else{
		return FindGCD(b, a % b);			    //if there are remainders, divide by remainder until 
	}											//b = 0 to know you found greatest common divisor 
}

void Fraction::Reduce() {
	int GCD = Fraction::FindGCD(_numerator, _denominator);	  //find the GCD of the numerator and denominator
	this->_numerator  = this->_numerator / GCD;				  //divde numerator by GCD
	this->_denominator = this->_denominator / GCD;			  //divide denominator by GCD
}

//constructors
Fraction::Fraction() {							 //default fraction
	this->_numerator = 0;				         // setting numerator to starting value of 0
	this->_denominator = 1;						 // denominator can not equal less than 1 or fraction is invalid
}

Fraction::Fraction(int numerator, int denominator) {	   //construct custom fraction
	if (denominator == 0) {								   // denominator is invaslid if 0
		this->_denominator = 1;							   //protect fraction by setting fraction to default value
		this->_numerator = 0;
	}
	else {
		this->_numerator = numerator;					   //set valid numerator and denominator
		this->_denominator = denominator;
	}
	Fraction::Reduce();								   //perform reduction for lowest term value 
}

//getters
int Fraction::GetNumerator() {					
	return this->_numerator;
}

int Fraction::GetDenominator() {
	return this->_denominator;
}

//setters
bool Fraction::SetNumerator(int numerator) {
	this->_numerator = numerator;
	Reduce();
	return true;										   //numerator will always be true 
}

bool Fraction::SetDenominator(int denominator) {
	if (denominator == 0) {
		return false;									   //denominator cannot be = 0 
	}
	else {
		this->_denominator = denominator;
		Reduce();
		return true;									   //if not = 0, denominator can be set to value
	}
}

//operations
//ADDITION
Fraction Fraction::operator+(Fraction addMe) {
	//create a temp fraction to avoid manipulating original 
	Fraction returnMe;									
	
	//add corresponding fraction components
	//Set Numerator: a/b + c/d -- (a X d) + (c X b)
	returnMe.SetNumerator((this->_numerator * addMe.GetDenominator()) + (addMe.GetNumerator() * this->_denominator));
	//Set Denominator: a/b + c/d -- (b X d)
	returnMe.SetDenominator(this->_denominator * addMe.GetDenominator());

	//return the temp fraction
	return returnMe;
}

//SUBTRACTION
Fraction Fraction::operator-(Fraction subtractMe) {
	//create a temp fraction to avoid manipulating original 
	Fraction returnMe;
	
	//subtract corresponding fraction components
	//Set Numerator: a/b - c/d -- (a X d) - (c X b)
	returnMe.SetNumerator((this->_numerator * subtractMe.GetDenominator()) - (subtractMe.GetNumerator() * this->_denominator)); 
	//Set Denominator: a/b - c/d -- (b X d)
	returnMe.SetDenominator(this->_denominator * subtractMe.GetDenominator());
	
	//return the temp fraction
	return returnMe;
}

//MULTIPLICATION
Fraction Fraction::operator*(Fraction multiplyMe) {
	//create a temp fraction to avoid manipulating original 
	Fraction returnMe;

	//multiply corresponding fraction components
	//Set Numerator: a/b * c/d -- (a X c)
	returnMe.SetNumerator(this->_numerator * multiplyMe.GetNumerator());
	//Set Denominator: a/b * c/d -- (b X d)
	returnMe.SetDenominator(this->_denominator * multiplyMe.GetDenominator());

	//return the temp fraction
	return returnMe;
}

//DIVISION
Fraction Fraction::operator/(Fraction divideMe) {
	//create a temp fraction to avoid manipulating original 
	Fraction returnMe;

	//check to see if dividing number is zero
	if (divideMe.GetNumerator() == 0) {
		//revert to safe default fraction
		returnMe.SetNumerator(0);
		returnMe.SetDenominator(1);
	}
	//if dividing number is not zero
	else {
		//divide coresponding fraction components
		//Set Numerator: a/b (divide) c/d -- (a X d)
		returnMe.SetNumerator(this->_numerator * divideMe.GetDenominator());
		//Set Denominator: a/b (divide) c/d -- (b X c)
		returnMe.SetDenominator(this->_denominator * divideMe.GetNumerator());
	}
	//return temp fraction
	return returnMe;
}

//overloads
void Fraction::operator=(Fraction value) {
	this->SetNumerator(value.GetNumerator());
	this->SetDenominator(value.GetDenominator());
}

ostream& operator<<(ostream & outputStream, Fraction & theFraction) {
	outputStream << "<" << theFraction._numerator << "/" << theFraction._denominator << ">";
	
	return outputStream;
}