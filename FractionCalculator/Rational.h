#pragma once

#include <iostream>
#include <string>

class Rational
{
public:

	explicit Rational(int num, int den) { //  constructor for Rational class takes numerator and denominator integer paramaters.
		setNumerator(num); //the object's numerator data member is set using the setNumerator public function.
		setDenominator(den); //then, the object's denominator data member is set using the setDenominator public function.
	}

	int getNumerator() { //returns numerator value when called.
		return numerator;
	};

	void setNumerator(int num) { //sets numerator value based on parameter when called.
		numerator = num;
	};

	int getDenominator() { //returns denominator value when called.
		return denominator;
	};

	void setDenominator(int den) { //sets denominator value based on parameter when called.
		if (den == 0) { //if the parameter value is zero, the denominator is set to one. This is to avoid division by 0 errors.
			std::cout << "Denominator cannot be 0, setting denominator to 1.\n" ;
			denominator = 1;
		}
		else {
			denominator = den;
		}
		reduce();	//the setDenominator function is designed to be called after the set numerator function in both main and the constructor
					//therefore, reduce function is called at the end of it, which finds the GCD for the numerator and denominator
	};				//using it to reduce the fraction to simplest form.

	std::string toString() { //toString casts the denominator and numerator from ints to strings, and then returns the value in 'numerator/denominator' form to be output in main. 
		std::string stringNumerator = "";
		std::string stringDenominator = "";
		std::string out = "";

		if (numerator == 0) { //if the numerator of the fraction is zero, then the whole value of the fraction is zero. The string output can then be safely returned as '0'.
			out = '0';
		}
		else if (denominator == 1) { //According to the identity property of division, a number divided by one will equal that number. As such, a numerator divided by a denominator of one is just a whole number equal to the value of the numerator. 
			stringNumerator = std::to_string(numerator);
			out = stringNumerator; //Therefore, only the numerator represented as a whole number is returned as a string.
		}
		else if (numerator == denominator) { //a number divided by itself will always equal one. If such a scenario occurs in the fraction, the value of one will be returned as a string.
			out = '1';
		}
		else if (numerator / denominator == -1) { //should a similar circumstance occur, but either the numerator or denominator is negative, then the value returned will insead be negative one.
			out = '-1';
		}
		else {
			stringNumerator = std::to_string(numerator);		//int numerator is converted to string and the returned value is stored in type string variable 'stringNumerator'.
			stringDenominator = std::to_string(denominator);    //same with denominator and 'stringDenominator'.
			out = stringNumerator + "/" + stringDenominator;	//the 'numerator/denominator' string is then built through concatenation and then stored in variable 'out'.
		}
		return out; // out is then returned to be output in main
	}

	friend std::ostream& operator << (std::ostream& output, Rational Fraction); //friend function for overloading the insertion operator to recognize Rational objects, since the
	//function itself can't be within the class proper.													

	Rational add(const Rational&(Fraction)) {		//this function properly add two fraction objects together, and returns the result to be stored in a fraction object. Parameter is the second fraction object.
		calculateLCD(denominator, Fraction.denominator);	//calculate lcd is necessary to find the least common denominator between the two fractions, should they have different denominators.
		Rational newFraction(0, 1); //a new fraction object is constructed to hold results until it is time to return them.
		int convertedNumerator1 = numerator * lcd1; //numerator for Fraction1 and the factor needed to attain the LCD from Fraction1 denominator are multiplied, with the converted result held for calculation.
		int convertedNumerator2 = Fraction.numerator * lcd2; //the same is done for the numerator of the second fraction.
		newFraction.denominator = Fraction.denominator * lcd2; //Least common denominator is attained by multiplying the second denominator with the necessary factor. The result is then held as the denominator of the newFraction object. This can be similarly done with the first denominator, but it doesn't matter which one is chosen since they will both produce an identical final result.
		newFraction.numerator = convertedNumerator1 + convertedNumerator2; //the numerator for fraction3 is the sum of converted numerators for fraction1 and fraction2.
		newFraction.reduce(); //the numerator and denominator of fraction3 are then reduced to simplest form
		return newFraction; // the newFraction object is then returned to be stored into the fraction3 object.
	}

