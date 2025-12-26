# Assignment 07: Lucas Jump Puzzle 
---
## 📋 Overview
This object oriented program uses class syntax and is responsible for instantiating and organizing the logic to produce a **GAME BOARD** object to represent the classic Lucas Jump puzzle.
___

## 🎯 Learning Objectives
- Implementing **game logic** with directional movement rules
- Using **arrays to represent game state** (`char board[7]`)
- Creating **multiple boolean methods** for state detection (`isSolved()`, `isGimp()`, `move()`)
- Understanding **complex conditional logic** for move validation
- Managing **game state updates** (tracking empty slot position)
- Implementing **jump mechanics** (tokens can leap over adjacent tokens)
- Using **iterative validation** to check all possible moves
___

## 📚 Technical Concepts
- **Game Board Representation:** A `char board[7]` array stores the game state with 'B' for blue tokens, 'R' for red tokens, and '*' for the empty slot
- **Empty Slot Tracking:** The `emptySlot` integer tracks which position is currently empty, allowing efficient move validation without searching the array
- **Directional Movement Rules:**
  - Blue tokens ('B') can only move **right** (positions must be left of or equal to empty slot)
  - Red tokens ('R') can only move **left** (positions must be right of or equal to empty slot)
- **Move Validation Logic:** The `move()` method checks four conditions for legal moves:
  1. Position is adjacent to empty slot (slide move)
  2. Position is two spaces away with a token in between (jump move)
  3. Token color matches allowed direction (B right, R left)
  4. Position is within board boundaries (0-6)
- **Win Condition Detection:** `isSolved()` checks if the board matches the exact win state: `R R R * B B B`
- **Gimp State Detection:** `isGimp()` iterates through all positions checking if ANY legal move exists. If no moves are possible, the puzzle is unsolvable from the current state
- **State Update Pattern:** After a valid move, three things update:
  1. Empty slot receives the moving token
  2. Moving token's position becomes empty ('*')
  3. `emptySlot` variable updates to the new empty position
___

## 🚀 How to Compile and Run
**For Bash:**
```bash
# Navigate to the directory containing the project files 
cd /path/to/your/files

# Compile the program
g++ LucasJumpDriver.cpp LucasJumpImplementation.cpp -o LucasJump

# Run the executable
./LucasJump       # On Linux / Mac
LucasJump.exe      # On Windows 
```
**For Visual Studio 2022:**
1. Create a new C++ Console Application project
2. Add all three files to the project:
   - Right-click on **Source Files** ➡️ Add ➡️ Existing Item ➡️ Select **LucasJumpDriver.cpp**
   - Right-click on **Source Files** ➡️ Add ➡️ Existing Item ➡️ Select **LucasJumpImplementation.cpp**
   - Right-click on **Header Files** ➡️ Add ➡️ Existing Item ➡️ Select **LucasJumpSPecification.h**
3. Press **F5** to build and run with debugging, or **Ctrl + F5** to run without debugging
___

## 💡Key Features
- Fixed 7-position game board with 3 blue tokens, 3 red tokens, and 1 empty space
- Directional movement constraints (blue moves right only, red moves left only)
- Jump mechanics allowing tokens to leap over one adjacent token
- Move validation prevents illegal moves and prompts retry
- Win condition detection when all tokens are in opposite positions
- Gimp state detection when puzzle becomes unsolvable
- Color-coded visual display (blue tokens, red tokens, white empty space)
- Screen clearing and board refresh after each move
___

## 📸 Sample Output
The program introduces the user to the board layout, color coded visuals for blue and red tokens, and explains the parameters in place to solve the puzzle. 
```
Positions:    0  1  2  3  4  5  6

Board:        B  B  B  *  R  R  R

Objective:
Move all blue tokens into red spaces, and red tokens into blue spaces

Rules:
1.) Select a position with either a red or blue token to move.
2.) Blue can only move right and red can only move left
3.) Tokens can jump one additional token when moving

Press any key to begin the game...

```
The program requests a number based input from the user to process a move
```

_________LUCAS JUMP GAME_________

Positions:    0  1  2  3  4  5  6

Board:        B  B  B  *  R  R  R

Enter the token you would like to move (you cannot move the *):

```
The program will identify if the user has entered a gimp / unsolvable state and display a game over message to the user followed by program termination.
```

_________LUCAS JUMP GAME_________

Positions:    0  1  2  3  4  5  6

Board:        R  *  B  B  B  R  R
You have run out of possible moves...GAME OVER

```
If the win condition is met the user will be congratulated for solving the puzzle before the program terminates.
```

_________LUCAS JUMP GAME_________

Positions:    0  1  2  3  4  5  6

Board:        R  R  R  *  B  B  B
Victory!!! you have solved the Lucas Jump Puzzle

```
___

## 🧠 Challenges and Solutions
- The `move()` method's logic was complex with four different validation conditions. Breaking it down into individual if-else cases and testing each type of move separately helped me understand how they worked together.
- Understanding `isGimp()` required thinking differently - instead of checking if ONE move is valid, I needed to check if ANY move exists by testing all positions.
___

## 💭 Concepts Demonstrated 
- **Game State Management:** Tracking and updating game configuration across player actions
- **Complex Boolean Logic:** Combining multiple conditions to determine move validity
- **Iterative Validation:** Checking all possibilities to determine available options
- **State Detection Algorithms:** Identifying win and unsolvable conditions programmatically
- **Directional Constraints:** Implementing rules that restrict movement based on token type