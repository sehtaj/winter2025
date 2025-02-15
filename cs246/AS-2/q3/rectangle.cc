#include "rectangle.h"

Rectangle::Rectangle(Point upperLeft, int height, int width, Rectangle::Colour colour)
    : upperLeft_(upperLeft), height_(height), width_(width), colour_(colour) {}

void Rectangle::translate(int x, int y) {
    upperLeft_ = upperLeft_ + Point(x, y);
}

void Rectangle::scale(float heightFactor, float widthFactor) {
    height_ = static_cast<int>(height_ * heightFactor);
    width_ = static_cast<int>(width_ * widthFactor);
}

void Rectangle::change(Rectangle::Colour newColour) {
    colour_ = newColour;
}

Rectangle::Colour Rectangle::colour() const {
    return colour_;
}

Point Rectangle::position() const {
    return upperLeft_;
}

int Rectangle::width() const {
    return width_;
}

int Rectangle::height() const {
    return height_;
}

std::istream &operator>>(std::istream &in, Rectangle &rectangle) {
    int x, y, height, width;
    char colourChar;
    in >> colourChar >> x >> y >> height >> width;

    Rectangle::Colour colour;
    switch (colourChar) {
        case 'r': colour = Rectangle::Colour::Red; break;
        case 'g': colour = Rectangle::Colour::Green; break;
        case 'b': colour = Rectangle::Colour::Blue; break;
        case 'o': colour = Rectangle::Colour::Orange; break;
        case 'y': colour = Rectangle::Colour::Yellow; break;
        case 'a': colour = Rectangle::Colour::Black; break;
        case 'w': colour = Rectangle::Colour::White; break;
        default: return in;
    }

    rectangle = Rectangle(Point(x, y), height, width, colour);
    return in;
}

std::ostream &operator<<(std::ostream &out, const Rectangle &rectangle) {
    char colourChar;
    switch (rectangle.colour()) {
        case Rectangle::Colour::Red: colourChar = 'r'; break;
        case Rectangle::Colour::Green: colourChar = 'g'; break;
        case Rectangle::Colour::Blue: colourChar = 'b'; break;
        case Rectangle::Colour::Orange: colourChar = 'o'; break;
        case Rectangle::Colour::Yellow: colourChar = 'y'; break;
        case Rectangle::Colour::Black: colourChar = 'a'; break;
        case Rectangle::Colour::White: colourChar = 'w'; break;
    }

    out << colourChar << " " << rectangle.position().x() << " " << rectangle.position().y()
        << " " << rectangle.height() << " " << rectangle.width();
    
    return out;
}