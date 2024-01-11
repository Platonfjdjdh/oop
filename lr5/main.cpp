#include <iostream>
#include "SentenceSearcher.h"
#include "SentenceSearcherTest.cpp"

int main() {
    setlocale(LC_ALL, "rus");
    std::cout << "������� ����� ��� ������ � ������������: ";
    std::string targetWord;
    std::cin >> targetWord;

   SentenceSearcher searcher(targetWord);
    searcher.searchSentences("input.txt");

    SentenceSearcherTest::runTests();
    return 0;
}
