/*Author: William Stewart Piteleski
Description: the specification file uses class syntax version 4 and is responsible for describing the
stop watch object and its features*/

#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <conio.h>

using namespace std;

//CLASS SPECIFICATION
class StopWatch {
private:
	//DATA MEMBERS
	clock_t startTime;
	clock_t gainedTime;
	bool isTicking;
public:
	//CONSTRUCTORS
	StopWatch();
	//METHODS
	bool Start();
	bool Stop();
	bool IsTicking();
	void DisplayTimerInfo();
};
#endif