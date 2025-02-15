#ifndef _PLAN_H
#define _PLAN_H
#include "call.h"
#include <vector>

class Plan {
private:
    std::vector<Call> calls;
    const int monthlyFee = 25;
    const double extraCharge = 0.50;
    
    /* Your private member variables and functions */

    friend std::ostream & operator<<( std::ostream & out, const Plan & plan );

public:
    Plan();
    ~Plan();

    // Adds the call to the month's current list of calls.
    void add( const Call &call ); 

    // Outputs the month's current list of calls and the amount owed.
    // Clears out the calls for the month.
    void calculateBill(); 
};

// Outputs the current month's calls, ordered by date and then by start time 
// within date. 
std::ostream & operator<<( std::ostream & out, const Plan & plan );

#endif

