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


FrequentFlyerAccount::FrequentFlyerAccount() //constructor - initialize data members
{
    mName = "?name?";
    mBalance = 0.0;
}

FrequentFlyerAccount::FrequentFlyerAccount(string name)
{
    if (name != "")
    {
        mName = name;
    }
    mBalance = 0.0;
}


bool FrequentFlyerAccount::addFlightToAccount(PlaneFlight flight)
{
    if ((flight.getName() == mName) && (flight.getCost() > 0))
    {
        mBalance = mBalance + flight.getMileage(); //add the miles to the balance
        return true;
    }
    else if ((flight.getName() == mName) && (flight.getCost() == 0)) //if the flight is a free flight
    {
        mBalance = mBalance - flight.getMileage(); //subtract the miles from the balance
        return true;
    }
    else
        return false;
}

bool FrequentFlyerAccount::canEarnFreeFlight(double mileage)
{
    if (mBalance >= mileage)
        return true;
    else
        return false;
}

bool FrequentFlyerAccount::freeFlight(string from, string to, double mileage, PlaneFlight &flight)
{
    if (mBalance >= mileage)
    {
        flight = PlaneFlight(mName, from, to, 0, mileage);
        return true;
    }
    else
        return false;
}

//--accessors

double FrequentFlyerAccount::getBalance()
{
    return mBalance;
}

string FrequentFlyerAccount::getName()
{
    return mName;
}