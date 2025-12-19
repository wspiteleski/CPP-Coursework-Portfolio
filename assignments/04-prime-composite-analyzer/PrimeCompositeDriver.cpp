/*Author: William Stewart Piteleski
Description: the following program will use decision making, iteration, 
number theory, and advanced loop techniques to identify a non-negative
integer as prime, composite, or neither while provided prime factorization for 
composite integers.*/

#include <iostream>
#include <conio.h>		//used for _getch() 
#include <cmath>        //used for sqrt() (square root) tool 

using namespace std;


//MAIN
int main() {
	int userNumber = 0;																		  //initializing an integer declaration to recieve user input value
	bool primeNumber = true;																  //initializing a bool declaration to recieve a true/false response from the program as it checks numbers throughout 

	cout << "Please enter a non-negative number equal to 2 or greater: ";					  //prompt the user to enter a value within a workable range 2 - inf
	cin >> userNumber;																		  //recieve user input and assign it to userNumber

	for (int divisor = 2; divisor <= sqrt(userNumber); divisor++) {							  //we will iterate up to the square root value of userNumber to see if we can divide the userNumber with a remainder
		if (userNumber % divisor == 0) {													  //to identify remainders we will use modulo, a result in zero means the number is a composite
			primeNumber = false;															  //if the number is a composite, the check is false (the number is not prime)
			break;																			  //if this check returns false, there is no need to continue checking and we can stop here ny using break
		}
	}

	if (userNumber < 2) {																	  //numbers less than 2 would be neither prime, composite, or negative (outside the parameter)
		cout << userNumber << " is out of our field consideration <[2, inf] : 2>" << endl;
		cout << "Press any key to continue";
																					   
	}else if (primeNumber ==  true) {														  //if the prime check registers true, this condition will trigger the prime number condition
		cout << userNumber << " is a PRIME number." << endl;
		cout << "Press any key to continue";
		
	}else {
		cout << userNumber << " is a COMPOSITE number." << endl;							  //if the condition check reaches this far the number must be composite and can execute without further checking 
		
		for (int divisor = 2; divisor <= userNumber; divisor++) {							  //iterate through potential divisor results 		
			while (userNumber % divisor == 0) {												  //identify when a remainder no longer exists using modulo (prime factor)
				cout << divisor << " has been found as a prime factor." << endl;
				userNumber = userNumber / divisor;											  //divide out the prime factor and continue the proocess to find remaining prime factos  
			}
		}		
		cout << "Press any key to continue";
		
	}	
	_getch();																				  //pause the screen for the user experience
	return 0;
}

