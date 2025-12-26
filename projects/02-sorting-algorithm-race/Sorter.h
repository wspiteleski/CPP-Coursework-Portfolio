/*Author: William Stewart Piteleski
Description: the specification file uses class syntax version 4 and is responsible for describing the
Sorter object and its features*/

#ifndef SORTER_H
#define SORTER_H

#include <iostream>
#include <fstream>
#include "Timer.h"

using namespace std;

class Sorter {
private:
	int* fileArray;
	int arraySize;

	Timer myTimer;
	double bubbleTimer;
	double selectionTimer;
	double insertionTimer;
public:
	//CONSTRUCTOR
	Sorter();
	
	//DECONSTRUCTOR
	~Sorter();
	
	//METHODS 
	void BubbleSorter();
	void SelectionSorter();
	void InsertionSorter();
	bool LoadFile(string filename);
	

	//GETTERS
	double GetBubbleTime();
	double GetSelectionTime();
	double GetInsertionTime();
	int GetArraySize();

};

#endif 

