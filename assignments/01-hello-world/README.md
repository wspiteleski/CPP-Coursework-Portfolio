# Assignment 01: Hello World!
---
## 📋 Overview
A rite of passage C++ program that demonstrates basic output to the console by displaying the message "Hello World!"
___

## 🎯 Learning Objectives
- Basic C++ program structure 
- Using the `<iostream>` library 
- Using `cout` stream for console output 
- Using `main()` function as program entry point 

___

## 📚 Technical Concepts
- **Include Directives:** The `#include <iostream>` preprocessor directive brings in the input/output stream library, which provides access to `cout` and other I/O functionality 
- **Namespace:** The `using namespace std;` statement allows us to use standard library features without the `std::` prefix, streamlining the coding process
- **Output Stream:** `cout` is the standard output stream that sends data to the console
- **Stream Manipulators:** `endl;` adds a newline character and flushes the output buffer, ensuring immediate display

___

## 🚀 How to Compile and Run
**For Bash:**
```bash
# Navigate to the directory containing helloworld.cpp
cd /path/to/your/file

# Compile the program
g++ helloworld.cpp -o helloworld

# Run the executable
./helloworld        # On Linux / Mac
helloworld.exe      # On Windows 
```
**For Visual Studio 2022:**
1. Create a new C++ Console Application project
2. Replace the default code with **helloworld.cpp**
3. Press **F5** to build and run with debugging, or **Ctrl+F5** to run without debugging 
___

## 💡Key Features
- Outputs a greeting message to the console 
- Demonstrates proper program structure with include, namespace, and main function
- Shows correct program termination with return value

___

## 📸 Sample Output
```
Hello World!
```
___

## 🧠 Challenges and Solutions
- Minor Syntax changes moving from C to C++ in my learning journey 

___

## 💭 Concepts Demonstrated 
- **Imperative Programming:** Sequential execution of statements from top to bottom 
- **Standard Library Usage:** Leveraging pre-built C++ functionality through includes
- **Compilation Process:** Understanding the transformation from source code to executable 