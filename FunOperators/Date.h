#pragma once
class Date
{
	int Day;
	int Month;
	int Year;

public:
	Date(); //Constructor by default will initialize an object with current date. 
	Date(int, int, int); //Constructor fills an object with user's data. Delegation below.
	Date(int, int);
	Date(int);

	void Print()const; //Prints date in a console.
	bool IsLeap()const; //Checks if the year is leap, returns true if it is.
	short DaysInMonth()const; //Returns days of a respective month.

	//Getters.
	int GetDay()const;
	int GetMonth()const;
	int GetYear()const;

	//Setters.
	void SetDay(int day);
	void SetMonth(int month);
	void SetYear(int year);
};