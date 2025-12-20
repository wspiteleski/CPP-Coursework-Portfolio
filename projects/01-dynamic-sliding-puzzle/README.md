# Project 01: Dynamic Sliding Puzzle
---
## 📋 Overview
An introduction to **Object-Oriented Programming (OOP)** principles by rebuilding Assignment 03's sliding tile puzzle using a class-based architecture. This project demonstrates the **three-file design pattern** (driver, implementation, specification), **constructor overloading**, **dynamic memory management with destructors**, and **scalable board dimensions** determined by user input.
___

## 🎯 Learning Objectives
- Understanding **Object-Oriented Programming** fundamentals
- Implementing the **three-file architecture** (Driver, Implementation, Specification)
- Using **constructor overloading** (default 3 X 3 and custom size constructors)
- Managing dynamic memory with **destructors** (`~SlidingPuzzle()`)
- Working with **encapsulation** (private data members, public methods)
- Understanding **class member access** (public vs private)
- Implementing **scalable board dimensions** using user input
- Using **preprocessor guards** (`#ifndef`, `#define`, `#endif`) to prevent multiple inclusions

___

## 📚 Technical Concepts
- **Three-File Architecture:**
  1. **Specification (.h):** Declares the class interface (what the class can do)
  2. **Implementation (.cpp):** Defines how the methods actually work
  3. **Driver (.cpp):** Uses the class to run the program
- **Constructor Overloading:** Two constructors for the `SlidingPuzzle` class:
  1. `SlidingPuzzle()` - Creates default 3 X 3 board
  2. `SlidingPuzzle(int width, int height)` - Creates custom-sized board based on user input
- **Destructor:** `~SlidingPuzzle()` automatically deallocates the dynamic 2D array when the object goes out of scope, preventing memory leaks
- **Encapsulation:** Private data members (`ppTheBoard`, `numRows`, `numCols`) are protected from direct manipulation. Public methods (`PrintBoard()`, `slideTile()`, etc.) control how the board is accessed and modified.
- **Dynamic Scalability:** Unlike Assignment 03's fixed 3 X 3 size, the board dimensions are allocated at runtime based on user input, making the puzzle work with any size 
- **Preprocessor Guards:** `#ifndef _GAME_BOARD_` prevents the header file from being included multiple times, avoiding redefinition errors
- **Input Validation with cin.fail():** Detects malformed input (non-integer characters) and uses `cin.clear()` and `rewind(stdin)` to purge invalid data
___

## 🚀 How to Compile and Run
**For Bash:**
```bash
# Navigate to the directory containing the project files 
cd /path/to/your/files

# Compile the program
g++ SlidiingPuzzleDriver.cpp SlidingPuzzleImplementation.cpp -o SlidingPuzzle

# Run the executable
./SlidingPuzzle       # On Linux / Mac
SlidingPuzzle.exe      # On Windows 
```
**For Visual Studio 2022:**
1. Create a new C++ Console Application project
2. Add all three files to the project:
   - Right-click on **Source Files** ➡️ Add ➡️ Existing Item ➡️ Select **SlidingPuzzleDriver.cpp**
   - Right-click on **Source Files** ➡️ Add ➡️ Existing Item ➡️ Select **SlidingPuzzleImplementation.cpp**
   - Right-click on **Header Files** ➡️ Add ➡️ Existing Item ➡️ Select **SlidingPuzzleSpecification.h**
3. Press **F5** to build and run with debugging, or **Ctrl + F5** to run without debugging
___

## 💡Key Features
- Object-oriented design with proper encapsulation
- User-customizable board size (minimum 3×3, scalable to any dimension)
- Two constructor options: default 3×3 or custom dimensions
- Automatic memory management through destructor
- Input validation for both size selection and game moves
- Color-coded tiles (green = correct, red = incorrect)
- Quit option (Q) to exit game mid-play
- Screen clearing and board refresh after each move
___

## 📸 Sample Output
Prompt the user to enter how many rows and columns they want their puzzle to contain
```
Please enter the number of columns you would like (at least 3): 5
Please enter the number of rows you would like (at least 3): 5
  1  2  3  4  5
  6  7  8  9 10
 11 12 13 14 15
 16 17 18 19 20
 21 22 23 24  *

Press any key to begin.

```
System scrambles the tile for the user 
```
Please enter the number of columns you would like (at least 3): 5
Please enter the number of rows you would like (at least 3): 5
  1  2  3  4  5
  6  7  8  9 10
 11 12 13 14 15
 16 17 18 19 20
 21 22 23 24  *

Press any key to begin.
Scrambling the tiles...
Scrambling complete, press any key to begin solving.

```

Scrambled puzzle is presented to the user along with controls used to solve it
```
 1  2  3  4  5
  6  7  8  9 10
 11 12 13 14 15
 16 17 18  * 20
 21 22 23 19 24

<W -> UP  :  A -> LEFT  :  S -> DOWN  :  D -> RIGHT  :  Q -> Quit  :>
Which Way To Slide:

```
Win Condition is presented to the user when puzzle is solved
```
  1  2  3  4  5
  6  7  8  9 10
 11 12 13 14 15
 16 17 18 19 20
 21 22 23 24  *

CONGRATULATIONS! YOU SOLVED THE PUZZLE!
Press any key to exit...

```

## 🧠 Challenges and Solutions
- Transitioning from imperative programming to OOP required a mental shift. Understanding that data and functions now live together as a cohesive "object" took time to fully grasp.
- The three-file architecture was initially confusing - figuring out what declarations go in the .h file versus definitions in the .cpp file required careful attention.
- Determining what should exist as **private** vs **public** was a new concept that required careful consideration when implementing 

___

## 💭 Concepts Demonstrated 
- **Object-Oriented Design:** Organizing code around objects with data and behaviors
- **Encapsulation:** Protecting data through private access and public interfaces
- **Constructor/Destructor Lifecycle:** Automatic initialization and cleanup of objects
- **Separation of Concerns:** Dividing program logic across driver, implementation, and specification
- **Scalable Architecture:** Designing systems that adapt to different requirements
- **Robust Input Handling:** Validating and sanitizing user input to prevent program crashes