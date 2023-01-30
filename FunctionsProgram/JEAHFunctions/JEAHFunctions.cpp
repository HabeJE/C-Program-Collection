// JEAHFunctions.cpp: Jude Habert 11/04/22 Roll 2 dice 110,000 times, while counting number of each result within the possible range to be printed out to the user on a table

#include <iostream>
#include <cstdlib> //for rand and srand 
#include <ctime> //use time as a means of creating rng 
#include <iomanip> //used to properly format percentages when printed out to the user

unsigned int rollDice(); //function for the simulation of rolling a pair of dice

int main() {

	std::cout << std::fixed << std::setprecision(2); //formats doubles to be displayed without scientific notation, rounded to nearest hundredths place. Used for rollPercent variables

	int twoCounter{ 0 };
	int threeCounter{ 0 };
	int fourCounter{ 0 };
	int fiveCounter{ 0 };
	int sixCounter{ 0 };
	int sevenCounter{ 0 };
	int eightCounter{ 0 };
	int nineCounter{ 0 };
	int tenCounter{ 0 };
	int elevenCounter{ 0 };
	int twelveCounter{ 0 }; //initialize counters for all possible rolls of a pair of dice

	srand(static_cast<unsigned int>(time(0))); //start random number generator

	for (int gameCounter{ 1 }; gameCounter <= 110000; gameCounter++) { //the loop will begin at a gameCounter of 1, incrementing by 1 for each iteration until it breaks after gameCounter exceeds 110000
		unsigned int sumOfDice {rollDice()}; //the pair of dice are rolled, and the sum of both is applied to unsigned integer sumOfDice

		switch (sumOfDice) { //decision is made based on the value of the sum of dice
		case 2: //if the sum of dice adds up to 2, increment the value of twoCounter by 1 and break from the selection statement
			twoCounter++;
			break;
		case 3:	//if the sum of dice adds up to 3, increment the value of threeCounter by 1 and break from the selection statement
			threeCounter++;
			break;
		case 4: //if the sum of dice adds up to 4, increment the value of fourCounter by 1 and break from the selection statement
			fourCounter++;
			break;
		case 5:	//if the sum of dice adds up to 5, increment the value of fiveCounter by 1 and break from the selection statement
			fiveCounter++;
			break;
		case 6:	//if the sum of dice adds up to 6, increment the value of sixCounter by 1 and break from the selection statement
			sixCounter++;
			break; 
		case 7: //if the sum of dice adds up to 7, increment the value of sevenCounter by 1 and break from the selection statement
			sevenCounter++;
			break;
		case 8: //if the sum of dice adds up to 8, increment the value of eightCounter by 1 and break from the selection statement
			eightCounter++;
			break;
		case 9: //if the sum of dice adds up to 9, increment the value of nineCounter by 1 and break from the selection statement
			nineCounter++;
			break;
		case 10: //if the sum of dice adds up to 10, increment the value of tenCounter by 1 and break from the selection statement
			tenCounter++;
			break;
		case 11: //if the sum of dice adds up to 11, increment the value of elevenCounter by 1 and break from the selection statement
			elevenCounter++;
			break;
		default: //if the sum of dice does not fulfill the above cases, which in any case would mean that the sum is equal to twelve, increment the value of twelveCounter by 1. Default case needs no break statement
			twelveCounter++;
		}
	}

	double twoPercent = (twoCounter / static_cast<double>(110000)) * 100;
	double threePercent = (threeCounter / static_cast<double>(110000)) * 100;
	double fourPercent = (fourCounter / static_cast<double>(110000)) * 100;
	double fivePercent = (fiveCounter / static_cast<double>(110000)) * 100;
	double sixPercent = (sixCounter / static_cast<double>(110000)) * 100;
	double sevenPercent = (sevenCounter / static_cast<double>(110000)) * 100;
	double eightPercent = (eightCounter / static_cast<double>(110000)) * 100;
	double ninePercent = (nineCounter / static_cast<double>(110000)) * 100;
	double tenPercent = (tenCounter / static_cast<double>(110000)) * 100;
	double elevenPercent = (elevenCounter / static_cast<double>(110000)) * 100;
	double twelvePercent = (twelveCounter / static_cast<double>(110000)) * 100; //Calculations for the percentage of total rolls that each dice roll result corresponds to 

	std::cout << "The roll 2 occurred " << twoCounter << " times which is " << twoPercent << "% of the rolls.\n";
	std::cout << "The roll 3 occurred " << threeCounter << " times which is " << threePercent << "% of the rolls.\n";
	std::cout << "The roll 4 occurred " << fourCounter << " times which is " << fourPercent << "% of the rolls.\n";
	std::cout << "The roll 5 occurred " << fiveCounter << " times which is " << fivePercent << "% of the rolls.\n";
	std::cout << "The roll 6 occurred " << sixCounter << " times which is " << sixPercent << "% of the rolls.\n";
	std::cout << "The roll 7 occurred " << sevenCounter << " times which is " << sevenPercent << "% of the rolls.\n";
	std::cout << "The roll 8 occurred " << eightCounter << " times which is " << eightPercent << "% of the rolls.\n";
	std::cout << "The roll 9 occurred " << nineCounter << " times which is " << ninePercent << "% of the rolls.\n";
	std::cout << "The roll 10 occurred " << tenCounter << " times which is " << tenPercent << "% of the rolls.\n";
	std::cout << "The roll 11 occurred " << elevenCounter << " times which is " << elevenPercent << "% of the rolls.\n";
	std::cout << "The roll 12 occurred " << twelveCounter << " times which is " << twelvePercent << "% of the rolls.\n"; 
	//Prints the number of occurances for each dice roll, followed by the percentage chance of each roll occurring based on 110,000 rolls

	return 0; //end program
}

