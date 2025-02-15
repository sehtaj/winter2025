#ifndef _DATE_H
#define _DATE_H
#include <iostream>

struct Date {
    enum class DayOfWeek {Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday};

    int year, month, day;
    Date( int y, int m, int d );
    DayOfWeek getDay(); // Requires date to be in Gregorian calendar.
    bool operator==( Date other );
    bool operator<( Date other );
};

std::istream & operator>>( std::istream & in, Date & date );
std::ostream & operator<<( std::ostream & out, Date &date );
std::ostream & operator<<( std::ostream & out, Date::DayOfWeek day );

#endif
