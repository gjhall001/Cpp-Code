// Author: Gregory Hall

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

void testMenu();
// Postcondition: the test menu is displayed for choice

bool isLeapYear(int year);
// Precondition: Takes year as an int value
// Postcondition: Leap year is determined by taking the
//  first two digits of year and divide by 4 then save remainder,
//  then subtract the remainder from 3 and this value is
//  multiplied by 2 and returned

int getCenturyValue(int year);
// Precondition: Takes year value as an int value
// Postcondition: Returns the remainder (modulo) of Year % 7

int getYearValue(int year);
// Precondition: Takes year value as an int value
// Postcondition: The last two digits of the year is divided by 4
// and this value is added together with the last two digits of the year
// and returned

int getMonthValue(int year, int month);
// Precondition: Takes year and month value as int values
// Postcondition: Using a switch statement with month as the controlling
// expression,the value 6 is returned for January or the value 2
// for February, if the year is a leap year, if not the following values
// are returned by month, Jan=0, Feb=3, Mar=3, Apr=6, May=1, June=4,
// Jul=6, Aug=2, Sep=5, Oct=0, Nov=3, Dec=5

int dayOfWeek(int month, int day, int year);
// Precondition: Takes int values for month, day, and year
// Postconditon: Calculates the sum of (day + getMonthValue(month, year) + getYearValue(year) + getCenturyValue(year))
// and returns the remainder of (sum % 7)

string dayOfWeek(int day);
// pre-condition: day has integer value 0, 1, 2, 3, 4, 5, or 6
// post-condition: the name of the day of week is returned as a string. If day
// has value 0, then SUNDAY is returned; 1, then MONDAY is returned; and so on.

int main()
{
	using namespace std;

	int choice;
	int day, month, year;
	do
	{
		testMenu();
		cout << "Please choose from menu: ";
		cin >> choice;
		switch (choice)
		{
		case 1: // check if a given year is leap year
			cout << "Please enter a year: ";
			cin >> year;

			// Year value must be greater than 1582
			while (year <= 1582)
			{
				cout << "Year value is incorrect. Year is valid if it is later than 1582.\nPlease enter a year: ";
				cin >> year;
			}

			if (isLeapYear(year))
				cout << "Year " << year << " is a leap year" << endl;
			else
				cout << "Year " << year << " is NOT a leap year" << endl;
			break;

		case 2: // calculate the century value of a given year
			cout << "Please enter a year: ";
			cin >> year;

			// Year value must be greater than 1582
			while (year <= 1582)
			{
				cout << "Year value is incorrect. Year is valid if it is later than 1582.\nPlease enter a year: ";
				cin >> year;
			}

			cout << "The century value is: " << getCenturyValue(year) << endl;
			break;

		case 3: // calculate the year value of a given year
			cout << "Please enter a year: ";
			cin >> year;

			// Year value must be greater than 1582
			while (year <= 1582)
			{
				cout << "Year value is incorrect. Year is valid if it is later than 1582.\nPlease enter a year: ";
				cin >> year;
			}

			cout << "The year value is: " << getYearValue(year) << endl;
			break;

		case 4: // calculate the month value of a given month in a given year
			cout << "Please enter a year and month: ";
			cin >> year >> month;

			// Year value must be greater than 1582
			while (year <= 1582)
			{
				cout << "Year value is incorrect. Year is valid if it is later than 1582.\nPlease enter a year: ";
				cin >> year;
			}

			// Month value must be between 1-12
			while ((month < 1) || (month > 12))
			{
				cout << "Month value is incorrect. Month is valid if it is between [1-12].\nPlease enter a month: ";
				cin >> month;
			}

			cout << "The month value is: " << getMonthValue(year, month) << endl;
			break;

		case 5: // calculate the day of week of a given date
			cout << "Please enter a year, a month, and a day : ";
			cin >> year >> month >> day;

			// Year value must be greater than 1582
			while (year <= 1582)
			{
				cout << "Year value is incorrect. Year is valid if it is later than 1582.\nPlease enter a year: ";
				cin >> year;
			}

			// Month value must be between 1-12
			while ((month < 1) || (month > 12))
			{
				cout << "Month value is incorrect. Month is valid if it is between [1-12].\nPlease enter a month: ";
				cin >> month;
			}

			cout << "The day of the week is: " << dayOfWeek(month, day, year) << endl;
			break;

		case 6: // print out the name of a given day of week
			cout << "Please enter a day of week (0 for Sunday, 1 for Monday, etc): ";
			cin >> day;
			cout << "The name of the day of the week is: " << dayOfWeek(day)
				 << endl;
			break;
		case 7:
			cout << "Did you test all functions yet? If not, please rerun the program.\n";
			break;
		default:
			cout << "Wrong option. Please choose from menu.\n";
			break;
		}

		system("pause");

	} while (choice != 7);

	return 0;
}

void testMenu()
{
	cout << "*************************************\n"
		 << "* Test Menu *\n"
		 << "* 1. isLeapYear *\n"
		 << "* 2. getCenturyValue *\n"
		 << "* 3. getYearValue *\n"
		 << "* 4. getMonthValue *\n"
		 << "* 5. dayOfWeek(month, day, year) *\n"
		 << "* 6. dayOfWeek (day) *\n"
		 << "* 7. Quit *\n"
		 << "*************************************\n";

	return;
}

bool isLeapYear(int year)
{
	int first2Digits = year / 100;
	int remainder = first2Digits % 4;
	double result = 3 - remainder;
	return (result * 2);
}

int getCenturyValue(int year)
{
	return (year % 7);
}

int getYearValue(int year)
{
	int last2Digits, nextStep;

	last2Digits = year % 100;
	nextStep = last2Digits / 4;

	return (last2Digits + nextStep);
}

int getMonthValue(int year, int month)
{
	switch (month)
	{

	case 1:
		if (isLeapYear(year))
		{
			return (6);
		}
		else
		{
			return (0);
		}
		break;
	case 2:
		if (isLeapYear(year))
		{
			return (2);
		}
		else
		{
			return (3);
		}
		break;
	case 3:
		return 3;
		break;
	case 4:
		return 6;
		break;
	case 5:
		return 1;
		break;
	case 6:
		return 4;
		break;
	case 7:
		return 6;
		break;
	case 8:
		return 2;
		break;
	case 9:
		return 5;
		break;
	case 10:
		return 0;
		break;
	case 11:
		return 3;
		break;
	case 12:
		return 5;
		break;
	default:
		"You have entered an incorrect month value. Please enter 1 for January, 2 for February, and so forth.";
	}
}

int dayOfWeek(int month, int day, int year)
{
	int sum = day + getMonthValue(month, year) + getYearValue(year) + getCenturyValue(year);

	return (sum % 7);
}

string dayOfWeek(int day)
{
	switch (day)
	{
	case 0:
		return ("SUNDAY");
		break;
	case 1:
		return ("MONDAY");
		break;
	case 2:
		return ("TUESDAY");
		break;
	case 3:
		return ("WEDNESDAY");
		break;
	case 4:
		return ("THURSDAY");
		break;
	case 5:
		return ("FRIDAY");
		break;
	case 6:
		return ("SATURDAY");
		break;
	default:
		return ("-1");
	}
}