/*Author: William Stewart Piteleski
Description: the specification file uses class syntax version 4 and is responsible for describing the
Time object and its features*/


#ifndef Timer_H
#define Timer_H

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <conio.h>

using namespace std;

//CLASS SPECIFICATION
class Timer {
private:
	clock_t startTime;
	clock_t gainedTime;
	bool isTicking;
public:
	//CONSTRUCTOR
	Timer();
	//METHODS
	bool Start();
	bool Stop();
	void Reset();
	double GetMilliseconds();
	bool IsTicking();
};

#endif 

