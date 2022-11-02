// 
// FrequentFlyerAcccount.h
//
//
//
//

#ifndef FrequentFlyerAccount_h
#define FrequentFlyerAccount_h

#include <iostream>
#include <string>
#include "PlaneFlight.h"

using namespace std;

class FrequentFlyerAccount

{

public:

	FrequentFlyerAccount();
	FrequentFlyerAccount(string name);

	double getBalance();
	string getName();

	bool addFlightToAccount(PlaneFlight flight);
	bool canEarnFreeFlight(double mileage);
	bool freeFlight(string from, string to, double milage, PlaneFlight &flight);

private:

	string mName;
	double mBalance;

};


#endif /* FrequentFlyerAcccount_h */