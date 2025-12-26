/*Author: William Stewart Piteleski
Description: the implementation file uses class syntax version 4 and is responsible for providing 
constructor and method definitions*/

#include "Timer.h"
#include <iostream>
#include <iomanip>					   //used for setprecision()
#include <time.h>					   //used for clock()

using namespace std;

//CONSTUCTORS
Timer::Timer() {					   //default constructor for timer 
	startTime = 0;
	gainedTime = 0;					   //amount of time gained while timer is running 
	isTicking = false;
}

//METHODS
bool Timer::Start() {
	if (isTicking) {				   //if timer is already running, dont start again 
		return false;
	}

	startTime = clock();			   //store the start time 
	isTicking = true;				   //start the timer 
	return true;
}

bool Timer::Stop() {
	if (!isTicking) {				   //if timer is already stopped, dont stop again
		return false;
	}

	clock_t currentTime = clock();						   //store the end time 
	clock_t timerStopped = currentTime - startTime;		   //calculate the time elapsed since starting

	gainedTime += timerStopped;							   //store elapsed time 

	isTicking = false;									   //stop the timer 
	return true;
}

void Timer::Reset() {									   //reset timer back to default state 
	startTime = 0;
	gainedTime = 0;
	isTicking = false;
}

double Timer::GetMilliseconds() {
	return gainedTime / (CLOCKS_PER_SEC / 1000);		   //calculate milliseconds that have elapsed
}

bool Timer::IsTicking() {								   //determine if clock is ticking or not 
	return isTicking;
}