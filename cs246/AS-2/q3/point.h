#ifndef _POINT_H
#define _POINT_H
#include <iostream>

class Point {

    /* Add your private variables and functions HERE */
	int a, b;

public:
	Point( int x = 0, int y = 0 );
	int x() const;
	int y() const;
	Point operator+( const Point & other );
};

std::ostream & operator<<( std::ostream & out, const Point & point );

#endif
