#include "Student.h"

STUDENT::STUDENT() : groupNumber(0) {
    std::fill(grades, grades + 5, 0.0);
}

void STUDENT::setName(const std::string& n) {
    name = n;
}

void STUDENT::setGroupNumber(int num) {
    groupNumber = num;
}

void STUDENT::setGrades(const double* g) {
    std::copy(g, g + 5, grades);
}

std::string STUDENT::getName() const {
    return name;
}

int STUDENT::getGroupNumber() const {
    return groupNumber;
}

const double* STUDENT::getGrades() const {
    return grades;
}

double STUDENT::calculateAverageGrade() const {
    double sum = 0.0;
    for (int i = 0; i < 5; ++i) {
        sum += grades[i];
    }
    return sum / 5.0;
}
