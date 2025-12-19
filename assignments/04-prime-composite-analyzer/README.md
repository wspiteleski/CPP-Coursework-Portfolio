# Assignment 04: Prime / Composite Analyzer  
---
## 📋 Overview
The following program will use decision making, iteration, number theory, and advanced loop techniques to identify a non-negative integer as prime, composite, or neither while providing prime factorization for composite integers.
___

## 🎯 Learning Objectives
- Using the `<cmath>` library
- Calculate the square root of a number with `sqrt()` function
- Incorporate boolean values for program decision making 
- Apply basic number theory to identify prime and composite numbers 

___

## 📚 Technical Concepts
- **Square Root Optimization:** loops only check divisors up to `sqrt(userNumber)` because if it has a divisor larger than the square root, it naturally has a corresponding smaller divisor
- **Boolean Flags:** `primeNumber` acts as a flag signaling if the value is true or false, which determines if the value is prime or composite
- **Modulo for Divisibility:** `userNumber % divisor == 0` identifies remainders, 0 identifies a factor by representing an even division
- **Break Statement:** `break` is used to exit the loop since we know the program no longer needs to look for a composite 
- **Prime Factorization Algorithm:** `while` loop divides each prime factor until no longer an even division, then continues with the next potential factor 
- **Input Boundaries:** Numbers less than 2 are neither prime nor composite, requiring validation to ensure the mathematical definition is kept in tact 
___

## 🚀 How to Compile and Run
**For Bash:**
```bash
# Navigate to the directory containing PrimeCompositeDriver.cpp
cd /path/to/your/file

# Compile the program
g++ PrimeCompositeDriver.cpp -o PrimeCompositeDriver

# Run the executable
./PrimeCompositeDriver        # On Linux / Mac
PrimeCompositeDriver.exe      # On Windows 
```
**For Visual Studio 2022:**
1. Create a new C++ Console Application project
2. Replace the default code with **PrimeCompositeDriver.cpp**
3. Press **F5** to build and run with debugging, or **Ctrl+F5** to run without debugging 
___

## 💡Key Features
- Prompt the user to enter a number equal to or greater than 2
- Validate the user entered value 
- Process the user entered value to determine if it is prime or composite
- If value is composite, identify the prime factor and divide until a prime value returns
- Display results to the user 

___

## 📸 Sample Output
```
Please enter a non-negative number equal to 2 or greater: 3055
3055 is a COMPOSITE number.
5 has been found as a prime factor.
13 has been found as a prime factor.
47 has been found as a prime factor.
Press any key to continue


```


___

## 🧠 Challenges and Solutions
- Core mathematical concepts become increasingly difficult when programming, understanding we are no longer solving a problem at face value; but rather, supplying a solution by understanding how mathmatical concepts operate. 
- Understanding the basic rules of **Prime** and **Composite** number was essential to flag a number with a boolean to define a numbers representation
- The square root optimization seemed counterintuitive at first. After testing with examples (like 36 having factors 6 x 6), I understood that any factor larger than the square root must have a corresponding smaller factor.

___

## 💭 Concepts Demonstrated 
- **Loop Optimization:** using mathematical functions like `sqrt()` to reduce unnecessary iterations
- **Early Exit Strategy:** Implementing `break` to stop a process when it is no longer needed
- **State Tracking:** Using boolean flags to manage decisions made by the program 
- **Number Theory Application:** Applying math concepts to code