#include "canvas.h"
#include <iostream>

Canvas::Canvas() : canvasWidth(0), canvasHeight(0) {}

Canvas::Canvas(const Canvas &other) : rectangles(other.rectangles), canvasWidth(other.canvasWidth), canvasHeight(other.canvasHeight) {}

Canvas::Canvas(Canvas &&other) : rectangles(std::move(other.rectangles)), canvasWidth(other.canvasWidth), canvasHeight(other.canvasHeight) {
    other.canvasWidth = 0;
    other.canvasHeight = 0;
}

Canvas::~Canvas() {}

Canvas &Canvas::operator=(const Canvas &other) {
    if (this != &other) {
        rectangles = other.rectangles;
        canvasWidth = other.canvasWidth;
        canvasHeight = other.canvasHeight;
    }
    return *this;
}

Canvas &Canvas::operator=(Canvas &&other) {
    if (this != &other) {
        rectangles = std::move(other.rectangles);
        canvasWidth = other.canvasWidth;
        canvasHeight = other.canvasHeight;
        other.canvasWidth = 0;
        other.canvasHeight = 0;
    }
    return *this;
}

void Canvas::add(const Rectangle &rectangle) {
    rectangles.push_back(rectangle);
    canvasWidth = std::max(canvasWidth, rectangle.point().x() + rectangle.width());
    canvasHeight = std::max(canvasHeight, rectangle.point().y() + rectangle.height());
}

int Canvas::numRectangles() const {
    return rectangles.size();
}

int Canvas::width() const {
    return canvasWidth;
}

int Canvas::height() const {
    return canvasHeight;
}

Rectangle Canvas::get(int rectangleId) const {
    return rectangles.at(rectangleId);
}

void Canvas::translate(int rectangleId, int x, int y) {
    rectangles.at(rectangleId).translate(x, y);
}

void Canvas::scale(int rectangleId, float heightFactor, float widthFactor) {
    rectangles.at(rectangleId).scale(heightFactor, widthFactor);
}

void Canvas::change(int rectangleId, Rectangle::Colour newColour) {
    rectangles.at(rectangleId).change(newColour);
}

void Canvas::remove(int rectangleId) {
    if (rectangleId >= 0 && rectangleId < numRectangles()) {
        rectangles.erase(rectangles.begin() + rectangleId);
    }
}

std::ostream &operator<<(std::ostream &out, const Canvas &canvas) {
    out << "Canvas (" << canvas.width() << "x" << canvas.height() << ") with " << canvas.numRectangles() << " rectangles:\n";
    for (int i = 0; i < canvas.numRectangles(); ++i) {
        out << "  Rectangle " << i << ": " << canvas.get(i) << "\n";
    }
    return out;
}