	Rational subtract(const Rational&(Fraction)) { //subtraction function is pretty much identical to the addition function, except the converted numerator of fraction1 is subtracted by the converted numerator of fraction2.
		calculateLCD(denominator, Fraction.denominator);
		Rational newFraction(0, 1);
		int convertedNumerator1 = numerator * lcd1;
		int convertedNumerator2 = Fraction.numerator * lcd2;
		newFraction.denominator = Fraction.denominator * lcd2;
		newFraction.numerator = convertedNumerator1 - convertedNumerator2;
		newFraction.reduce();
		return newFraction;
	}

	Rational multiply(const Rational&(Fraction)) { //multiply function obtains the product from objects fraction1 and fraction2 to be returned to the main function and stored within another Fraction object.
		Rational newFraction(0, 1);
		newFraction.numerator = numerator * Fraction.numerator; //newfraction numerator is the product of fraction1 numerator and fraction2 numerator.
		newFraction.denominator = denominator * Fraction.denominator; //newfraction denominator is the product of fraction1 numerator and fraction2 numerator.
		newFraction.reduce();
		return newFraction;
	}

	Rational divide(const Rational&(Fraction)) { //division function is nearly identical to the multiplication function, but fraction1 is multiplied by the inverse of fraction2;
		Rational newFraction(0, 1);

		if (Fraction.numerator == 0) { //Should the numerator of the divisor Fraction be zero, that would result in division by zero. To prevent any issues, an exception is thrown to inform the user of such an issue.
			throw 11;
		}

		else {
			newFraction.numerator = numerator * Fraction.denominator; //The numerator of fraction1 is multiplied by the denominator of fraction2. This is stored in newfraction numerator.
			newFraction.denominator = denominator * Fraction.numerator; //The denominator of fraction1 is then mulitiplied by the numerator of fraction2. This is stored in newfraction denominator.
			newFraction.reduce();
			return newFraction;
		}
		
	}

	Rational operator + (const Rational Fraction) { //operation overload of the plus symbol to recognize Rational objects, using the add function within the Rational class to perform the addition.
		Rational newFraction(0, 1);
		newFraction = add(Fraction);
		return newFraction;
	}

	Rational operator - (const Rational Fraction) { //operation overload of the minus symbol to recognize Rational objects, using the subtract function within the Rational class to perform the subtraction.
		Rational newFraction(0, 1);
		newFraction = subtract(Fraction);
		return newFraction;
	}

	Rational operator * (const Rational Fraction) { //operation overload of the asterisk symbol to recognize Rational objects, using the multiply function within the Rational class to perform the multiplication.
		Rational newFraction(0, 1);
		newFraction = multiply(Fraction);
		return newFraction;
	}

	Rational operator / (const Rational Fraction) { //operation overload of the forward slash symbol to recognize Rational objects, using the divide function within the Rational class to perform the division.
		Rational newFraction(0, 1);
		newFraction = divide(Fraction);
		return newFraction;
	}

	Rational Fraction1Inputs() { //Fraction1Inputs is to take integer inputs from the user, and inform that user that those inputs are being stored as the numerator and denominator of Fraction1 object.

		int input(NULL);
		Rational inputFraction(0, 1);

		while (std::cout << "Enter the numerator for the first fraction: " && !(std::cin >> input)) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input; please re-enter.\n";
		}
		inputFraction.setNumerator(input);
		std::cout << "\n";

		while (std::cout << "Enter the denominator for the first fraction: " && !(std::cin >> input)) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input; please re-enter.\n";
		}
		inputFraction.setDenominator(input);
		std::cout << "\n";

		std::cout << "The simplest form of this fraction is: " << inputFraction << std::endl;
		std::cout << "\n";

		return inputFraction;
	}

	Rational Fraction2Inputs () { //This function is effectively the same as the one above, but will inform the user that the inputs are instead being stored in the Fraction2 object.
		
		int input(NULL);
		Rational inputFraction(0, 1);

		while (std::cout << "Enter the numerator for the second fraction: " && !(std::cin >> input)) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input; please re-enter.\n";
		}
		inputFraction.setNumerator(input);
		std::cout << "\n";

		while (std::cout << "Enter the denominator for the second fraction: " && !(std::cin >> input)) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input; please re-enter.\n";
		}
		inputFraction.setDenominator(input);
		std::cout << "\n";

		std::cout << "The simplest form of this fraction is: " << inputFraction << std::endl;
		std::cout << "\n";

		return inputFraction;
	}

