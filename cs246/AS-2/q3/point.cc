#include "point.h"

Point::Point(int x, int y) : xCoord(x), yCoord(y) {}

int Point::x() const {
    return xCoord;
}

int Point::y() const {
    return yCoord;
}

Point Point::operator+(const Point &other) {
    return Point(xCoord + other.x(), yCoord + other.y());
}

std::ostream &operator<<(std::ostream &out, const Point &point) {
    out << "(" << point.x() << ", " << point.y() << ")";
    return out;
}
