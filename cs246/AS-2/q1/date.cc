#include "date.h"
#include <iomanip>

using namespace std;

Date::Date(int y, int m, int d) : year(y), month(m), day(d) {}

bool Date::operator==(Date other) {
    return year == other.year && month == other.month && day == other.day;
}

bool Date::operator<(Date other) {
    if (year != other.year) return year < other.year;
    if (month != other.month) return month < other.month;
    return day < other.day;
}


istream &operator>>(std::istream &in, Date &date) {
    char sep1, sep2;
    in >> date.year >> sep1 >> date.month >> sep2 >> date.day;
    
    if (sep1 != '/' || sep2 != '/') {
        std::cerr << "Invalid date format! Expected format: YYYY/MM/DD\n";
        in.clear();       
        return in;
    }
    return in;
}

ostream &operator<<(ostream &out, Date &date) {
    out << date.year << "/" << date.month << "/" << date.day;
    return out;
}

std::ostream &operator<<(std::ostream &out, const Date &date) {
    out << date.year << "/" << date.month << "/" << date.day;
    return out;
}

std::ostream &operator<<(std::ostream &out, Date::DayOfWeek day) {
    const char *dayNames[] = {"Sunday", "Monday", "Tuesday", "Wednesday",
                              "Thursday", "Friday", "Saturday"};
    out << dayNames[static_cast<int>(day)];
    return out;
}

// Calculate day of the week using Zeller's Congruence
Date::DayOfWeek Date::getDay() {
    int y = year, m = month;
    if (m < 3) { m += 12; y--; }
    int K = y % 100;
    int J = y / 100;
    int h = (day + (13 * (m + 1)) / 5 + K + (K / 4) + (J / 4) + (5 * J)) % 7;
    
    static const DayOfWeek days[] = {
        DayOfWeek::Saturday, DayOfWeek::Sunday, DayOfWeek::Monday, 
        DayOfWeek::Tuesday, DayOfWeek::Wednesday, DayOfWeek::Thursday, 
        DayOfWeek::Friday
    };
    return days[h];
}

