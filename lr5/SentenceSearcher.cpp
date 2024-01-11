#include "SentenceSearcher.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

SentenceSearcher::SentenceSearcher(const std::string& word) : targetWord(word) {}

bool SentenceSearcher::isSentenceEnd(char c) {
    return c == '.' || c == '!' || c == '?';
}

bool SentenceSearcher::containsWord(const std::string& sentence) {
    std::string lowerSentence = sentence;
    std::transform(lowerSentence.begin(), lowerSentence.end(), lowerSentence.begin(), ::tolower);
    return lowerSentence.find(targetWord) != std::string::npos;
}

void SentenceSearcher::searchSentences(const std::string& filename) {
    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        std::cerr << "Не удалось открыть файл." << std::endl;
        return;
    }

    std::ostringstream bufferStream;
    char c;
    while (inputFile.get(c)) {
        bufferStream.put(c);
        if (isSentenceEnd(c)) {
            std::string buffer = bufferStream.str();
            if (containsWord(buffer)) {
                std::cout << buffer << std::endl;
            }
            bufferStream.str("");
        }
    }

    inputFile.close();
}
