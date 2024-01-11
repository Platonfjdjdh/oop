#include <iostream>
#include <cassert>
#include <sstream>

#include "Student.h"

class StudentTest {
public:
    void runTests() {
        testStudentInitialization();
        testStudentInputOutput();
        testStudentSorting();
    }

private:
    void testStudentInitialization() {
        STUDENT student;
        assert(student.getName() == "");
        assert(student.getGroupNumber() == 0);
        const double* grades = student.getGrades();
        for (int i = 0; i < 5; ++i) {
            assert(grades[i] == 0.0);
        }
    }

    void testStudentInputOutput() {
        STUDENT student;
        std::istringstream input("John Doe\n42\n5.0 4.0 3.0 2.0 1.0");
        input >> student;
        assert(student.getName() == "John Doe");
        assert(student.getGroupNumber() == 42);
        const double* grades = student.getGrades();
        assert(grades[0] == 5.0);
        assert(grades[1] == 4.0);
        assert(grades[2] == 3.0);
        assert(grades[3] == 2.0);
        assert(grades[4] == 1.0);

        std::ostringstream output;
        output << student;
        std::string expectedOutput = "John Doe, Group: 42, Grades: 5 4 3 2 1\n";
        assert(output.str() == expectedOutput);
    }

    void testStudentSorting() {
        STUDENT students[3];
        std::istringstream input1("John Doe\n42\n5.0 4.0 3.0 2.0 1.0");
        std::istringstream input2("Alice Smith\n42\n4.0 3.0 4.0 5.0 5.0");
        std::istringstream input3("Bob Johnson\n42\n2.0 3.0 2.0 4.0 5.0");

        input1 >> students[0];
        input2 >> students[1];
        input3 >> students[2];

        std::sort(students, students + 3, [](const STUDENT& a, const STUDENT& b) {
            return a.calculateAverageGrade() < b.calculateAverageGrade();
        });

        assert(students[0].getName() == "Bob Johnson");
        assert(students[1].getName() == "John Doe");
        assert(students[2].getName() == "Alice Smith");
    }
};