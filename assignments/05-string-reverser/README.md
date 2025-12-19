# Assignment 05: String Reverser
---
## 📋 Overview
The following program will utilize non-tail recursive technique to reverse a string input.
This will be done with restrictions stated by the instructor (one integer / one character declarative and no additional libraries).
___

## 🎯 Learning Objectives
- Understanding **Non-Tail Recursion**
- Working with `char*` and incrementing pointers
- Manipulating **C-Style Strings**
- Operating within instructor constraints
- Understanding **Null Terminators** 
- Using **Null Temporary Placement** to control recursion

___

## 📚 Technical Concepts
- **Pointer Arithmetic:** `*(pReverseMe + stringLength)` moves the pointer forward to access characters at different positions 
- **Non-Tail Recursion:** Recursion happens both before AND after the recursive call, using the call stack to reverse the string
- **Null Terminator Manipulation:** hides the already swapped characters by setting them to 0 so they do not get manipulated again
- **String Length Calculation:** a `while()` loop is used to count characters to help with limitation of helper functions like `strlen()`
- **Multiple Base Cases:** two base cases:
    1. `*pReverseMe == 0` signifies and empty string or end of string 
    2. `stringLength <= 1` signifies a single character or nothing to reverse 
- **Character Swapping:** saves the first character, replaces it with the last character, continues recursion, restores saved character to its new position 
___

## 🚀 How to Compile and Run
**For Bash:**
```bash
# Navigate to the directory containing ReverseStringDriver.cpp
cd /path/to/your/file

# Compile the program
g++ ReverseStringDriver.cpp -o ReverseStringDriver

# Run the executable
./ReverseStringDriver        # On Linux / Mac
ReverseStringDriver.exe      # On Windows 
```
**For Visual Studio 2022:**
1. Create a new C++ Console Application project
2. Replace the default code with **ReverseStringDriver.cpp**
3. Press **F5** to build and run with debugging, or **Ctrl+F5** to run without debugging 
___

## 💡Key Features
- Reverse a string without creating a copy
- Use instructor limitation: one integer and one character variable
- Implements recursion without helper functions or additional libraries
- Handles strings of any length
- Demonstrates frame stack manipulation for string reversal

___

## 📸 Sample Output
```
The string contains:
onamonapea

CALL THE REVERSING FUNCTION

The string contains:
aepanomano
Press any key to continue...

```


___

## 🧠 Challenges and Solutions
- Expanding on recursion with Non-Tail recursion challenged my understanding of frame stacks and how they worked. During this learning process the instructor demonstrated how to debug the program and watch the frame stacks in action to truly understand what is happening in this scenario. 
- Understanding how to manipulate a pointer position with basic math was an unexpected concept to learn and helped provide insight on future applications of how to use pointers 
- Having resource limitations provided a true problem / solution experience. Being used to freely choose any possible solution to a problem can be spoiling when learning as this is not how the professional environment will be.

___

## 💭 Concepts Demonstrated 
- **Non-Tail Recursion:** work performed before and after recursive calls, utilizing the call stack
- **Pointer Arithmetic:** navigating memory addresses to access string characters
- **In-Place Manipulation:** modifying data without additional storage 
- **Constraint-Based Problem Solving:** meeting solution requirements with limited resources 