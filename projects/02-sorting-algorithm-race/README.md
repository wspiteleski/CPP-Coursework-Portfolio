# Project 02 10: Sorting Algorithm Race
---
## 📋 Overview
This Object Oriented Program demonstrates **performance analysis** by racing three sorting algorithms (Bubble Sort, Insertion Sort, Selection Sort) against increasingly large datasets. The program uses **object composition** (Sorter class contains a Timer object), **file I/O** to load test data, and **benchmarking** to compare algorithm efficiency across 4 file sizes: 500, 5,000, 25,000, and 100,000 elements.


## 🎯 Learning Objectives
- Working with **file I/O** using `<fstream>` library
- Understanding `ifstream` for reading file contents
- Implementing **three sorting algorithms** (Bubble, Selection, Insertion)
- Using **object composition** (Sorter HAS-A Timer)
- Reading files **twice** (count elements, then populate array)
- Understanding **algorithm efficiency** and Big-O notation
- **Benchmarking** code performance with timing measurements
- Managing **multiple header dependencies** (Sorter includes Timer)
- Using **arrays of strings** for file management
- Understanding **nullptr** for safe pointer initialization
___

## 📚 Technical Concepts
- **File I/O Pattern - Two-Pass Reading:**
  1. **First pass:** Open file, count elements using `eof()` (end-of-file), close file
  2. **Second pass:** Open file again, allocate array based on count, populate array, close file
  - This allows dynamic array sizing without knowing file size in advance
- **Object Composition:** The `Sorter` class contains a `Timer` object as a private member, demonstrating the "HAS-A" relationship (a Sorter HAS-A Timer)
- **Bubble Sort Algorithm:** Nested loops compare adjacent elements, swapping if out of order. Each pass "bubbles" the largest unsorted element to its final position. **Time Complexity:** O(n²)
- **Selection Sort Algorithm:** Finds the minimum element in unsorted portion, swaps it to the front. Builds sorted portion from left to right. **Time Complexity:** O(n²)
- **Insertion Sort Algorithm:** Takes each element and inserts it into its correct position in the sorted portion. Builds sorted portion from left to right. **Time Complexity:** O(n²)
- **Performance Analysis:** All three algorithms are O(n²), but have different constant factors:
  - Insertion Sort is typically fastest for nearly-sorted data
  - Bubble Sort is typically slowest
  - Selection Sort falls in between
- **Destructor for Dynamic Arrays:** `~Sorter()` checks if `fileArray != nullptr` before deleting to prevent deleting an unallocated pointer
- **Timer Integration:** Each sort method calls `Reset()`, `Start()`, then `Stop()`, storing elapsed time in dedicated variables (`bubbleTimer`, `selectionTimer`, `insertionTimer`)
- **Array Management:** String array `files[]` stores filenames, int array `sizes[]` stores element counts for display purposes
___

## 🚀 How to Compile and Run
**For Bash:**
```bash
# Navigate to the directory containing the project files 
cd /path/to/your/files

# Compile the program
g++ Race_Driver.cpp Sorter_Implementation.cpp Time_Implementation.cpp -o SortingRace

# Run the executable
./SortingRace       # On Linux / Mac
SortingRace.exe      # On Windows 
```
**For Visual Studio 2022:**
**For Visual Studio 2022:**
1. Create a new C++ Console Application project
2. Add all source files to the project:
   - Right-click on **Source Files** ➡️ Add ➡️ Existing Item ➡️ Select **Race_Driver.cpp**
   - Right-click on **Source Files** ➡️ Add ➡️ Existing Item ➡️ Select **Sorter_Implementation.cpp**
   - Right-click on **Source Files** ➡️ Add ➡️ Existing Item ➡️ Select **Time_Implementation.cpp**
   - Right-click on **Header Files** ➡️ Add ➡️ Existing Item ➡️ Select **Sorter.h**
   - Right-click on **Header Files** ➡️ Add ➡️ Existing Item ➡️ Select **Timer.h**
3. Add all NumFile text files to the project directory (same folder as .sln file)
4. Press **F5** to build and run with debugging, or **Ctrl + F5** to run without debugging
___

## 💡Key Features
- Tests three sorting algorithms on identical datasets
- Four progressively larger test files (500 to 100,000 elements)
- Automatic file reading and array population
- Independent timing for each algorithm
- Displays results in milliseconds with 3-decimal precision
- Demonstrates performance degradation with dataset size
- Uses object composition (Sorter contains Timer)
- Safe memory management with destructor and nullptr checks
- Results show insertion sort generally outperforms others
___

## 📸 Sample Output
```
Populating Arrays... <500 elements>
Sorting...
SORTS COMPLETE!
Elapsed Time <Bubble Sort>   : 0.000 milliseconds
Elapsed Time <Insertion Sort>: 0.000 milliseconds
Elapsed Time <Selection Sort>: 0.000 milliseconds

Populating Arrays... <5000 elements>
Sorting...
SORTS COMPLETE!
Elapsed Time <Bubble Sort>   : 42.000 milliseconds
Elapsed Time <Insertion Sort>: 11.000 milliseconds
Elapsed Time <Selection Sort>: 20.000 milliseconds

Populating Arrays... <25000 elements>
Sorting...
SORTS COMPLETE!
Elapsed Time <Bubble Sort>   : 1283.000 milliseconds
Elapsed Time <Insertion Sort>: 272.000 milliseconds
Elapsed Time <Selection Sort>: 479.000 milliseconds

Populating Arrays... <100000 elements>
Sorting...
SORTS COMPLETE!
Elapsed Time <Bubble Sort>   : 22045.000 milliseconds
Elapsed Time <Insertion Sort>: 4451.000 milliseconds
Elapsed Time <Selection Sort>: 7670.000 milliseconds

ANALYSIS COMPLETE... PRESS ANY KEY TO CONTINUE.
Press any key to continue
```

___

## 🧠 Challenges and Solutions
- The two-pass file reading pattern initially seemed inefficient - why read the file twice? Understanding that we need to know the array size BEFORE allocating memory clarified why this approach is necessary.
- Implementing three different sorting algorithms required careful attention to the nested loop logic for each. Testing with small datasets helped verify correctness before running on large files.
- Watching the dramatic time differences between 5,000 and 100,000 elements demonstrated O(n²) complexity in action - seeing theory become reality was eye-opening.
___

## 💭 Concepts Demonstrated 
- **File Input/Output:** Reading external data files into program memory
- **Algorithm Analysis:** Comparing performance characteristics of different approaches
- **Object Composition:** Using objects as members of other objects
- **Performance Benchmarking:** Measuring and comparing execution time
- **Dynamic Memory Management:** Allocating arrays based on runtime data
- **Multiple Algorithm Implementation:** Solving the same problem with different strategies