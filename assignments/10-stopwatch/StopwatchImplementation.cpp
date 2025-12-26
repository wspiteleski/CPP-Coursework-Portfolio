/*Author: William Stewart Piteleski
Description: the implementation file uses class syntax version 4 and is responsible for providing
constructor and methods definitions*/

#include "StopWatch.h"
#include <iostream>
#include <iomanip>						//used for setprecision()
#include <time.h>

using namespace std;

//CONSTRUCTORS
StopWatch::StopWatch() {				//default constructor
	startTime = 0;
	gainedTime = 0;						//ammount of time gained while stopwatch is running
	isTicking = false;
}

//METHODS
bool StopWatch::Start() {				//if stopwatch is already running, dont start again
	if (isTicking) {					
		return false;
	}

	startTime = clock();				//store the start time in clock()
	isTicking = true;					//start the stopwatch 
	return true;
}

bool StopWatch::Stop() {				//if stop watch is already stopped, dont stop again 
	if (!isTicking) {
		return false;
	}

	clock_t currentTime = clock();							//store the end time in clock()
	clock_t watchStopped = currentTime - startTime;			//calculate time elapsed since starting

	gainedTime += watchStopped;

	isTicking = false;					//stopped the stopwatch
	return true;						
}

bool StopWatch::IsTicking() {
	return isTicking;
}

void StopWatch::DisplayTimerInfo() {
	int seconds = gainedTime / CLOCKS_PER_SEC;				  //calculating the ticks into seconds
	int milliseconds = gainedTime / (CLOCKS_PER_SEC / 1000);  //calculating the ticks into milliseconds 
	
	double totalTime = seconds + (milliseconds % 1000) / 1000.0; //combining seconds and milliseconds for final outcome 

	cout << fixed << setprecision(3);						//setting format for decimal number
	cout << totalTime << " seconds have passed" << endl;
	cout << "Press any key to continue" << endl;
	_getch();
}