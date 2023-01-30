// JEAHProg4.cpp : Find the two largest values among 10 numbers
// 
// Initialize variables counter, number, largest, larger. Define counter as unsigned and initialize as value 1
// 
// In order for the program to recognize negative numbers, rather than letting the program assume that the two initial values for large and largest are zero,
// The first two iterations are done outside of the while loop, and intend to assign values to larger and largest without assuming the two will be positive
// 
// Print the current iteration to user
// Prompt user to input any number
// Assign number to largest
// Add one to counter
// 
// Print the current iteration to the user 
// Prompt user to input any number
// 
// If number is greater than the number largest
//		Assign the previous largest number's value to the variable larger
//		Assign the new largest number's value to the variable largest
// 
// Else 
//		Assign the number to the value larger
// 
// While the counter is less than or equal to ten
//		Print the current iteration to the user
//		Prompt user to input any number
// 
//		If the number is greater than the largest number
//			Assign the previous largest number's value to the variable larger
//			Assign the new largest number's value to the variable largest
//					
//		Else if the number is only larger than the number assigned to variable larger
//			Assign the new second largest number to the variable larger
// 
//		Add one to counter
// 
// If the largest number and the second largest number are both equal
//		Inform the user that this is the case and then return the number for both
// 
// Else
//		Return the value of the largest number to the user, then return the value of the second largest number to the user
// 
// End Program
//

#include <iostream>

int main()
{

	int unsigned counter{ 1 }; //Initializes all variables as integers. Since counter will only ever be positive, and only change by a value of positive one ever, it will be an unsigned integer.
	int number{};
	int largest{};
	int larger{};

	//Although the textbook provides an example of using this program for a sales contest of highest units sold, I am assuming that this is merely an example and that I
	// may possibly deal with negative integers. Following this assumption, the first two iterations will define the variables largest and larger in a way that will permit 
	// negative numbers, without having to compare them to the largest and larger variables initialized by default to 0, 
	// and the way I decided to do this is to put them both outside of the while loop. The first iteration will only assign the number input to the largest variable,
	// without a selection statement, and then increment the counter. The second iteration will only use a selection statement to compare the number to the value of largest,
	// assigning that number to the largest variable if it is greater, while moving the previous largest variable to be assigned to variable larger. Otherwise, the number will
	// be assigned to variable larger using the else keyword. After that, all following iterations will be performed within the while loop.

	std::cout << "The current iteration is: " << counter << " of 10." << std::endl; //Show the user the current iteration, as well as the max iterations of ten, for clarity.
	std::cout << "Please input any number : "; //Prompts user to input any number.
	std::cin >> number;
	std::cout << std::endl;
	largest = number; // Assigns the input value to variable largest.
	++counter; //Increments the counter by one.

	std::cout << "The current iteration is: " << counter << " of 10." << std::endl; //Show the user the current iteration, as well as the max iterations of ten, for clarity.
	std::cout << "Please input any number : "; //Prompts user to input any number.
	std::cin >> number;
	std::cout << std::endl;
	
	if (number > largest) { //If the input value is larger than the value contained in variable largest, 
		larger = largest;   //then assign the value of variable largest to variable larger,
		largest = number;	//followed by assigning the input value to variable largest.

	}

	else {
		larger = number; //If the above selection statement isn't true, than assign the input value to variable larger.
	}

	++counter; //Increments the counter by one.

	while (counter <= 10) { //The while loop will create iterations so long as the value of counter is less than or equal to ten.
		std::cout << "The current iteration is: " << counter << " of 10." << std::endl; //Show the user the current iteration, as well as the max iterations of ten, for clarity.
		std::cout << "Please input any number : "; //Prompts user to input any number.
		std::cin >> number;
		std::cout << std::endl;

		if (number > largest) { //If the input value is larger than the value contained in variable largest, 
			larger = largest;   //then assign the value of variable largest to variable larger,
			largest = number;	//followed by assigning the input value to variable largest.

		}

		else if (number > larger) { //Else, if the input value is only larger than the value contained in variable larger,
			larger = number;		//Assign the input value to variable larger.
		}	

		++counter; //Increments the counter by one.
	}

	if (largest == larger) { //If the largest value and the second largest value are equal, then prompt the user of the case and then return the value of both numbers.													
		std::cout << "The two largest numbers are equal to eachother, at a value of: " << largest;

	}

	else { //Else, then return to the user of the value of the largest number, then in a new line return to them the value of the second largest.
		std::cout << "The largest number in the set of ten is: " << largest << std::endl ;
		std::cout << "While the second largest number will be: " << larger;
	}

	return 0; //End program.
}




