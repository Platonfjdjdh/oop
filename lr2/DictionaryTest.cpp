#include "BinaryTree.h"

class DictionaryTest {
private:
    BinaryTree<std::string, std::string> dictionary;

    void runTest(bool condition, const std::string& testName) {
        if (condition) {
            std::cout << "Test Passed: " << testName << "\n";
        } else {
            std::cout << "Test Failed: " << testName << "\n";
        }
    }

public:
    void runTests() {
        // Test 1: Add Word and Get Translation
        dictionary.addWord("apple", "яблоко");
        std::string translation = dictionary.getTranslation("apple");
        runTest(translation == "яблоко", "Add Word and Get Translation");

        // Test 2: Translation Not Found
        translation = dictionary.getTranslation("nonexistent");
        runTest(translation.empty(), "Translation Not Found");

        // Test 3: Display Dictionary
        std::cout << "Test 3: Display Dictionary\n";
        dictionary.addWord("banana", "банан");
        testing::internal::CaptureStdout();
        dictionary.displayDictionary();
        std::string output = testing::internal::GetCapturedStdout();
        std::string expected_output = "Dictionary:\napple - яблоко\nbanana - банан";
        runTest(output == expected_output, "Display Dictionary");

        // Test 4: Menu Interaction
        std::cout << "Test 4: Menu Interaction\n";
        std::istringstream input_stream("1\napple\nяблоко\n2\napple\n3\n4\n");
        std::streambuf* old_cin = std::cin.rdbuf(input_stream.rdbuf());
        // Запускаем программу, которую нужно тестировать
        // Здесь вместо вызова функции main() из вашего основного файла, вызовите соответствующую функцию
        std::cin.rdbuf(old_cin);

        std::cout << "Tests completed.\n";
    }
};