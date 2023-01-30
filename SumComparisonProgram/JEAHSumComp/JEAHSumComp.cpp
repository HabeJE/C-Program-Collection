// Jude Habert
// 9-14-22
//#The Program's function is to create 2 sums, each sum created by two numbers inputted by the user. The program will then place those//
//sums in ascending order such that the bigger sum is above the smaller sum.//

#include <iostream> //input output functions

int main() {

	int number1{ 0 };
	int number2{ 0 };  //Initialize Numbers 1 and 2; will be required to create the first sum.
	int number3{ 0 };
	int number4{ 0 };  //Initialize Numbers 3 and 4; will be required to create the second sum.
	int sum{ 0 };	//Initialize first sum.
	int sum2{ 0 };  //Initialize second sum.

	std::cout << "Input two integers\n";
	std::cin >> number1 >> number2;		// Request User to define values for numbers 1 and 2.

	std::cout << "Now, input two other integers\n";
	std::cin >> number3 >> number4;		// Request user to define values for numbers 3 and 4.

	sum = number1 + number2;	//Calculations to determine the first sum from numbers 1 and 2.
	sum2 = number3 + number4;		//Calculations to determine the second sum from numbers 3 and 4.

	if (sum > sum2) {

		std::cout << " The sum of the larger sum generated by the first pair of numbers, " << number1 << " and " << number2 << " is " << sum << std::endl;
		std::cout << " The sum of the smaller sum generated by the second pair of numbers, " << number3 << " and " << number4 << " is " << sum2 << std::endl;
	}	// If the first sum is larger than the second sum, then the results of the first sum will be displayed first, then the second.
	else {
		std::cout << " The sum of the larger sum generated by the second pair of numbers, " << number3 << " and " << number4 << " is " << sum2 << std::endl;
		std::cout << " The sum of the smaller sum generated by the first pair of numbers, " << number1 << " and " << number2 << " is " << sum << std::endl;
	}	// Otherwise, the second sum will be displayed first, then the first.
	return 0; // After this, the role of the program is completed.

}