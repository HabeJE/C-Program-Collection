// FractionCalculator.cpp : A simple fraction calculator for basic arithmetic. Takes inputs of rational numbers represented by objects.
//

#include "Rational.h"
#include <iostream>
#include <string>
#include <limits>

int main() //the main implements the Rational class as a means of calculating two fractions, utilizing a menu
{
	Rational inputFraction(0, 1); //this Rational object is only used to call the Fraction#Input functions and then assign inputs to create rational numbers in Fraction1 and Fraction2.
	Rational Fraction1(0, 1);
	Rational Fraction2(0, 1);
	Rational Fraction3(0, 1);	//three Rational fraction objects are constructed. Two are used for arithmetic, and the other is used to contain the result.

	std::string stringResponse;	
	char charResponse(NULL);

	std::cout << "Welcome,";
	std::cout << "\n";

	while (true) {	//menu functions through a while loop


		std::cout << "Enter 'a' for addition, 's' for subtraction, 'd' for division, 'm' for multiplication, or 'q' to quit: "; //stringResponse will hold a user input as a string
		std::cin >> stringResponse;

		if (stringResponse.length() > 1) { //should the user input more than one character, they are informed that only the first character will be read
			std::cout << "The input is larger than one character; truncating all excess characters." << std::endl;
			std::cout << "\n";
		}

		charResponse = stringResponse[0]; //only the first character of stringResponse is stored in charResponse. From there selection statements will make a decision according to what the user intends to do.

		if (charResponse == 'q') { //should the user no longer need to continue, inputting q will break out of the while loop and end the program.
			break;
		}

		switch (charResponse) {
			//if the response is any other valid option, prompt the user to input values of a numerator and denominator for each fraction. Show resulting fractions from user input in simplest form to the user.
			case 'a': 	//if response is a, perform fraction addition using the overloaded summation operator and print the results to the user.

				Fraction1 = inputFraction.Fraction1Inputs(); //results from the input functions are placed within their respective objects
				Fraction2 = inputFraction.Fraction2Inputs();
				Fraction3 = Fraction1 + Fraction2;

				std::cout << Fraction3 << " = " << Fraction1 << " + " << Fraction2 << std::endl;
				std::cout << "\n";

				break;

			case 's': 	//if response is s, perform fraction subtraction using the overloaded subtraction operator and print the results to the user.

				Fraction1 = inputFraction.Fraction1Inputs();
				Fraction2 = inputFraction.Fraction2Inputs();
				Fraction3 = Fraction1 - Fraction2;

				std::cout << Fraction3 << " = " << Fraction1 << " - " << Fraction2 << std::endl;
				std::cout << "\n";

				break;

			case 'm': //if the response is m, perform fraction multiplication using the overloaded multiplication operator and print the results to the user.

				Fraction1 = inputFraction.Fraction1Inputs();
				Fraction2 = inputFraction.Fraction2Inputs();
				Fraction3 = Fraction1 * Fraction2;

				std::cout << Fraction3 << " = " << Fraction1 << " * " << Fraction2 << std::endl;
				std::cout << "\n";

				break;

			case 'd': 	//if the response is d, perform fraction division using the overloaded division operator and print the results to the user.

				try {
					Fraction1 = inputFraction.Fraction1Inputs();
					Fraction2 = inputFraction.Fraction2Inputs();
					Fraction3 = Fraction1 / Fraction2;
				}
				catch (int FractionDivideByZeroException){ //Should the numerator of the divisor fraction be zero, then the exception is thrown from the Rational divide function and caught here.
					std::cout << "Exception: Divisor Fraction is equal to zero. Division by zero is undefined." << std::endl; //The user is informed that this is the issue and the case breaks without printing the results to the user. 
					break;
				}

				std::cout << Fraction3 << " = " << Fraction1 << " / " << Fraction2 << std::endl;
				std::cout << "\n";

				break;

			default:	
				std::cout << "Invalid Response: Please return an expected character." << std::endl; //default case informs user that they had not provided a valid response.
				std::cout << "\n";
		}
	}
}

	