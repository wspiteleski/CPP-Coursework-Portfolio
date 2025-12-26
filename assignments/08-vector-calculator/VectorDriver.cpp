/*Author: William Stewart Piteleski
Description: the driver file uses class syntax version 4 and is responsible for instanssiating
and organizing the logic to produce the vector calculations for magnitude with operator overloading*/

#include <iostream>
#include "Specification.h"

using namespace std;

int main() {
    Vector myFirstVector(4, 5);      //creating a set of vectors with an arbitrary value 
    Vector mySecondVector;
    Vector resultVector;
    mySecondVector = myFirstVector; 

    cout << "My vector: " << myFirstVector << endl;     //display value setting operation for = 

    resultVector = myFirstVector + mySecondVector;      //display addition operation for +  
    cout << "My vector added to itself: " << resultVector << endl;

    resultVector = myFirstVector - mySecondVector;     //display subtraction operation for - 
    cout << "My vector subtracted by itself: " << resultVector << endl;


    return 0;
}