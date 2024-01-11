#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <iomanip>
#include <algorithm>

class STUDENT {
private:
    std::string name;
    std::string group;
    int grades[5];

public:
    STUDENT();

    void setName(const std::string& n);
    void setGroup(const std::string& g);
    void setGrades(const int g[]);

    std::string getName() const;
    std::string getGroup() const;

    double getAverageGrade() const;

    friend std::istream& operator>>(std::istream& in, STUDENT& student);
    friend std::ostream& operator<<(std::ostream& out, const STUDENT& student);
};

#endif // STUDENT_H
