#include "Student.h"
#include "StudentTest.cpp"

int main() {
    const int numStudents = 4;
    STUDENT students[numStudents];

    for (int i = 0; i < numStudents; ++i) {
        std::cout << "Enter data for student " << i + 1 << ":" << std::endl;
        std::cin >> students[i];
    }

    std::sort(students, students + numStudents, [](const STUDENT& a, const STUDENT& b) {
        return a.getAverageGrade() < b.getAverageGrade();
    });

    bool found = false;
    std::cout << "Students with grades 4 and 5:" << std::endl;
    for (int i = 0; i < numStudents; ++i) {
        if (students[i].getAverageGrade() >= 4.0) {
            std::cout << students[i].getName() << " (" << students[i].getGroup() << ")" << std::endl;
            found = true;
        }
    }

    if (!found) {
        std::cout << "No students with grades 4 and 5 found." << std::endl;
    }

    StudentTest studentTest;
    studentTest.runTests();
    std::cout << "All tests passed!\n";

    return 0;
}
