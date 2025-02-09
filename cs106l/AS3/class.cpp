#include "class.h"
#include <iostream>

Student::Student() : name("Unknown"), cgpa(0.0) {}

Student::Student(const std::string& name, double cgpa) : name(name), cgpa(cgpa) {
    if (!isCgpaValid(cgpa)) {
        this->cgpa = 0.0;
    }
}

std::string Student::getName() const {
    return name;
}

void Student::setName(const std::string& newName) {
    name = newName;
}

bool Student::isCgpaValid(double cgpa) {
    return cgpa >= 0.0 && cgpa <= 10.0;
}