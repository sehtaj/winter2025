#include "canvas.h"
#include <iostream>

Canvas::Canvas() : width_(0), height_(0) {}

Canvas::Canvas(const Canvas &other) 
    : width_(other.width_), height_(other.height_), rectangles(other.rectangles) {}

Canvas::Canvas(Canvas &&other) noexcept
    : width_(other.width_), height_(other.height_), rectangles(std::move(other.rectangles)) {
    other.width_ = 0;
    other.height_ = 0;
}

Canvas &Canvas::operator=(const Canvas &other) {
    if (this != &other) {
        width_ = other.width_;
        height_ = other.height_;
        rectangles = other.rectangles;
    }
    return *this;
}

Canvas &Canvas::operator=(Canvas &&other) noexcept {
    if (this != &other) {
        width_ = other.width_;
        height_ = other.height_;
        rectangles = std::move(other.rectangles);
        other.width_ = 0;
        other.height_ = 0;
    }
    return *this;
}

Canvas::~Canvas() {}

void Canvas::add(const Rectangle &rect) {
    rectangles.push_back(rect);
    updateDimensions();
}

void Canvas::remove(int index) {
    if (index >= 0 && index < numRectangles()) {
        rectangles.erase(rectangles.begin() + index);
        updateDimensions();
    }
}

void Canvas::change(int index, Rectangle::Colour newColour) {
    if (index >= 0 && index < numRectangles()) {
        rectangles[index].change(newColour);
    }
}

void Canvas::translate(int index, int dx, int dy) {
    if (index >= 0 && index < numRectangles()) {
        rectangles[index].translate(dx, dy);
        updateDimensions();
    }
}

void Canvas::scale(int index, float heightFactor, float widthFactor) {
    if (index >= 0 && index < numRectangles()) {
        rectangles[index].scale(heightFactor, widthFactor);
        updateDimensions();
    }
}

int Canvas::numRectangles() const {
    return rectangles.size();
}

int Canvas::width() const {
    return width_;
}

int Canvas::height() const {
    return height_;
}

Rectangle Canvas::get(int index) const {
    if (index >= 0 && index < numRectangles()) {
        return rectangles[index];
    }
    return Rectangle(); 
}

void Canvas::updateDimensions() {
    width_ = 0;
    height_ = 0;
    for (const auto &rect : rectangles) {
        int right = rect.position().x() + rect.width();
        int bottom = rect.position().y() + rect.height();
        if (right > width_) width_ = right;
        if (bottom > height_) height_ = bottom;
    }
}

std::ostream &operator<<(std::ostream &out, const Canvas &canvas) {
    for (int i = 0; i < canvas.numRectangles(); ++i) {
        out << "Rectangle " << i << ": " << canvas.rectangles[i] << std::endl;
    }
    return out;
}