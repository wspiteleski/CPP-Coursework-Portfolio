# Assignment 06: Triangle Calculator 
---
## 📋 Overview
This object oriented program uses class syntax and is responsible for instantiating the triangle object 
and organizing logic to produce a triangle display and the pythagorean theorem results including:
hypotenuse, area, and perimeter based on the data entered for adjacent and opposite side 
lengths
___

## 🎯 Learning Objectives
- Implementing the **three-file OOP structure** for assignments
- Using **getters and setters** for controlled data access
- Understanding the **`this->` pointer** for accessing object members
- Creating **constructors** to initialize object state
- Implementing **boolean return values** for input validation
- Using the `<cmath>` library's `sqrt()` function for calculations
- Designing **methods that calculate derived values** (hypotenuse from sides)
- Understanding **private vs public** class members
___

## 📚 Technical Concepts
- **Three-File Class Structure:**
  1. **Specification (.h):** Declares the Triangle class interface with private data members and public methods
  2. **Implementation (.cpp):** Defines how each method works
  3. **Driver (.cpp):** Instantiates the Triangle object and uses its methods
- **The `this->` Pointer:** Used to explicitly reference the object's own data members (e.g., `this->oppositeSide`). While not always required, it clarifies when accessing member variables versus parameters.
- **Getters and Setters Pattern:**
  - **Getters** (`getOppositeSide()`, `getHypotenuse()`) provide read-only access to private data
  - **Setters** (`setOppositeSide()`, `setAdjacentSide()`) validate input before modifying private data
- **Boolean Validation:** Setters return `true` if the value is accepted or `false` if rejected (e.g., negative numbers), allowing the caller to check if the operation succeeded
- **Constructor Initialization:** The `Triangle()` constructor sets all member variables to safe default values (0.0) following secure programming practices
- **Calculated Properties:** The `getHypotenuse()`, `getArea()`, and `getPerimeter()` methods calculate values on-the-fly using the Pythagorean theorem and geometry formulas rather than storing them
- **Encapsulation:** Private members (`oppositeSide`, `adjacentSide`, etc.) prevent direct manipulation, ensuring values can only be changed through validated setter methods
___

## 🚀 How to Compile and Run
**For Bash:**
```bash
# Navigate to the directory containing the project files 
cd /path/to/your/files

# Compile the program
g++ triangleDriver.cpp triangleImplementation.cpp -o triangleCalculator

# Run the executable
./triangleCalculator       # On Linux / Mac
triangleCalculator.exe      # On Windows 
```
**For Visual Studio 2022:**
1. Create a new C++ Console Application project
2. Add all three files to the project:
   - Right-click on **Source Files** ➡️ Add ➡️ Existing Item ➡️ Select **triangleDriver.cpp**
   - Right-click on **Source Files** ➡️ Add ➡️ Existing Item ➡️ Select **triangleImplementation.cpp**
   - Right-click on **Header Files** ➡️ Add ➡️ Existing Item ➡️ Select **triangleSpecification.h**
3. Press **F5** to build and run with debugging, or **Ctrl + F5** to run without debugging
___

## 💡Key Features
- Object-oriented triangle calculator using proper encapsulation
- Input validation prevents negative side lengths through boolean setters
- Calculates hypotenuse using the Pythagorean theorem: √(a² + b²)
- Computes area using the formula: (opposite × adjacent) / 2
- Computes perimeter by summing all three sides
- ASCII art triangle display with formatted output
- Conditional formatting for whole numbers vs decimals in display
___

## 📸 Sample Output
```
                    *
                    **
                    * *
                    *  *
                    *   *
Opposite Side = 4.6 *    *   Hypotenuse Side = 9.5
                    *     *
                    *      *
                    *       *
                    **********

                    Adjacent Side = 8.3

The area of the triangle is     : 19
The perimeter of the triangle is: 22
Press any key to continue

```
- To interact with this calculator:
    - Alter line 17: `if (newTriangle.setOppositeSide(4.6) == false) {` **4.6** to desired value 
    - Alter line 21: `if (newTriangle.setAdjacentSide(8.3) == false) {` **8.3** to desired value 
___

## 🧠 Challenges and Solutions
- Understanding the purpose of getters and setters seemed redundant at first - why not just access the variables directly? Learning about encapsulation and data protection helped clarify why this pattern exists.
- The `this->` pointer was initially confusing. Understanding it points to the current object's own data members took practice.
___

## 💭 Concepts Demonstrated 
- **Encapsulation:** Protecting data through private access modifiers and public interfaces
- **Getters and Setters:** Controlled access pattern for class data members
- **Input Validation:** Using boolean returns to communicate success/failure
- **Object Lifecycle:** Constructor initialization of object state
- **Separation of Interface and Implementation:** Dividing class declaration (.h) from definition (.cpp)