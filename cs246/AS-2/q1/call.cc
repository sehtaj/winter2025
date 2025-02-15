#include "call.h"
#include <iomanip>
#include <iostream>

using namespace std;

Call::Call(Date date, int startTime, int duration) : date(date), startTime(startTime), duration(duration) {}

std::istream &operator>>(std::istream &in, Call &call) {
    in >> call.date >> call.startTime;
    if (!(in >> call.duration)) {
        call.duration = 1; 
    }
    return in;
}

ostream &operator<<(ostream &out, Call &call) {
    out << call.date << " " << call.startTime << " " << call.duration;
    return out;
}