/*Author: William Stewart Piteleski
Description: This implementation file uses class syntax version 4 and is responsible for providing definitions
of the methods of the triangle  responsible for producing a triangle displpay and  
the pythagorean theorem results including:
hypotenuse, area, and perimeter based on the data entered for adjacent and opposite side
lengths*/

#include "triangleSpecification.h" 
#include <cmath>							     //included for sqrt() function for pythagoreum theorum

//CONSTRUCTOR
Triangle::Triangle() {
	this->oppositeSide = 0.0;					 //this-> used to point to the objects variable
	this->adjacentSide = 0.0;					 //setting default values to 0.0 for basic secure programming pratices
	this->hypotenuse = 0.0;
	this->area = 0.0;
	this->perimeter = 0.0;
}

//GETTERS
float Triangle::getOppositeSide() {
	return this->oppositeSide;
}

float Triangle::getAdjacentSide() {
	return this->adjacentSide;
}

float Triangle::getHypotenuse() {			     //MATHMATICS FOR FINDING HYPOTENUSE: hypotenuse = squareroot(opposite side squared + adjacent side squared)
	return sqrt((this->oppositeSide * this->oppositeSide) + (this->adjacentSide * this->adjacentSide));
}

int Triangle::getArea() {						 //MATHMATICS FOR FINDING AREA: area = (opposite side x adjacent side) / 2
	return (this->oppositeSide * this->adjacentSide) / 2;
}

int Triangle::getPerimeter() {					 //MATHMATICS FOR FINDING PERIMETER: perimeter = opposite side + adjacent side + hypotenuse
	return this->oppositeSide + this->adjacentSide + this->getHypotenuse();	   //used getHypotenuse to get calculated version instead of default 0.0
}

//SETTERS
bool Triangle::setOppositeSide(float myOpposite) {
	bool accepted = false;						 //default bool state

	if (myOpposite <= 0) {						 //ensuring opposite side cant be set to a negative 
		accepted = false;
	}else {
		this->oppositeSide = myOpposite;		 //if value is not a negative, we will allow oppositeSide toe be set to input value 
		accepted = true;
	}

	return accepted;							 //let client know if accepted is true or false
}

bool Triangle::setAdjacentSide(float myAdjacent) {
	bool accepted = false;

	if (myAdjacent <= 0) {
		accepted = false;
	}else {
		this->adjacentSide = myAdjacent;
		accepted = true;
	}

	return accepted;
}



