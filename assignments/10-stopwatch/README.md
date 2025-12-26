# Assignment 10: Stopwatch
---
## 📋 Overview
This Object Oriented Program creates a stopwatch object capable of measuring elapsed time using the system clock. The program demonstrates time tracking, state management, and conversion between different time units. The driver code was provided by the instructor as starter code.


## 🎯 Learning Objectives
- Working with the `<time.h>` library for time measurement
- Using `clock_t` data type to store time values
- Understanding `clock()` function to capture current time
- Converting **clock ticks** to **seconds** and **milliseconds**
- Using `CLOCKS_PER_SEC` constant for time conversion
- Managing **object state** with boolean flags (`isTicking`)
- Implementing **start/stop functionality** with state validation
- Accumulating time across multiple operations (`gainedTime`)
- Formatting decimal output with `setprecision()`
___

## 📚 Technical Concepts
- **`clock_t` Data Type:** Special data type for storing time measurements from the system clock, measured in "ticks"
- **`clock()` Function:** Returns the current processor time as the number of clock ticks since program start
- **Time Conversion Formula:**
  - **To seconds:** `ticks / CLOCKS_PER_SEC`
  - **To milliseconds:** `ticks / (CLOCKS_PER_SEC / 1000)`
  - Example: If `CLOCKS_PER_SEC = 1000` and `ticks = 2500`, then `2500 / 1000 = 2.5 seconds`
- **State Management:** The `isTicking` boolean prevents errors:
  - `Start()` returns `false` if already running (can't start twice)
  - `Stop()` returns `false` if already stopped (can't stop twice)
- **Accumulated Time:** `gainedTime` stores total elapsed time across start/stop cycles, allowing the stopwatch to be paused and resumed
- **Time Calculation:** `currentTime - startTime` gives elapsed ticks for the current timing session
- **Precision Control:** `setprecision(3)` with `fixed` manipulator ensures consistent 3-decimal-place display (e.g., "2.320 seconds")
- **Boolean Return Pattern:** Start/Stop methods return success/failure, allowing the caller to detect invalid operations
___

## 🚀 How to Compile and Run
**For Bash:**
```bash
# Navigate to the directory containing the project files 
cd /path/to/your/files

# Compile the program
g++ StopwatchDriver.cpp StopwatchImplementation.cpp -o Stopwatch

# Run the executable
./Stopwatch       # On Linux / Mac
Stopwatch.exe      # On Windows 
```
**For Visual Studio 2022:**
1. Create a new C++ Console Application project
2. Add all three files to the project:
   - Right-click on **Source Files** ➡️ Add ➡️ Existing Item ➡️ Select **StopwatchDriver.cpp**
   - Right-click on **Source Files** ➡️ Add ➡️ Existing Item ➡️ Select **StopwatchImplementation.cpp**
   - Right-click on **Header Files** ➡️ Add ➡️ Existing Item ➡️ Select **StopwatchSpecification.h**
3. Press **F5** to build and run with debugging, or **Ctrl + F5** to run without debugging
___

## 💡Key Features
- Start and stop timing functionality
- Accumulates time across multiple start/stop cycles
- Prevents invalid operations (starting when running, stopping when stopped)
- Converts clock ticks to human-readable seconds
- Displays time with millisecond precision (3 decimal places)
- State tracking prevents timing errors
- Boolean returns communicate operation success
- Automatic time calculation and display
___

## 📸 Sample Output

Program prompts user to begin the stopwatch 
```
Press any key to start the stopwatch...

```
Stopwatch begins running; visualized to user with the animated dotted line. User is prompted on how to stop the timer 
```
Press any key to start the stopwatch...
The stopwatch has been started, press any key to stop it...
..........................................................................

```
Program reports total elapsed time to user before terminating 
```
Press any key to start the stopwatch...
The stopwatch has been started, press any key to stop it...
..........................................................................
2.320 seconds have passed
Press any key to continue

```

___

## 🧠 Challenges and Solutions
- Understanding that `clock()` returns "ticks" rather than seconds was initially confusing. Learning about `CLOCKS_PER_SEC` as the conversion factor clarified how to translate ticks into human-readable time.
- The accumulated time pattern (`gainedTime += watchStopped`) required careful thought - understanding that you add each timing session to the total helped me see how pause/resume functionality works.
___

## 💭 Concepts Demonstrated 
- **Time Measurement:** Capturing and calculating elapsed time using system clock
- **Unit Conversion:** Translating between clock ticks, seconds, and milliseconds
- **State Validation:** Using boolean flags to prevent invalid operations
- **Accumulated Values:** Tracking totals across multiple operations
- **Formatted Output:** Controlling decimal precision for user-friendly display