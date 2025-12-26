/*Author: William Stewart Piteleski
Description: the implementation file uses class syntax version 4 and is responsible for providing
constructor, method, and getter definitions*/

#include <iostream>
#include <fstream>					   //for file stream library
#include "Sorter.h"

using namespace std;

//CONSTRUCTOR
Sorter::Sorter() {					   // default constructor for file sorter 
	fileArray = nullptr;
	arraySize = 0;
	bubbleTimer = 0.0;
	selectionTimer = 0.0;
	insertionTimer = 0.0;

}

//DECONSTRUCTOR
Sorter::~Sorter() {					   //deallocating memory needed to prevent memory leaks 
	if (fileArray != nullptr) {		   //checking if there is an array to delete by comparing the pointer 
		delete[] fileArray;			  //this will delete the array  
	}
}

//METHODS
/*the following will open the file twice, once to count how large of an array we want to make
and another time to fill the array with the values counted, this will allow for any file size
to be loaded without needing to know in advance how many values need to be stored*/
bool Sorter::LoadFile(string filename) {				   //read file and create an array
	ifstream inputHandle(filename, ios::in);			   //attempt to open the file 

	if (inputHandle.is_open() == true) {				   //checking if file is open 
		arraySize = 0;									   //set an array to accept read values 
		int fileValue;

		while (!inputHandle.eof()) {					   //eof = end of file 
			inputHandle >> fileValue;					   //identify the value being read
			arraySize++;								   //for every value counted grow the array 
		}
		
		inputHandle.close();							   //close the file after reading 

		fileArray = new int[arraySize];					   //create the array based on the counted size
		inputHandle.open(filename, ios::in);			   //open file a second time 

		if (inputHandle.is_open() == true) {
			int value = 0;

			while (!inputHandle.eof()) {
				if (value < arraySize) {
					inputHandle >> fileArray[value];	   //store the read number into the array 
					value++;
				}
			}

			inputHandle.close();						   //close the file a second time
		}
		return true;
	}
	else {
		cout << "Error: the file " << filename << " could not be opened for reading..." << endl;
		return false;									   //indicate file is not open 
	}
}

//GETTERS
int Sorter::GetArraySize() {
	return arraySize;
}

double Sorter::GetBubbleTime() {
	return bubbleTimer;
}

double Sorter::GetSelectionTime() {
	return selectionTimer;
}

double Sorter::GetInsertionTime() {
	return insertionTimer;
}

//SORTING METHODS
//BUBBLE
void Sorter::BubbleSorter() {
	
	myTimer.Reset();									   //ensure the timer is refreshed to default values
	myTimer.Start();									   //start the timer 
	
	for (int count = 0; count < arraySize - 1; count++) {  //move through the file array of numbers
		
		for (int position = 0; position < arraySize - 1 - count; position++) {	//compare numbers in the file array
			if (fileArray[position] > fileArray[position + 1]) {
				int tempNum = fileArray[position];								   //if the values are out of order swap positions
				fileArray[position] = fileArray[position + 1];
				fileArray[position + 1] = tempNum;
			}
		}
	}

	myTimer.Stop();									       //stop the timer 
	bubbleTimer = myTimer.GetMilliseconds();			   //convert the timer results to milliseconds
}

//SELECTION
void Sorter::SelectionSorter() {

	myTimer.Reset();
	myTimer.Start();

	for (int count = 0; count < arraySize - 1; count++) {
		int currentMin = count;												   //set a number to compare
		
		for (int position = count + 1; position < arraySize; position++) {	   //iterate through array comparing to number to compare
			
			if (fileArray[position] < fileArray[currentMin]) {
				currentMin = position;										   //swap compare number with smaller number found 
			}
		}
		int tempNum = fileArray[count];
		fileArray[count] = fileArray[currentMin];							   //swap smallets number found location 
		fileArray[currentMin] = tempNum;
	}

	myTimer.Stop();
	selectionTimer = myTimer.GetMilliseconds();
}

//INSERTION
void Sorter::InsertionSorter() {

	myTimer.Reset();
	myTimer.Start();

	int currentValue;														   //set a value to be compared 
	for (int count = 1; count < arraySize; count++) {
		int position = count - 1;
		currentValue = fileArray[count];

		while (position >= 0 && fileArray[position] > currentValue) {
			fileArray[position + 1] = fileArray[position];					   //move larger compared number up the line
			position--;														   //move smaller compared number down the line 
		}

		fileArray[position + 1] = currentValue;								   //insert value to correct position
	}

	myTimer.Stop();
	insertionTimer = myTimer.GetMilliseconds();
}