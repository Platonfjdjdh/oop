#include "SentenceSearcher.h"
#include <cassert>
#include <iostream>
#include <fstream>
#include <sstream>
class SentenceSearcherTest {
public:
    static void runTests() {
        testContainsWord();
        testSearchSentences();
    }

private:
    static void testContainsWord() {
        SentenceSearcher searcher("apple");

        // Позитивный тест: слово "apple" содержится в предложении
        assert(searcher.containsWord("I have an apple."));
        
        // Позитивный тест: слово "apple" содержится в предложении независимо от регистра
        assert(searcher.containsWord("APPLE is a fruit."));

        // Негативный тест: слово "apple" не содержится в предложении
        assert(!searcher.containsWord("Banana is yellow."));

        std::cout << "testContainsWord passed." << std::endl;
    }

    static void testSearchSentences() {
        SentenceSearcher searcher("cat");

        // Позитивный тест: предложение содержит слово "cat"
        std::ifstream testFile("test_file.txt");
        if (testFile.is_open()) {
            std::streambuf* originalCout = std::cout.rdbuf();
            std::ostringstream capturedOutput;
            std::cout.rdbuf(capturedOutput.rdbuf());

            searcher.searchSentences("test_file.txt");

            std::cout.rdbuf(originalCout);
            testFile.close();

            assert(capturedOutput.str() == "The cat is sleeping.\n");
            std::cout << "testSearchSentences passed." << std::endl;
        } else {
            std::cerr << "Failed to open test file for testSearchSentences." << std::endl;
        }
    }
};
