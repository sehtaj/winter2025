#include "rectangle.h"

Rectangle::Rectangle(Point upperLeft, int height, int width, Rectangle::Colour colour)
    : upperLeft(upperLeft), rectHeight(height), rectWidth(width), rectColour(colour) {}

void Rectangle::translate(int x, int y) {
    upperLeft = upperLeft + Point(x, y);  
}

void Rectangle::scale(float heightFactor, float widthFactor) {
    rectHeight *= heightFactor;
    rectWidth *= widthFactor;
}

void Rectangle::change(Rectangle::Colour newColour) {
    rectColour = newColour;
}

Rectangle::Colour Rectangle::colour() const {
    return rectColour;
}

Point Rectangle::point() const {
    return upperLeft;
}

int Rectangle::width() const {
    return rectWidth;
}

int Rectangle::height() const {
    return rectHeight;
}

std::istream &operator>>(std::istream &in, Rectangle &rectangle) {
    int x, y, height, width;
    std::string colour;
    in >> x >> y >> height >> width >> colour;

    // Default color is Black
    Rectangle::Colour rectColour = Rectangle::Colour::Black;

    // Matching the color string with valid color names
    if (colour == "Red") {
        rectColour = Rectangle::Colour::Red;
    }
    else if (colour == "Green") {
        rectColour = Rectangle::Colour::Green;
    }
    else if (colour == "Blue") {
        rectColour = Rectangle::Colour::Blue;
    }
    else if (colour == "Orange") {
        rectColour = Rectangle::Colour::Orange;
    }
    else if (colour == "Yellow") {
        rectColour = Rectangle::Colour::Yellow;
    }
    else if (colour == "Black") {
        rectColour = Rectangle::Colour::Black;
    }
    else if (colour == "White") {
        rectColour = Rectangle::Colour::White;
    }
    else {
        // Warn the user about the invalid color and use the default (Black)
        std::cerr << "Warning: Unknown colour '" << colour << "'; defaulting to Black.\n";
    }

    // Set the rectangle with the corresponding values
    rectangle = Rectangle(Point(x, y), height, width, rectColour);
    return in;
}

std::ostream &operator<<(std::ostream &out, const Rectangle &rectangle) {
    out << rectangle.upperLeft.x() << " " << rectangle.upperLeft.y() << " "
        << rectangle.height() << " " << rectangle.width() << " ";

    std::string colour;
    if (rectangle.colour() == Rectangle::Colour::Red) {
        colour = "Red";
    } else if (rectangle.colour() == Rectangle::Colour::Green) {
        colour = "Green";
    } else if (rectangle.colour() == Rectangle::Colour::Blue) {
        colour = "Blue";
    } else if (rectangle.colour() == Rectangle::Colour::Orange) {
        colour = "Orange";
    } else if (rectangle.colour() == Rectangle::Colour::Yellow) {
        colour = "Yellow";
    } else if (rectangle.colour() == Rectangle::Colour::Black) {
        colour = "Black";
    } else if (rectangle.colour() == Rectangle::Colour::White) {
        colour = "White";
    }

    out << colour;
    return out;
}