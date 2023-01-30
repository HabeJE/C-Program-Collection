// Starcount.cpp : Jude Habert, 10/28/22 Display four right triangles at different positions, with a width and height of 10 asterisks
//
// For a counter of one, breaking if counter is greater than or equal to ten, incrementing by one
//		Assign counter to variable starcount
//		Assign ten subtracted by the counter to variable spacecount
//		For variable starcount, breaking if starcount is less than or equal to zero, decrementing by one
//			output an asterisk
//		For variable spacecount, breaking if spacecount is less than or equal to zero, decrementing by one
//			output a space
//		Output the newline escape sequence
// Output a newline escape sequence
// 
// For a counter of ten, breaking if counter is less than or equal to zero, decrementing by one
//		Assign counter to variable starcount
//		Assign ten subtracted by the counter to variable spacecount 
//		For variable starcount, breaking if starcount is less than or equal to zero, decrementing by one
//			output an asterisk
//		For variable spacecount, breaking if spacecount is less than or equal to zero, decrementing by one
//			output a space
//		Output the newline escape sequence 
// Output a newline escape sequence
// 
// For a counter of zero, breaking if counter is greater than or equal to ten, incrementing by one
//		Assign counter to variable spacecount
//		Assign ten subtracted by the counter to variable starcount
//		For variable spacecount, breaking if spacecount is less than or equal to zero, decrementing by one
//			output a space
//		For variable starcount, breaking if starcount is less than or equal to zero, decrementing by one
//			output an asterisk
//		Output the newline escape sequence
// Output a newline escape sequence
// 
// For a counter of nine, breaking if counter is less than or equal to zero, decrementing by one
//		Assign counter to variable spacecount
//		Assign ten subtracted by counter to variable starcount
//		For variable spacecount, breaking if spacecount is less than or equal to zero, decrementing by one
//			output a space
//		For variable starcount, breaking if starcount is less than or equal to zero, decrementing by one
//			output an asterisk
//		Output the newline escape sequence
//

#include <iostream> // used solely for the outputs of a single star, space, or newline escape sequence.

int main() {

	for (int counter{ 1 }; counter <= 10; counter++) { // This loop will begin at a counter of one, incrementing by a value of one for each loop until the counter is greater than ten.
		int starcount = counter; // initilializes integer starcount by assigning it with the current value of counter for each loop.
		for (starcount; starcount > 0; starcount--) { // This loop will begin at the current value of starcount, decrementing by a value of one for each loop until the starcount is less than or equal to zero.
			std::cout << "*"; //for each iteration, the asterisk character will be output on the current line.
		}
		std::cout << "\n"; //After all the asterisks have been output on the line, the program will then move to a new line and the main counter loop will reiterate. 
		//I also originally had a counter to keep track of spaces and a for loop to print out spaces for this loop and the second one, but I realized that both are unneccessary as the triangles could be made without them.
		//After the main counter iteration statement breaks, the result will print out a right triangle with the right angle positioned on the bottom left corner of the screen.
	}
	std::cout << "\n"; //To further separate each triangle from the other on the screen, the program will move down a line for clarity.

	for (int counter{ 10 }; counter > 0; counter--) { // This loop will begin at a counter of ten, decrementing by a value of one for each loop until the counter is less than or equal to zero.
		int starcount = counter; // initilializes integer starcount by assigning it with the current value of counter for each loop.
		for (starcount; starcount > 0; starcount--) { // This loop will begin at the current value of starcount, decrementing by a value of one for each loop until the starcount is less than or equal to zero.
			std::cout << "*"; //for each iteration, the asterisk character will be output on the current line.
		}
		std::cout << "\n"; //After all the asterisks have been output on the line, the program will then move to a new line and the main counter loop will reiterate. 
		//After the main counter iteration statement breaks, the result will print out a right triangle with the right angle positioned on the top left corner of the screen.
	}
	std::cout << "\n";

	for (int counter{ 0 }; counter < 10; counter++) { //This loop will begin at a counter of zero, incrementing by a value of one for each loop until the counter is greater than or equal to ten.
		int spacecount = counter; //Unlike the two loops above, this one will instead assign the current value of counter to the integer spacecount instead. 
		//This is also why counter is initialized to 0 instead, since the first loop requires the printing of ten asterisks without a space.
		int starcount = 10 - counter; //As such, the integer starcount will be instead assigned as ten minus the current value of counter.
		for (spacecount; spacecount > 0; spacecount--) { //This loop will begin at the current value of spacecount, decrementing by a value of one for each loop until the spacecount is less than or equal to zero.
			std::cout << " "; //for each iteration, a space will be output on the current line following all the asterisks on that line.
		}
		for (starcount; starcount > 0; starcount--) { // This loop will begin at the current value of starcount, decrementing by a value of one for each loop until the starcount is less than or equal to zero.
			std::cout << "*"; //for each iteration, the asterisk character will be output on the current line.
		}
		std::cout << "\n"; //After all the asterisks and spaces have been output on the line, the program will then move to a new line and the main counter loop will reiterate. 
		//After the main counter iteration statement breaks, the result will print out a right triangle with the right angle positioned on the top right corner of the screen.
	}
	std::cout << "\n";

	for (int counter{ 9 }; counter >= 0; counter--) { //This loop will begin at a counter of nine, decrementing by a value of one for each loop until the counter is less than zero.
		int spacecount = counter; // Initializes integer spacecount by assigning it with the current value of counter for each loop.
		int starcount = 10 - counter; // Initializes integer starcount by assigning it as ten minus the current value of counter for each loop.
		for (spacecount; spacecount > 0; spacecount--) { //This loop will begin at the current value of spacecount, decrementing by a value of one for each loop until the spacecount is less than or equal to zero.
			std::cout << " "; //for each iteration, a space will be output on the current line following all the asterisks on that line.
		}
		for (starcount; starcount > 0; starcount--) { // This loop will begin at the current value of starcount, decrementing by a value of one for each loop until the starcount is less than or equal to zero.
			std::cout << "*"; //for each iteration, the asterisk character will be output on the current line.
		}
		std::cout << "\n"; //After all the asterisks and spaces have been output on the line, the program will then move to a new line and the main counter loop will reiterate. 
		//After the main counter iteration statement breaks, the result will print out a right triangle with the right angle positioned on the bottom right corner of the screen.
	}
	std::cout << "\n";

	return 0;
}
