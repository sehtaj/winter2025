#include "call.h"
#include <iomanip>
#include <iostream>

using namespace std;

Call::Call(Date date, int startTime, int duration) : date(date), startTime(startTime), duration(duration) {}

std::istream &operator>>(std::istream &in, Call &call) {
    in >> call.date >> call.startTime >> call.duration;
    if (call.duration <= 0) {
        cout << "Invalid call duration! Expected a positive integer\n";
        call.duration = 0;
        call.startTime = 0;
        call.date = Date{0,0,0};
    }
    return in;
}


ostream &operator<<(ostream &out, Call &call) {
    out << call.date << " " << call.startTime << " " << call.duration;
    return out;
}


