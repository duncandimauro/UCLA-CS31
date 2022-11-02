#include <iostream>
#include <string>
using namespace std;

int main()
{
	
	//Initializing variables

	string(month);
	string(dayofweek);

	int m;
	int d;
	int y;
	int c;
	int yearcode;
	int daycode;
	int centurycode;
	

	//Giving variables initial values to prevent errors
	m = 0;
	d = 0;
	y = 0;
	c = 0;
	yearcode = 0;
	daycode = 0;
	centurycode = 0;
	
	//Requesting the user to type out a month and storing that data as a string
	cout << "Provide a month: ";
	cin >> month;

	//Checking which month the user typed and storing the relevant month code in the variable "m"
	if (month == "January")
		m = 1;
	else if (month == "February")
		m = 4;
	else if (month == "March")
		m = 4;
	else if (month == "April")
		m = 0;
	else if (month == "May")
		m = 2;
	else if (month == "June")
		m = 5;
	else if (month == "July")
		m = 0;
	else if (month == "August")
		m = 3;
	else if (month == "September")
		m = 6;
	else if (month == "October")
		m = 1;
	else if (month == "November")
		m = 4;
	else if (month == "December")
		m = 6;
	else { cout << "Invalid month!\n"; return(0); }


	//Requesting the user to type out a day and storing that data in the "d" variable
	cout << "Provide a day: ";
	cin >> d;

	if (d < 1 || d > 31 || cin.fail())
	{
		cout << "Invalid day!\n"; return(0); //Producing an error message if the day is invalid
	}


	//Requesting the user to type out a year and storing that data in the "y" variable
	cout << "Provide a year: ";
	cin >> y;

	if (y < 1 || y > 3000 || cin.fail()) //cin.fail() returns non-zero (true) if the previous cin command failed, such as if somebody typed "a" for the year
	{
		cout << "Invalid year!\n"; return(0); //Producing an error message if the year is invalid
	}

	//Checking if the year provided is a leap year and if the month is January or February, then adjusting the month code properly
	if (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0) && (month == "January" || month == "February"))
	{
		m = m - 1;
	}
	
	c = (y / 100) % 4; //Solving for the century value
	

	//Solving for the century code using the given table
	if (c == 0)
		centurycode = -2;
	else if (c == 1)
		centurycode = 3;
	else if (c == 2)
		centurycode = 1;
	else if (c == 3)
		centurycode = -1;

	yearcode = ((y % 100) / 4) + (y % 100); //solving for the year code using the given equation

	daycode = (centurycode + d + yearcode + m) % 7; //solving for the day code using the given equation

	//Finding the day of the week using the day code that was solved for
	if (daycode == 0)
		dayofweek = "Sunday";
	else if (daycode == 1 || daycode == -6)
		dayofweek = "Monday";
	else if (daycode == 2 || daycode == -5)
		dayofweek = "Tuesday";
	else if (daycode == 3 || daycode == -4)
		dayofweek = "Wednesday";
	else if (daycode == 4 || daycode == -3)
		dayofweek = "Thursday";
	else if (daycode == 5 || daycode == -2)
		dayofweek = "Friday";
	else if (daycode == 6 || daycode == -1)
		dayofweek = "Saturday";

	//Printing the message that states "Month Day, Year was a ____!"
	cout << month << " " << d << ", " << y << " was a " << dayofweek << "!";
}