#include "plan.h"
#include "call.h"
#include <iostream>
#include <iomanip>  

using namespace std;

Plan::Plan() {}

Plan::~Plan() {
    calls.clear(); 
}

void Plan::add(const Call &call) {
    calls.push_back(call);
}

void Plan::calculateBill() {
    for (size_t i = 0; i < calls.size(); i++) {
        for (size_t j = 0; j < calls.size() - 1; j++) {
            if (calls[j + 1].date < calls[j].date || 
               (calls[j + 1].date == calls[j].date && calls[j + 1].startTime < calls[j].startTime)) {
                Call temp = calls[j];
                calls[j] = calls[j + 1];
                calls[j + 1] = temp;
            }
        }
    }

    int totalChargeableMinutes = 0;
    double totalCost = monthlyFee;
    int currentMonth = calls[0].date.month; 

    for (size_t i = 0; i < calls.size(); i++) {
        cout << calls[i] << endl;

        if (calls[i].date.month != currentMonth) {
            cout << "Total Charge for " << currentMonth << ": $" 
                 << fixed << setprecision(2) << totalCost << endl;

            totalChargeableMinutes = 0;
            totalCost = monthlyFee;
            currentMonth = calls[i].date.month;
        }

        int start = calls[i].startTime;
        int duration = calls[i].duration;
        Date::DayOfWeek day = calls[i].date.getDay();

        if (!((start >= 1800 || start < 700) || 
              (day == Date::DayOfWeek::Saturday || day == Date::DayOfWeek::Sunday))) {
            totalChargeableMinutes += duration;
        }

        if (totalChargeableMinutes > 150) {
            totalCost += (totalChargeableMinutes - 150) * extraCharge;
        }
    }

    cout << "Total Charge for " << currentMonth << ": $" 
         << fixed << setprecision(2) << totalCost << endl;

    calls.clear();
}

ostream &operator<<(ostream &out, const Plan &plan) {
    for (size_t i = 0; i < plan.calls.size(); i++) {
        out << plan.calls[i] << endl;
    }
    return out;
}