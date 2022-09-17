#include "Date.h"
#include <iostream>
using namespace std;

Date::Date()//Sets default value.
{
	Day = 16;
	Month = 9;
	Year = 2022;
}
Date::Date(int d, int m, int y) :Date(d, m)

{
	if (y >= 99999 || y <= 0)						//Checks if the year is correct, otherwise puts 1900
		Year = 1900;
	else
		Year = y;

	if (d > DaysInMonth() || d < 0)				//Checks if the day is correct, otherwise puts 1
		Day = 1;

	if (m > 12 || m < 0)						//Checks if the month is correct, otherwise puts 1
		Month = 1;

}
Date::Date(int d, int m) :Date(d)
{
	Month = m;
	Year = 2022;
}
Date::Date(int d)
{

	Day = d;
	Month = 9;
	Year = 2022;
}
void Date::Print()const //Prints respective date in a console.
{
	cout << Day << '.' << Month << "." << Year << endl;
}
bool Date::IsLeap() const //Returns true if a year is leap, otherwise returns false.
{
	if (Year % 4 == 0) return true; //If year % 4, then it's Leap.
	return false;
}
short Date::DaysInMonth() const
{
	if (Month == 1 || Month == 3 || Month == 5 || Month == 7 || Month == 8 || Month == 10 || Month == 12) { //Checking months with 31 days
		return 31;
	}
	if (Month == 4 || Month == 6 || Month == 9 || Month == 11) { //Checking months with 30 days
		return 30;
	}
	if (Month == 2) {
		if (IsLeap()) return 29; // If Leap, returns 29, otherwise returns 28
		else return 28;
	}
	return -1;
}


//Getters.
int Date::GetDay() const
{
	return Day;
}
int Date::GetMonth() const
{
	return Month;
}
int Date::GetYear() const
{
	return Year;
}
//Setters
void Date::SetDay(int day)
{
	Day = day;
}
void Date::SetMonth(int month)
{
	Month = month;
}
void Date::SetYear(int year)
{
	Year = year;
}

