#ifndef SENTENCE_SEARCHER_H
#define SENTENCE_SEARCHER_H

#include <string>

class SentenceSearcher {
private:
    std::string targetWord;

    bool isSentenceEnd(char c);

public:
    SentenceSearcher(const std::string& word);

    void searchSentences(const std::string& filename);

    bool containsWord(const std::string& sentence);
};

#endif // SENTENCE_SEARCHER_H
