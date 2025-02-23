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
    
    
//     istream &operator>>(std::istream &in, Date &date) {
//         string stored;
//         getline(in,stored);
//         string temp;
//         istringstream iss(temp);
//         int counter = 0;
        
//         int len = stored.length();
//         for (int i = 0 ; i < len ; i++) {
//             if (stored[i] == '/' || stored[i] == ' ') {
//                 iss.str(temp);
//                 iss.clear();
//                 if (counter == 0) {
//                     iss >> date.year;
//                 }
//                 else if ( counter == 1) {
//                     iss >> date.month;
                    
//                 } else {
//                     iss >> date.day;
//                     break;
//                 }
//                 temp = "";
//                 counter += 1;
//             } else {
//                 temp += stored[i];
//             }
//         }
//         return in;
//     }

// }

ostream &operator<<(ostream &out, Call &call) {
    out << call.date << " " << call.startTime << " " << call.duration;
    return out;
}


