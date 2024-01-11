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
        assert(student.getGroup() == "");
        assert(student.getAverageGrade() == 0.0);
    }

    void testStudentInputOutput() {
        STUDENT student;
        std::istringstream input("John Doe\nGroupA\n5 4 3 2 1");
        input >> student;
        assert(student.getName() == "John Doe");
        assert(student.getGroup() == "GroupA");
        assert(student.getAverageGrade() == 3.0);

        std::ostringstream output;
        output << student;
        std::string expectedOutput = "          John Doe   GroupA     3\n";
        assert(output.str() == expectedOutput);
    }

    void testStudentSorting() {
        STUDENT students[3];
        std::istringstream input1("John Doe\nGroupA\n5 4 3 2 1");
        std::istringstream input2("Alice Smith\nGroupB\n4 3 4 5 5");
        std::istringstream input3("Bob Johnson\nGroupC\n2 3 2 4 5");

        input1 >> students[0];
        input2 >> students[1];
        input3 >> students[2];

        std::sort(students, students + 3, [](const STUDENT& a, const STUDENT& b) {
            return a.getAverageGrade() < b.getAverageGrade();
        });

        assert(students[0].getName() == "Bob Johnson");
        assert(students[1].getName() == "John Doe");
        assert(students[2].getName() == "Alice Smith");
    }
};

int main() {
    StudentTest studentTest;
    studentTest.runTests();
    std::cout << "All tests passed!\n";

    return 0;
}
