# Assignment 08: Vector Calculator with Operator Overloading 
---
## 📋 Overview
This Object Oriented Program is responsible for instantiating and organizing the logic to produce a vector calculator for magnitude with operator overloading practices. This program includes starter code from the instructor as a starting off point.
___

## 🎯 Learning Objectives
- Understanding **operator overloading** fundamentals
- Overloading arithmetic operators (`+`, `-`)
- Overloading assignment operator (`=`)
- Overloading stream insertion operator (`<<`)
- Using **friend functions** for operator access to private members
- Understanding **`ostream&` return type** for chaining operations
- Implementing **vector mathematics** (addition, subtraction)
- Calculating **vector magnitude** using the distance formula
___

## 📚 Technical Concepts
- **Operator Overloading Syntax:** Redefining operators to work with custom objects. Format: `ReturnType operator SYMBOL(parameters)`
  - Example: `Vector operator+(Vector addMe)` makes the `+` operator work with Vector objects
- **Assignment Operator (`=`):** `void operator=(Vector value)` allows vector assignment like `mySecondVector = myFirstVector`, copying the x and y components
- **Addition Operator (`+`):** `Vector operator+(Vector addMe)` creates a new vector by adding corresponding components: `<x₁+x₂, y₁+y₂>`
- **Subtraction Operator (`-`):** `Vector operator-(Vector subtractMe)` creates a new vector by subtracting corresponding components: `<x₁-x₂, y₁-y₂>`
- **Stream Insertion Operator (`<<`):** `friend ostream& operator<<(ostream& outputStream, Vector& theVector)` allows vectors to be printed directly with `cout <<`
- **Friend Functions:** The `friend` keyword grants the `<<` operator access to private members (`_v_x`, `_v_y`) even though it's not a class member function
- **Return by Reference (`ostream&`):** Returning a reference to the output stream enables **chaining**: `cout << vector1 << vector2 << endl;`
- **Magnitude Calculation:** Uses the distance formula: `√(x² + y²)` to compute vector length, recalculated whenever components change
- **Helper Methods:** `CalculateMagnitude()` is private and called automatically by setters and constructors to keep magnitude updated
___

## 🚀 How to Compile and Run
**For Bash:**
```bash
# Navigate to the directory containing the project files 
cd /path/to/your/files

# Compile the program
g++ VectorDriver.cpp VectorImplementation.cpp -o VectorCalculator

# Run the executable
./VectorCalculator       # On Linux / Mac
VectorCalculator.exe      # On Windows 
```
**For Visual Studio 2022:**
1. Create a new C++ Console Application project
2. Add all three files to the project:
   - Right-click on **Source Files** ➡️ Add ➡️ Existing Item ➡️ Select **VectorDriver.cpp**
   - Right-click on **Source Files** ➡️ Add ➡️ Existing Item ➡️ Select **VectorImplementation.cpp**
   - Right-click on **Header Files** ➡️ Add ➡️ Existing Item ➡️ Select **VectorSPecification.h**
3. Press **F5** to build and run with debugging, or **Ctrl + F5** to run without debugging
___

## 💡Key Features
- Vector object with x and y components
- Automatic magnitude calculation using the Pythagorean theorem
- Operator overloading for natural mathematical syntax
- Assignment operator allows vector copying
- Addition and subtraction operators for vector math
- Stream insertion operator for easy display output
- Magnitude updates automatically when components change
- Demonstrates both member and friend function overloading
___

## 📸 Sample Output
```
My vector: <4, 5>
My vector added to itself: <8, 10>
My vector subtracted by itself: <0, 0>

```
- To interact with this calculator:
    - Alter line 11: `Vector myFirstVector(4, 5);` **4.5** to desired vector 
___

## 🧠 Challenges and Solutions
- Operator overloading syntax was initially confusing - using `operator+` as a function name felt strange at first. Understanding this is just special syntax to teach C++ how operators work with custom types helped clarify the concept.
- The friend function for `<<` was particularly tricky. Understanding why it needs access to private members and why it can't be a regular member function took careful study of the examples provided to me. 
___

## 💭 Concepts Demonstrated 
- **Operator Overloading:** Extending built-in operators to work with custom objects
- **Friend Functions:** Granting external functions access to private class members
- **Return by Reference:** Enabling operation chaining through reference returns
- **Automatic Recalculation:** Keeping derived values (magnitude) synchronized with base data
- **Vector Mathematics:** Implementing mathematical operations programmatically