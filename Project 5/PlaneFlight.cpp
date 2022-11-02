// 
// FrequentFlyerAcccount.cpp
//
//
//
//

#include "FrequentFlyerAccount.h"
#include "PlaneFlight.h"
#include <iostream>
#include <string>


using namespace std;


PlaneFlight::PlaneFlight() //constructor - initialize data members
{
	mCost = 0.0;
	mFromCity = "?fromCity?";
	mToCity = "?toCity?";
	mName = "?name?";
	mMileage = 0.000000;
}

PlaneFlight::PlaneFlight(string passengerName, string fromCity, string toCity, double cost, double mileage)
{
	if (passengerName != "")
	{
		mName = passengerName;
	}

	if ((fromCity != "") && (fromCity != toCity))
	{
	mFromCity = fromCity;
	}

	if ((toCity != "") && (toCity != fromCity))
	{
		mToCity = toCity;
	}

	if (cost >= 0)
	{
		mCost = cost;
	}
	else
	{
		mCost = -1;
	}

	if (mileage > 0)
	{
		mMileage = mileage;
	}
	else
	{
		mMileage = -1;
	}
}


//--modifiers

void PlaneFlight::setName(string name)
{
	if (name != "")
	{
		mName = name;
	}
}

void PlaneFlight::setToCity(string to)
{
	if ((to != "") && (to != mFromCity))
	{
		mToCity = to;
	}
}

void PlaneFlight::setFromCity(string from)
{
	if ((from != "") && (from != mToCity))
	{
		mFromCity = from;
	}
}

void PlaneFlight::setCost(double cost)
{
	if (cost >= 0)
	{
		mCost = cost;
	}
	else
		mCost = -1;
}

void PlaneFlight::setMileage(double mileage)
{
	if (mileage > 0)
	{
		mMileage = mileage;
	}
	else
		mMileage = -1;
}


//--accessors


double PlaneFlight::getCost()
{
	return mCost;
}

double PlaneFlight::getMileage()
{
	return mMileage;
}

string PlaneFlight::getName()
{
	return mName;
}

string PlaneFlight::getFromCity()
{
	return mFromCity;
}

string PlaneFlight::getToCity()
{
	return mToCity;
}






