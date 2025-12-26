/*Author: William Stewart Piteleski
Description: The implementation file uses class syntax version 4 and is responsible for providing
constructor, getter, setter, method, and overload definitions in conjunction with instructor provided
code*/

#include "Specification.h"

//METHOD IMPLEMENTATIONS
//helper methods

void Vector::CalculateMagnitude() {
	this->_magnitude = sqrt(pow(abs(this->_v_x), 2) + pow(abs(this->_v_y), 2));
}

//constructors
Vector::Vector() {
	this->_v_x = 0.0;
	this->_v_y = 0.0;
	CalculateMagnitude();
}

Vector::Vector(double _v_x, double _v_y) {
	this->_v_x = _v_x;
	this->_v_y = _v_y;
	CalculateMagnitude();
}

//setters
void Vector::SetVX(double _v_x) {
	this->_v_x = _v_x;
	CalculateMagnitude();
}

void Vector::SetVY(double _v_y) {
	this->_v_y = _v_y;
	CalculateMagnitude();
}

//getters
double Vector::GetVX() {
	return this->_v_x;
}

double Vector::GetVY() {
	return this->_v_y;
}

double Vector::GetMagnitude() {
	return this->_magnitude;
}

//operations
Vector Vector::AddVector(Vector addMe) {
	//create a temp vector
	Vector returnMe;

	//add corresponding vector components
	returnMe.SetVX(this->_v_x + addMe.GetVX());
	returnMe.SetVY(this->_v_y + addMe.GetVY());

	//return the tempVector
	return returnMe;
}

Vector Vector::SubtractVector(Vector subtractMe) {
	//create a temp vector
	Vector returnMe;

	//subtract corresponding vector components
	returnMe.SetVX(this->_v_x - subtractMe.GetVX());
	returnMe.SetVY(this->_v_y - subtractMe.GetVY());

	//return the tempVector
	return returnMe;
}

//display methods
void Vector::Display() {
	cout << "<" << this->_v_x << ", " << this->_v_y << ">";
}

//overloads
void Vector::operator=(Vector value) {							//overloading the = operator for vector assignment 
	this->SetVX(value.GetVX());
	this->SetVY(value.GetVY());
}

Vector Vector::operator+(Vector addMe) {						//overloading the + operator for vector addition			
	Vector returnMe;
	returnMe.SetVX(this->_v_x + addMe.GetVX());
	returnMe.SetVY(this->_v_y + addMe.GetVY());

	return returnMe;
}

Vector Vector::operator-(Vector subtractMe) {				    //overloading the - operator for vecotr subtraction
	Vector returnMe;
	returnMe.SetVX(this->_v_x - subtractMe.GetVX());
	returnMe.SetVY(this->_v_y - subtractMe.GetVY());

	return returnMe;
}

ostream& operator<<(ostream& outputStream, Vector& theVector) {   //overloading the << operator for vector display 
	outputStream << "<" << theVector._v_x << ", " << theVector._v_y << ">";
	
	return outputStream;
}