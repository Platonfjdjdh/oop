#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <algorithm>

class STUDENT {
private:
    std::string name;
    int groupNumber;
    double grades[5];

public:
    STUDENT();

    void setName(const std::string& n);
    void setGroupNumber(int num);
    void setGrades(const double* g);

    std::string getName() const;
    int getGroupNumber() const;
    const double* getGrades() const;

    double calculateAverageGrade() const;

    friend std::ostream& operator<<(std::ostream& os, const STUDENT& student);
    friend std::istream& operator>>(std::istream& is, STUDENT& student);
};

#endif // STUDENT_H
