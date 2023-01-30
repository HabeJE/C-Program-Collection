
class JEAHDate {

#include <iostream> //need iostream for the displayDate member function

public:

	void setDate(int dayNumber = 1, int monthNumber = 1, int yearNumber = 1) { //constructor with three parameters used for assigning values to three data members month, day, and year
		monthNumber = month; //data member month will be assigned a value through monthNumber
		dayNumber = day; //data member day will be assigned a value through dayNumber
		yearNumber = year; //data member year will be assigned a value through yearNumber
	}

	void setMonth(int monthNumber) { //function that sets month, under the conditionals
		if (monthNumber < 1 ) { // if the monthNumber value is less than one, then month will be assigned a value of one
			month = 1;
		}
		else if (monthNumber > 12) { //similarly, if the monthNumber value is more than twelve, then month will be assigned a value of one as well
			month = 1;
		}
		else { //if the monthNumber is viable, assigned a value from one to twelve, then it will be assigned to data member month
			month = monthNumber;
		}
	}

	void setDay(int dayNumber) { //function that sets day
		day = dayNumber;
	}

	void setYear(int yearNumber) { //function that sets year
		year = yearNumber;
	}

	int getMonth() const { //getMonth function returns the month value 
		return month;
	}

	int getDay() const { //getDay function returns the day value
		return day;
	}

	int getYear() const { //getYear function returns the year value
		return year;
	}

	void displayDate() const{ //displayDate function displays the date in a m/d/y format 
		std::cout << month << "/" << day << "/" << year; 
	}                                                

private:
	int month; //data member holding the assigned month
	int day; //data member holding the assigned day
	int year; //data member holding the assigned year
};