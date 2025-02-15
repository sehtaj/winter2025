#ifndef _CALL_H
#define _CALL_H

#include "date.h"
#include <iostream>

struct Call {
    Date date;
    int startTime, duration;
    Call( Date date, int startTime, int duration );
};

std::istream & operator>>( std::istream & in, Call & call );
std::ostream & operator<<( std::ostream & out, const Call &call );

#endif