# Assignment 03: Sliding Tile Puzzle 
---
## 📋 Overview
An introduction to imperative program paradigm, pseudo-random program behavior, and Windows API calls. The assignment contained starter code for students to build upon for the final output provided by the instructor. `printTheRainbow()` method was provided by instructor to demonstrate API color calls.
___

## 🎯 Learning Objectives
- Using the `<windows.h>` library
- Process API calls with `HANDLE` 
- Use `cls(HANDLE hConsole)` function API to clear the screen 
- Implementing **Recursion** for controlled repetition with a base case
- Seed pseudo-random behavior with `srand(time(NULL))` 
- Use prototype methods for a refined program architecture 

___

## Technical Concepts
- **API Calls and Handling:** call upon Windows-specific library to:
  1. change text colors with `SetConsoleTextAttribute()`
  2. clear the screen with `cls()` API
  3. get console handle with `GetStdHandle(STD_OUTPUT_HANDLE)`
- **Pseudo-Random Behavior:** utilize random behavior by:
  1. seeding with `srand(time(NULL))`; pulling a value from the computer clock to apply a random like outcome 
  2. obtaining a set possibility with `rand() % 4 + 1`. The modulo operation gives us 0-3 and adding one gives use the possibility of 1-4, mapping our four directions (UP, DOWN, LEFT, and RIGHT)
- **Recursion:** `ScrambleMoves()` calls upon itself until a specified number of moves is achieved. Each time a move is made `moves - 1` occurs until the base case of zero is reached.
- **Boolean Returns:** `SlideTile()` establishes the rules of a legal move with true/false returns to validate a user input while preventing illegal moves 
- **Game State Logic:** `isBoardSolved` establishes the rules for a win condition with boolean returns

___

## 🚀 How to Compile and Run
**For Bash:**
```bash
# Navigate to the directory containing SlidingTileGame.cpp
cd /path/to/your/file

# Compile the program
g++ SlidingTileGame.cpp -o SlidingTileGame

# Run the executable
./SlidingTileGame        # On Linux / Mac
SlidingTileGame.exe      # On Windows 
```
**For Visual Studio 2022:**
1. Create a new C++ Console Application project
2. Replace the default code with **SlidingTileGame.cpp**
3. Press **F5** to build and run with debugging, or **Ctrl+F5** to run without debugging 
___

## 💡Key Features
- Initializes a solved 3 x 3 sliding puzzle game board
- Scrambles game board using recursive random moves 
- Color coded tiles represent correct positioning (green) and incorrect positioning (red)
- Validate user moves by preventing illegal tile slides 
- Clear and refresh screen after each move 
- Determine when the puzzle is solved and terminate 

___

## 📸 Sample Output

The program will initialized a solved board. Green numbers indicate a correctly positioned number. With user initiation, the board will scramble
```
  1  2  3
  4  5  6
  7  8  *
isBoardSolved(): true
Press any Key to begin...

Scrambling the tiles...
Scrambling complete, press any key to begin solving.

```
Once Scrambled, board state displays false and controls are displayed to the user. While correct numbers remain green, incorrect positioned numbers will be red.
```
  *  1  3
  4  2  5
  7  8  6
isBoardSolved(): false

<W -> UP  :  A -> LEFT  :  S -> DOWN  :  D -> RIGHT  :  >
Which Way To Slide:

```
Once solved, board state displays true and all numbers are green. Pressing enter after a solve will terminate the program.
```
  1  2  3
  4  5  6
  7  8  *
isBoardSolved(): true

<W -> UP  :  A -> LEFT  :  S -> DOWN  :  D -> RIGHT  :  >
Which Way To Slide:

```

___

## 🧠 Challenges and Solutions
- Calling and handling API's for the first time was a little confusing and tricky at first. New syntax and purpose with a higher level challenge seemed daunting at first. I chose to break this project down into sections to help process the new content and ideas being taught. 
- Modulo was strange to get used to, it was easy to want to percieve it as division until understanding what is actually happening. To help picture the concept I think of a fixed possibility situation, like rolling a dice, and how we are looking for a sepcific side of the dice + 1 because of the possibility of 0 remainders. 
- Practicing prototyping within a imperative program really expanded my thoughts on what can be accomplished in a imperative program.
- Recursion can be a difficult concept, especially depending on the complexity of its use. An instructor provided lecture showed how recursion works in a visible format that I referenced regularly when using it. 

___

## 💭 Concepts Demonstrated 
- **API Calls:** Using Windows-specific libraries for console manipulation
- **Random Behavior:** Seeding and generating pseudo-random numbers for scrambling
- **Prototyping:** Organizing and refining program architecture with modular functions 
- **Recursion:** Self-calling function with base case for controlled repetition 