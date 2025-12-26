# Assignment 09: Fraction Calculator with Operator Overloading 
---
## 📋 Overview
This Object Oriented Program is responsible for instantiating and organizing the logic to produce a vector calculator for magnitude with operator overloading practices. The objective of this assignment was to build on the concept of overloading learned while completing the Vector Calculator (assingment 08).

## 🎯 Learning Objectives
- Expanding operator overloading to **four arithmetic operators** (`+`, `-`, `*`, `/`)
- Implementing **recursive algorithms** (Greatest Common Divisor)
- Understanding **automatic fraction reduction** to lowest terms
- Using **meaningful boolean returns** from setters for validation
- Applying **fraction mathematics** formulas programmatically
- Preventing **division by zero** in denominator validation
- Working with **helper methods** (`FindGCD()`, `Reduce()`)
___

## 📚 Technical Concepts
- **Recursive GCD Algorithm:** `FindGCD(int a, int b)` uses recursion to find the Greatest Common Divisor:
  - **Base case:** If `b == 0`, return `a` (current divisor is the GCD)
  - **Recursive case:** Return `FindGCD(b, a % b)` (swap values, use remainder)
  - Example: GCD(8, 12) → GCD(12, 8) → GCD(8, 4) → GCD(4, 0) → returns 4
- **Automatic Reduction:** `Reduce()` is called automatically after every setter and constructor operation to ensure fractions are always in lowest terms
- **Boolean Setter Validation:** Unlike Assignment 08's void setters, these return `true`/`false`:
  - `SetNumerator()` always returns `true` (any integer is valid)
  - `SetDenominator()` returns `false` if value is 0 (division by zero prevention), `true` otherwise
- **Fraction Addition:** Formula: `a/b + c/d = (a×d + c×b) / (b×d)`
  - Cross-multiply numerators, add results, multiply denominators
- **Fraction Subtraction:** Formula: `a/b - c/d = (a×d - c×b) / (b×d)`
  - Cross-multiply numerators, subtract results, multiply denominators
- **Fraction Multiplication:** Formula: `a/b × c/d = (a×c) / (b×d)`
  - Multiply numerators together, multiply denominators together
- **Fraction Division:** Formula: `a/b ÷ c/d = (a×d) / (b×c)`
  - Multiply by reciprocal (flip second fraction and multiply)
  - Includes validation to prevent dividing by a fraction with numerator of 0
- **Helper Method Pattern:** Private methods (`FindGCD()`, `Reduce()`) handle internal calculations that users don't need to call directly
___

## 🚀 How to Compile and Run
**For Bash:**
```bash
# Navigate to the directory containing the project files 
cd /path/to/your/files

# Compile the program
g++ FractionDriver.cpp FractionImplementation.cpp -o FractionCalculator

# Run the executable
./FractionCalculator       # On Linux / Mac
FractionCalculator.exe      # On Windows 
```
**For Visual Studio 2022:**
1. Create a new C++ Console Application project
2. Add all three files to the project:
   - Right-click on **Source Files** ➡️ Add ➡️ Existing Item ➡️ Select **FractionDriver.cpp**
   - Right-click on **Source Files** ➡️ Add ➡️ Existing Item ➡️ Select **FractionImplementation.cpp**
   - Right-click on **Header Files** ➡️ Add ➡️ Existing Item ➡️ Select **FractionSpecification.h**
3. Press **F5** to build and run with debugging, or **Ctrl + F5** to run without debugging
___

## 💡Key Features
- Four arithmetic operators overloaded (`+`, `-`, `*`, `/`)
- Automatic reduction to lowest terms after every operation
- Recursive GCD algorithm for finding common divisors
- Division by zero prevention with boolean validation
- Meaningful boolean returns from setters (communicates success/failure)
- Stream insertion operator for formatted display `<numerator/denominator>`
- Default constructor creates safe 0/1 fraction
- Custom constructor validates denominator before creation
___

## 📸 Sample Output
```
<3/4> + <1/2> = <5/4>
<3/4> - <1/2> = <1/4>
<3/4> * <1/2> = <3/8>
<3/4> / <1/2> = <3/2>
My first fraction now equals my second fraction: <1/2>

SETTER TESTING
My test fraction is: <5/6>
SetDenominator() is valid: <5/9>
SetDenominator(0) is invalid

```
- To interact with this calculator:
    - Alter line 12: `Fraction myFirstFraction(3, 4);` **(3, 4)** to desired fraction 
    - Alter line 13: `Fraction myFirstFraction(1, 2);` **(1, 2)** to desired fraction
    - Alter line 14: `Fraction myFirstFraction(5, 6);` **(5, 6)** to desired fraction
___

## 🧠 Challenges and Solutions
- The recursive GCD algorithm was initially difficult to visualize. Tracing through examples on paper (like GCD(8,12)) helped me understand how the base case and recursive case work together.
- Fraction division required careful thought - understanding to multiply by the reciprocal and validate the divisor's numerator isn't zero took deliberate consideration.
___

## 💭 Concepts Demonstrated 
- **Recursive Algorithms:** Self-calling functions with base cases for mathematical computations
- **Automatic Data Normalization:** Keeping data in standard form (reduced fractions) transparently
- **Comprehensive Operator Overloading:** Implementing full arithmetic operation suite
- **Meaningful Return Values:** Using boolean returns to communicate operation success/failure
- **Mathematical Formula Implementation:** Translating fraction arithmetic rules into code
- **Edge Case Handling:** Preventing invalid operations (division by zero)