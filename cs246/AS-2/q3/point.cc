#include "point.h"

Point::Point(int x, int y) : a(x), b(y) {}

int Point::x() const {
    return a;
}

int Point::y() const {
    return b;
}

Point Point::operator+(const Point &other) {
    return Point(x() + other.x(), y() + other.y()); 
}

std::ostream &operator<<(std::ostream &out, const Point &point) {
    out << "(" << point.x() << ", " << point.y() << ")"; 
}