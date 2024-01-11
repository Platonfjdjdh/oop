#include "Student.h"
#include "StudentTest.cpp"

int main() {
    const int arraySize = 10;
    STUDENT students[arraySize];

    for (int i = 0; i < arraySize; ++i) {
        std::cin >> students[i];
    }

    std::sort(students, students + arraySize, [](const STUDENT& a, const STUDENT& b) {
        return a.calculateAverageGrade() < b.calculateAverageGrade();
    });

    bool found = false;
    for (int i = 0; i < arraySize; ++i) {
        if (students[i].calculateAverageGrade() >= 4.0) {
            std::cout << students[i].getName() << ", Group: " << students[i].getGroupNumber() << std::endl;
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
