#include "BinaryTree.h"
#include "DictionaryTest.cpp"

int main() {
    BinaryTree<std::string, std::string> dictionary;

    fillDictionaryFromFile(dictionary, "dictionary.txt");

    int choice;
    std::string word;
    std::string translation;

    do {
        std::cout << "Menu:\n";
        std::cout << "1. Add Word\n";
        std::cout << "2. Get Translation\n";
        std::cout << "3. Display Dictionary\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter English word: ";
                std::cin >> word;
                std::cout << "Enter Russian translation: ";
                std::cin >> translation;
                dictionary.addWord(word, translation);
                break;
            case 2:
                std::cout << "Enter English word to translate: ";
                std::cin >> word;
                translation = dictionary.getTranslation(word);
                if (!translation.empty()) {
                    std::cout << "Translation: " << translation << std::endl;
                }
                else {
                    std::cout << "Word not found in the dictionary.\n";
                }
                break;
            case 3:
                dictionary.displayDictionary();
                break;
            case 4:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 4);

    DictionaryTest dictionaryTest;
    dictionaryTest.runTests();

    return 0;
}
