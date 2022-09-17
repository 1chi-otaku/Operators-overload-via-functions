#pragma once
#include <iostream>
#include "Date.h"
using namespace std;

Date operator+(int a, const Date obj); //Addtion operation via int value. Will try to add an int value to a respective date.
Date operator+(Date obj, const Date obj2);  //Addtion operation via int value. Will try to add an a date to a respective date.
Date operator-(int a, Date& obj); //Subtraction operation via int value. Will try to subtract an int value from a respective date.
Date operator-(const Date& obj, const Date& obj2);
Date& operator--(Date& obj); //Will substract one day from a respective date(Prefix).
Date operator--(Date& obj, int a); //Will add one day to a respective date(Postfix).
Date& operator++(Date& obj); //Will add one day to a respective date(Prefix).
Date operator++(Date& obj, int a); //Will add one day to a respective date(Postfix).
Date& operator-=(Date& obj, int a); //Subtract AND assignment operator.
Date& operator+=(Date& obj, int a); //Add AND assignment operator.

bool operator>(int a, const Date& b); //Checks if the date larger than int value, it it is, returns true, otherwise returns false.
bool operator>(const Date& a, const Date& b); //Checks if the date larger than other date, it it is, returns true, otherwise returns false.
bool operator<(int a, const Date& b);				//Checks if the date less than int value, it it is, returns true, otherwise returns false.
bool operator<(const Date& a, const Date& b); //Checks if the date less than other date, it it is, returns true, otherwise returns false.
bool operator>=(int a, const Date& b);
bool operator<=(int a, const Date& b);
bool operator==(const Date& a, const Date& b);
bool operator!=(const Date& a, const Date& b);