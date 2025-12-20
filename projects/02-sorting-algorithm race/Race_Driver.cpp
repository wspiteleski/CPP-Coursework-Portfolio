/*Author: William Stewart Piteleski
Description: the specification file uses class syntax version 4 and is responsible for
instantiating both sorter and timer to create an interface that shows the difference in time to sort
4 instances of number arrays (500 numbers, 5000 numbers, 25000 numbers, and 100000 numbers
read directly from given files*/

#include <iostream>
#include <iomanip>							//sor setprecision()
#include "Sorter.h"
#include "Timer.h"
#include <conio.h>							//for getch()
using namespace std;

int main() {
	string files[] = {										//setting the files to be read for the race
		"NumFile500.txt",
		"NumFile5K.txt",
		"NumFile25K.txt",
		"NumFile100K.txt"
	};

	int sizes[] = { 500, 5000, 25000, 100000 };				//used to show user which file is being populated and sorted 

	// Populate all 4 files 
	for (int i = 0; i < 4; i++) {
		cout << "Populating Arrays... <" << sizes[i] << " elements>" << endl;

		// instatiate all three sorting types 
		Sorter bubbleSort;
		Sorter selectionSort;
		Sorter insertionSort;

		// Load the file into each sorter type 
		bubbleSort.LoadFile(files[i]);
		selectionSort.LoadFile(files[i]);
		insertionSort.LoadFile(files[i]);

		cout << "Sorting..." << endl;

		// Run all three sort types 
		bubbleSort.BubbleSorter();
		insertionSort.InsertionSorter();
		selectionSort.SelectionSorter();

		cout << "SORTS COMPLETE!" << endl;

		cout << fixed << setprecision(3);			// Display results with proper formatting
		cout << "Elapsed Time <Bubble Sort>   : " << bubbleSort.GetBubbleTime() << " milliseconds" << endl;
		cout << "Elapsed Time <Insertion Sort>: " << insertionSort.GetInsertionTime() << " milliseconds" << endl;
		cout << "Elapsed Time <Selection Sort>: " << selectionSort.GetSelectionTime() << " milliseconds" << endl;
		cout << endl;  
	}

	cout << "ANALYSIS COMPLETE... PRESS ANY KEY TO CONTINUE." << endl;
	cout << "Press any key to continue";
	_getch();									 //pauses screen for user to be able to read results 

	return 0;
}