//defines the function rollDice
unsigned int rollDice() {
	int die1{ 1 + rand() % 6 }; //simulation of the first dice roll
	int die2{ 1 + rand() % 6 }; //simulation of the second dice roll
	int sum{ die1 + die2 }; //the sum of the first and seccond dice roll
	return sum; //the sum is then returned to where a function parameter or user might need it
}

// Include libraries for iostream, cstdlib, and ctime for input output statements, as well as prototypes for generating random results
// Create function prototype rollDice
// 
// Begin Main function
// Initialize counters to keep track of each result ranging from 1 to 12, starting at 0
// Begin random number generator
// 
// for gameCounter beginning at 1, loop reiterating until gameCounter exceeds 110,000, incrementing by 1
//		Using rollDice function, roll dice twice and add the sum to variable sumOfDice
//		create switch case for sumOfDice
//			case 2 for a roll of 2
//				increment twoCounter by 1
//				break
//			case 3 for a roll of 3
//				increment threeCounter by 1
//				break
//			case 4 for a roll of 4
//				increment fourCounter by 1
//				break
//			case 5 for a roll of 5 
//				increment fiveCounter by 1
//				break
//			case 6 for a roll of 6
//				increment sixCounter by 1
//				break
//			case 7 for a roll of 7
//				increment sevenCounter by 1
//				break 	
//			case 8 for a roll of 8
//				increment eightCounter by 1
//				break
//			case 9 for a roll of 9 
//				increment nineCounter by 1
//				break
//			case 10 for a roll of 10 
//				increment tenCounter by 1
//				break
//			case 11 for a roll of 11
//				increment elevenCounter by 1
//				break
//			default case for a roll of 12
//				increment twelveCounter by 1
//
//	Divide each rollCounter by the gameCounter, multiply by one hundred, round to nearest hundredth and then assign to variable rollPercent (the word roll being replaced with the result number)
//	Output each roll, the number of occurances of that roll through rollCounter, and then the rollPercentage in a table for each result to the user
//	End main
// 
//	Define function rolldice 
//	die 1 rolls a number between 1 and 6
//	die 2 rolls a number between 1 and 6
//	sum the two rolls together
//