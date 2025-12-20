/*Author: William Stewart Piteleski
Description: This specification file uses class syntax version 4 and is responsible for describing interfaces of the triangle
responsible for producing a triangle displpay and  the pythagorean theorem results including:
hypotenuse, area, and perimeter based on the data entered for adjacent and opposite side
lengths*/

#ifndef _TRIANGLE_							     //preprocessor protection from multiple declarations
#define _TRIANGLE_							     //preprocessor protection from multiple declarations

#include <iostream>
using namespace std;

//TRIANGLE CLASS
class Triangle {
private:										 //protecting from manipulation of triangle attributes
	float oppositeSide;
	float adjacentSide;
	float hypotenuse;
	int area;
	int perimeter;

public:											 //methods that are allowed to be interacted with 
	//CONSTRUCTOR 
	Triangle();

	//GETTERS
	float getOppositeSide();
	float getAdjacentSide();
	float getHypotenuse();						 //MATHMATICS FOR FINDING HYPOTENUSE: hypotenuse = squareroot(opposite side squared + adjacent side squared)
	int getArea();								 //MATHMATICS FOR FINDING AREA: area = (opposite side x adjacent side) / 2
	int getPerimeter();							 //MATHMATICS FOR FINDING PERIMETER: perimeter = opposite side + adjacent side + hypotenuse

	//SETTERS
	bool setOppositeSide(float myOpposite);		 //setter methods are bools to prevent negative numbers from the user 
	bool setAdjacentSide(float myAdjacent);
	
};												 //END OF TRIANGLE 

#endif 											 //preprocessor protection from multiple declarations