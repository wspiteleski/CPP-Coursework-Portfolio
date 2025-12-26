/*Author: William Stewart Piteleski
Description: the specification file uses class syntax version 4 and is responsible for describing the 
vector object and its features provided by the instrcutor in conjunction with overloading features*/

#ifndef _VECTOR_
#define _VECTOR_

#include <iostream>
#include <math.h>

using namespace std;

//CLASS SPECIFICATION
class Vector {

private:
	//DATA MEMBERS
	double _v_x;
	double _v_y;
	double _magnitude;

	//HELPER METHODS
	void CalculateMagnitude();

public:
	//CONSTRUCTORS
	Vector();
	Vector(double _v_x, double _v_y);

	//SETTERS
	void SetVX(double _v_x);
	void SetVY(double _v_y);

	//GETTERS
	double GetVX();
	double GetVY();
	double GetMagnitude();

	//OPERATIONS
	Vector AddVector(Vector addMe);
	Vector SubtractVector(Vector subtractMe);

	//DISPLAY METHODS
	void Display();

	//OVERLOADS
	void operator=(Vector value);
	
	Vector operator+(Vector addMe);

	Vector operator-(Vector subtractMe);

	friend ostream& operator<<(ostream&, Vector& theVector);

};

#endif