private:

	void calculateLCD(int den1, int den2) { //since attaining the least common denominator for two different fractions requires a different factor for each denominator, these two numbers must be found with two different functions. Since this and the below functions are only called within the class, they are all private.
		constantDen1 = den1;
		constantDen2 = den2;	//these two are for use in recursive calls in the subLCD functions; the original denominator values that won't change every time the original parameters are modified within that function.
		subLCD1(den1, den2);	//LCD1 finds the necessary factor to change the denominator for fraction 1 into the least common denominator.
		subLCD2(den2, den1);	//LCD2 finds the necessary factor to change the denominator for fraction 2 into the least common denominator.
	}

	void subLCD1(int subDen1, int subDen2) { //finds the factor for the fraction 1 least common denominator using recursion.
		if (subDen1 = subDen2) {	//once denominator 1 is equal to denominator 2, then lcd is found.
			lcd1 = subDen1;			//assigns the final value of the modified denominator1 into lcd1, to be used when multiplying the numerator into a viable form for the addition and subtraction functions.
		}
		else if (subDen1 > subDen2) {
			subLCD1(subDen1, subDen2 + constantDen2);	//if denominator 1 is greater than denominator 2, then make a recursive call where the parameter for denominator 2 has another group of the original denominator 2 added onto it
		}
		else {
			subLCD1(subDen1 + constantDen1, subDen2); //otherwise, as in the case where denominator 2 is greater than denominator 1, then make a recursive call where the parameter for denominator 1 has another group of the original denominator 1 added onto it.
		}
	}

	void subLCD2(int subDen2, int subDen1) { //this function is very similar to the one above, but once the recursive loop breaks, the value is assigned to lcd2 so as to be multiplied with the numerator for fraction 2. The parameters for denominator 1 and 2 are also switched when the function is called by the calculateLCD function.
		if (subDen2 = subDen1) {
			lcd2 = subDen2;
		}
		else if (subDen2 > subDen1) {
			subLCD2(subDen2, subDen1 + constantDen2); //since denominators 1 and 2 are switched by the calculate LCD function, the constantDen2 is actually added onto denominator 1 when denominator 2 is greater than denominator 1.
		}
		else {
			subLCD2(subDen2 + constantDen1, subDen1); //similarly for this recursive call, where constantDen1 is added onto denominator 2 should denominator 1 be greater than denominator 2. Both of these deviations are to help get a factor to properly set numerator and denominator 2 into a form suitable to fraction addition and subtraction.
		}
	}

	void calculateGCD(int number1, int number2) { //calculate GCD is used within the reduce function to find the greatest common divisor between the numerator and denominator of a fraction object. This is achieved with recursion calls.
		if (number2 == 0) {		//	Once the result of the second parameter is a remainder of 0, the gcd is found.
			gcd = number1;		//	Assign the first parameter to gcd.
		}
		else {
			calculateGCD(number2, number1 % number2); //If the gcd is not found yet, recursive call with first parameter being the second parameter in the previous call, and have the result of the remainder of the previous call's first parameter divided by the previous call's second parameter be the second parameter.
		}		
	}

	void reduce() { //reduces fraction object to simplest form.
		calculateGCD(numerator, denominator); //finds gcd of the fraction.
		numerator = numerator / gcd; //the numerator is reduced.
		denominator = denominator / gcd; //the denominator is reduced
		if (denominator < 0) {	//on some occasions with arithmetic and user inputs, the denominator may end up negative. Although mathematically feasible, this results in a very clumsy format. 
			numerator = numerator * -1;
			denominator = denominator * -1; //To correct this matter, both numerator and denominator multiplied by negative one, resulting in an equivalent fraction in a more pleasant form.
		}
	}

	int numerator; //this int represents the numerator in the fraction object

	int denominator; //this int represents the denominator in the fraction object

	int gcd; //this int holds the gcd used to reduce a fraction to simplest form

	int lcd1; //this int is used to properly apply the least common denominator in a summation or subtraction problem onto the first fraction 

	int lcd2; //this int does the same to the second fraction in the problem

	int constantDen1; //this int is used for calculating the LCD using recursion 

	int constantDen2;; //this int is used for calculating the LCD using recursion
};

std::ostream& operator << (std::ostream& output, Rational Fraction) { //For overloading insertion operator to properly identify Rational Objects and output the toString function without needing to make a direct call for toString or the Rational type, only the object name proper. 
	output << Fraction.toString();
	return output;
}