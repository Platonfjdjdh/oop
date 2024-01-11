#include "Student.h"

STUDENT::STUDENT() {
    for (int i = 0; i < 5; ++i) {
        grades[i] = 0;
    }
}

void STUDENT::setName(const std::string& n) {
    name = n;
}

void STUDENT::setGroup(const std::string& g) {
    group = g;
}

void STUDENT::setGrades(const int g[]) {
    for (int i = 0; i < 5; ++i) {
        grades[i] = g[i];
    }
}

std::string STUDENT::getName() const {
    return name;
}

std::string STUDENT::getGroup() const {
    return group;
}

double STUDENT::getAverageGrade() const {
    double sum = 0;
    for (int i = 0; i < 5; ++i) {
        sum += grades[i];
    }
    return sum / 5.0;
}

std::istream& operator>>(std::istream& in, STUDENT& student) {
    std::cout << "Enter name: ";
    std::getline(in, student.name);

    std::cout << "Enter group: ";
    std::getline(in, student.group);

    std::cout << "Enter grades (5 space-separated integers): ";
    for (int i = 0; i < 5; ++i) {
        in >> student.grades[i];
    }

    return in;
}

std::ostream& operator<<(std::ostream& out, const STUDENT& student) {
    out << std::setw(20) << student.name << std::setw(10) << student.group << std::setw(8) << student.getAverageGrade();
    return out;
}
