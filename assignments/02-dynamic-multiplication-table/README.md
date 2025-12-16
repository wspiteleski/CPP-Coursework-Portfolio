# Assignment 02: Dynamic Multiplication Table
---
## 📋 Overview
An introduction to dynamic design patterns including: **2d arrays**, **double pointers**, and **data management** by producing a dynamic multiplication table. The user is prompted to enter a number of rows and columns (a maximum of 10 X 10) to display the appropriate size table with an aesthetically pleasing format.
___

## 🎯 Learning Objectives
- Using the `<iomanip>` library
- Using `setw()` function for uniform spacing and aesthetic to table output 
- Using the `<conio.h>` library
- Using `getch()` function to control program closure for user experience  
- Dynamic memory allocation using `new` and `delete[]`
- Working with double pointers (`int**`) for 2D structures
- Creating and Managing 2D arrays at runtime
- Implementing nested loops for row / column iteration
- Input validation with while loops
- Memory management to prevent memory leaks 

___

## 📚 Technical Concepts
- **Double Pointers:** `int** ppTimesTable` uses a pointer to pointer structure to build the dynamic 2D array 
- **Dynamic 2D Arrays:** created with a two-step allocation process:
  1. allocate an array of pointers (the rows): `ppTimesTable = new int*[rows]` 
  2. allocate an integer array for each row: `ppTimesTable[numRow] = new int[columns]`
- **Nested Loops:** used to apply loop logic during a specific condition until met 
- **Array Indexing:** `ppTimesTable[numRow][numCol] = (numRow + 1) * (numCol + 1)` accounts for array zero-indexing
- **Memory Deallocation:** delete in reverse order to prevent losing access to the row of pointers before cleaning their memory by deleting each row's integer array (`delete[] ppTimesTable[numRow]`), then deleting the array of row pointers (`delete[] ppTimesTable`).
- **Input Validation:** use the condition `while(rows < 1 || rows > 10)` and `while(columns < 1 || columns > 10)` to create an appropriate range the user to operate in


___

## 🚀 How to Compile and Run
**For Bash:**
```bash
# Navigate to the directory containing dynamictable.cpp
cd /path/to/your/file

# Compile the program
g++ dynamictable.cpp -o dynamictable

# Run the executable
./dynamictable        # On Linux / Mac
dynamictable.exe      # On Windows 
```
**For Visual Studio 2022:**
1. Create a new C++ Console Application project
2. Replace the default code with **dynamictable.cpp**
3. Press **F5** to build and run with debugging, or **Ctrl+F5** to run without debugging 
___

## 💡Key Features
- Prompts user for input on desired size table 
- Validates user input to prevent invalid table sizes 
- Uses dynamic memory allocation to create tables of any size (up to 10 X 10)
- Outputs number of rows and columns requested by user along with their content 
- Shows correct program termination with return value
- Effectively manages memory usages with a core dynamic design pattern 

___

## 📸 Sample Output
```
Please enter a number of rows on the interval [1, 10]: 5

Please enter a number of columns on the interval [1, 10]: 6

   |  1|  2|  3|  4|  5|  6
---+---+---+---+---+---+----
  1|  1|  2|  3|  4|  5|  6
---+---+---+---+---+---+----
  2|  2|  4|  6|  8| 10| 12
---+---+---+---+---+---+----
  3|  3|  6|  9| 12| 15| 18
---+---+---+---+---+---+----
  4|  4|  8| 12| 16| 20| 24
---+---+---+---+---+---+----
  5|  5| 10| 15| 20| 25| 30
Press and key to continue. . .

```
___

## 🧠 Challenges and Solutions
- After an 8 year hiatus from schooling, I had to relearn proper program formatting and documentation. My initial submission was messy with little to no explanation, but after great instructor guidance, I was able to produce the clean and legable version you see today. It was here I learned the importance of proper documentation that would assist me through the remainder of this course as I was able to easily reference previous assignments when attempting new challenges.
- Understanding dynamic design patterns was frustrating at first, after taking to pen and paper I was able to draw out what was happening to better understand the concept.
- Minor flaws for aesthetics could be overwhelming at times, truly understanding the **loops** and **conditions** I was creating to produce an aestheically pleasing display took careful consideration and gave insight to how they actually work.

___

## 💭 Concepts Demonstrated 
- **Nested Looping:** Understanding how a condition is applied and how a loop interacts with the condition when nested 
- **Input Validation:** Practicing secure programming strategies that prevent the user from attempting to operate outside of the programs parameters while also guiding the user with thourough instructions
- **Manual Memory Management:** Using `delete[]` to manually deallocate dynamic memory and prevent memory leaks 