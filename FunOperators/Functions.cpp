
#include "Date.h"
Date operator+(int a, const Date obj) //Addtion operation via int value. Will try to add an int value to a respective date.
{
	int MonthDaysTemp; //MonthDaysTemp for correct work of DaysInMonth() with Day field.
	int MonthBuffer = 0; //For Months field never be more than 12 in the first while cycle. 
	Date temp(obj);
	temp.SetDay(temp.GetDay() + a); //Adds new days.
	while (temp.GetDay() > temp.DaysInMonth()) { //While Days > Days in Current Months, Days - Days in Current Months, Months ++.
		temp.SetDay(temp.GetDay() - temp.DaysInMonth());
		temp.SetMonth(temp.GetMonth() + 1);
		MonthDaysTemp = temp.DaysInMonth();
		temp.SetMonth(temp.GetMonth() - 1);
		MonthBuffer++;
	}
	temp.SetMonth(temp.GetMonth() + MonthBuffer); //Adds MonthBuffer to a Month field.
	while (temp.GetMonth() > 12) { //While Month > 12. Month -= 12? Year++.
		temp.SetYear(temp.GetYear() + 1);
		temp.SetMonth(temp.GetMonth() - 12);
	}
	return temp; //Returns temp object
}
Date operator+(Date obj, const Date obj2) //Addtion operation via int value. Will try to add an a date to a respective date.
{
	int MonthDaysTemp; //MonthDaysTemp for correct work of DaysInMonth() with Day field.
	int MonthBuffer = 0; //For Months field never be more than 12 in the first while cycle. 
	Date temp(obj);
	temp.SetDay(temp.GetDay() + obj2.GetDay()); //Adds new days.
	while (temp.GetDay() > temp.DaysInMonth()) { //While Days > Days in Current Months, Days - Days in Current Months, Months ++.
		temp.SetDay(temp.GetDay() - temp.DaysInMonth());
		temp.SetMonth(temp.GetMonth() + 1);
		MonthDaysTemp = temp.DaysInMonth();
		temp.SetMonth(temp.GetMonth() - 1);
		MonthBuffer++;
	}
	temp.SetMonth(temp.GetMonth() + obj2.GetMonth());
	temp.SetMonth(temp.GetMonth() + MonthBuffer); //Adds MonthBuffer to a Month field.
	while (temp.GetMonth() > 12) { //While Month > 12. Month -= 12? Year++.
		temp.SetYear(temp.GetYear() + 1);
		temp.SetMonth(temp.GetMonth() - 12);
	}
	temp.SetYear(temp.GetYear() + obj2.GetYear());
	return temp; //Returns temp object
}
Date operator-(int a, Date& obj) //Subtraction operation via int value. Will try to subtract an int value from a respective date.
{
	int MonthDaysTemp; //MonthDaysTemp for correct work of DaysInMonth() with Day field.
	Date temp(obj); //Creating temp object.

	temp.SetDay(temp.GetDay() - a);//Substract days.
	while (temp.GetDay() < 1) { //While Days < 1, Month--, Day+= MonthDaysTemp.
		MonthDaysTemp = temp.DaysInMonth();
		temp.SetMonth(temp.GetMonth() - 1);
		temp.SetDay(temp.GetDay() + temp.DaysInMonth());
		while (temp.GetMonth() < 1) { //While Months < 1 Year --, Month +=12.
			temp.SetYear(temp.GetYear() - 1);
			temp.SetMonth(temp.GetMonth() + 12);
		}
	}
	return temp; //Returns temp object
}
Date operator-(const Date& obj, const Date& obj2)
{
	int MonthDaysTemp; //MonthDaysTemp for correct work of DaysInMonth() with Day field.
	Date temp(obj); //Creating temp object.

	temp.SetDay(temp.GetDay() - obj2.GetDay());//Substract days.
	while (temp.GetDay() < 1) { //While Days < 1, Month--, Day+= MonthDaysTemp.
		MonthDaysTemp = temp.DaysInMonth();
		temp.SetMonth(temp.GetMonth() - 1);
		temp.SetDay(temp.GetDay() + temp.DaysInMonth());
		temp.SetMonth(temp.GetMonth() - obj2.GetMonth());
		while (temp.GetMonth() < 1) { //While Months < 1 Year --, Month +=12.
			temp.SetYear(temp.GetYear() - 1);
			temp.SetMonth(temp.GetMonth() + 12);
		}
	}
	temp.SetYear(temp.GetYear() - obj2.GetYear());
	return temp; //Returns temp object
}
Date& operator--(Date& obj) {
	obj.SetDay(obj.GetDay() - 1);
	if (obj.GetDay() < 1) {
		obj.SetMonth(obj.GetMonth() - 1);
		obj.SetDay(obj.DaysInMonth());
		if (obj.GetMonth() < 1) {
			obj.SetMonth(12);
			obj.SetDay(obj.DaysInMonth());
			obj.SetYear(obj.GetYear() - 1);
		}
	}
	return obj;
}
Date operator--(Date& obj, int a) {
	Date temp(obj);
	obj.SetDay(obj.GetDay() - 1);
	if (obj.GetDay() < 1) {
		obj.SetMonth(obj.GetMonth() - 1);
		obj.SetDay(obj.DaysInMonth());
		if (obj.GetMonth() < 1) {
			obj.SetMonth(12);
			obj.SetDay(obj.DaysInMonth());
			obj.SetYear(obj.GetYear() - 1);
		}
	}
	return temp;
}
Date& operator++(Date& obj) //Will add one day to a respective date(Prefix).
{
	obj.SetDay(obj.GetDay() + 1);
	if (obj.GetDay() > obj.DaysInMonth()) { //If Day > Days in Month, Sets day to 1 and checks if the month is correct.
		obj.SetMonth(obj.GetMonth() + 1);
		obj.SetDay(1);
		if (obj.GetMonth() > 12) {
			obj.SetMonth(1);
			obj.SetDay(1);
			obj.SetYear(obj.GetYear() + 1);
		}
	}
	return obj; //returns pointer this.
}
Date operator++(Date& obj, int a) //Will add one day to a respective date(Postfix).
{
	Date temp(obj); // Creating temp object.
	obj.SetDay(obj.GetDay() + 1);
	if (obj.GetDay() > obj.DaysInMonth()) { //If Day > Days in Month, Sets day to 1 and checks if the month is correct.
		obj.SetMonth(obj.GetMonth() + 1);
		obj.SetDay(1);
		if (obj.GetMonth() > 12) {
			obj.SetMonth(1);
			obj.SetDay(1);
			obj.SetYear(obj.GetYear() + 1);
		}
	}
	return temp; // Returns temp object.
}
Date& operator-=(Date& obj, int a) {
	int MonthDaysTemp; //MonthDaysTemp for correct work of DaysInMonth() with Day field.
	obj.SetDay(obj.GetDay() - a);//Substract days.
	while (obj.GetDay() < 1) {
		MonthDaysTemp = obj.DaysInMonth();
		obj.SetMonth(obj.GetMonth() - 1);
		obj.SetDay(obj.GetDay() + MonthDaysTemp);
		while (obj.GetMonth() < 1) {
			obj.SetYear(obj.GetYear() - 1);
			obj.SetMonth(obj.GetMonth() + 12);
		}
	}
	return obj; //returns object
}
Date& operator+=(Date& obj, int a) {
	int MonthDaysTemp;
	obj.SetDay(obj.GetDay() + a);
	while (obj.GetDay() > obj.DaysInMonth()) {
		MonthDaysTemp = obj.DaysInMonth();
		obj.SetMonth(obj.GetMonth() + 1);
		obj.SetDay(obj.GetDay() - MonthDaysTemp);
		while (obj.GetMonth() > 12) {
			obj.SetYear(obj.GetYear() + 1);
			obj.SetMonth(obj.GetMonth() - 12);
		}
	}
	return obj; //returns object
}
bool operator>(int a, const Date& b) {
	if (a > b.GetYear()) return 1;
	if (a < b.GetYear()) return 0;
	if (a > b.GetMonth()) return 1;
	if (a < b.GetMonth()) return 0;
	if (a > b.GetDay())return 1;
	return 0;
}
bool operator>(const Date& a, const Date& b) {
	if (a.GetYear() > b.GetYear()) return 1;
	if (a.GetYear() < b.GetYear()) return 0;
	if (a.GetMonth() > b.GetMonth()) return 1;
	if (a.GetMonth() < b.GetMonth()) return 0;
	if (a.GetDay() > b.GetDay())return 1;
	return 0;
}
bool operator<(int a, const Date& b) {
	if (a < b.GetYear()) return 1;
	if (a < b.GetYear()) return 0;
	if (a < b.GetMonth()) return 1;
	if (a < b.GetMonth()) return 0;
	if (a < b.GetDay())return 1;
	return 0;
}
bool operator<(const Date& a, const Date& b) {
	if (a.GetYear() < b.GetYear()) return 1;
	if (a.GetYear() < b.GetYear()) return 0;
	if (a.GetMonth() < b.GetMonth()) return 1;
	if (a.GetMonth() < b.GetMonth()) return 0;
	if (a.GetDay() < b.GetDay())return 1;
	return 0;
}
bool operator>=(int a, const Date& b) {
	if (operator>(a, b)) return 1;
	if (a == b.GetDay() && a == b.GetMonth() && a == b.GetYear()) return 1;
	return 0;
}
bool operator<=(int a, const Date& b) {
	if (operator<(a, b)) return 1;
	if (a == b.GetDay() && a == b.GetMonth() && a == b.GetYear()) return 1;
	return 0;
}
bool operator==(const Date& a, const Date& b) {
	if (a.GetDay() == b.GetDay() && a.GetMonth() == b.GetMonth() && a.GetYear() == b.GetYear())return 1;
	return 0;

}
bool operator!=(const Date& a, const Date& b) {
	if (a.GetDay() == b.GetDay() && a.GetMonth() == b.GetMonth() && a.GetYear() == b.GetYear())return 0;
	return 1;
}