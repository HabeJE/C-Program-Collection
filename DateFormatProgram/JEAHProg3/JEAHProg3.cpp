// JEAHProg3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream> //needed for input output functions
#include "JEAHDate.h" //including header JEAHDate, which will store values for month, day, and year to be returned to user 

int main() // main function guides the JEAHDate header by providing the values that will be stored until the end of the program 
{
	JEAHDate Date{}; //object to be used by the setMonth, setDay, setYear, and displayDate member fucntions
	 
	int theMonth;
	int theDay;
	int theYear; //initializing variables to take inputs

	std::cout << "Please enter any desired month by its assigned number from 1 to 12: "; //prompt user to input month, whether the month is viable for use will be decided by the header file
	std::cin >> theMonth; //store the user input into variable theMonth
	if (theMonth < 1) {
		std::cout << "Given month is less than one and therefore too low. Setting value to one.\n"; //provide information to the user that the value inputted is too low, then inform them that the header file will correct this value to one
	}
	else if (theMonth > 12) {
		std::cout << "Given month is greater than twelve and therefore too high. Setting value to one.\n"; //provide information to the user that the value inputted is too high, then inform them that the header file will correct this value to one
	}
	Date.setMonth(theMonth); //places the value of that variable into the month data member through member function setMonth
	std::cout << "The given month is: " << Date.getMonth() << std::endl; //confirm the value of the month to the user

	std::cout << "Now, please enter any desired day: "; //prompt user to input the day
	std::cin >> theDay; //store the user input into variable theDay
	Date.setDay(theDay); //places the value of that variable into the day data member through member function setDay
	std::cout << "The given day is: " << Date.getDay() << std::endl; //confirm the value of the day to the user

	std::cout << "Finally, please enter any desired year: "; //prompt the user to input the year
	std::cin >> theYear; //store the user input into variable theYear 
	Date.setYear(theYear); //places the value of that variable into the year through member function setYear
	std::cout << "Your given year is: " << Date.getYear() << std::endl; //confirm the value of the year to the user

	std::cout << "The date is: ";
	Date.displayDate(); //return the date in M/D/Y format to the user. Had trouble trying to display this using pointers, so I decided to call the member function on the line beneath the output

	return 0;
} 