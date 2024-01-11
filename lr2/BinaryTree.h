#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <fstream>
#include <string>

template <typename T>
struct Node {
    T key;
    Node* left;
    Node* right;

    Node(T k) : key(k), left(nullptr), right(nullptr) {}
};

template <typename KeyType, typename ValueType>
class BinaryTree {
private:
    struct Entry {
        KeyType key;
        ValueType value;

        Entry(KeyType k, ValueType v) : key(k), value(v) {}
    };

    Node<Entry>* root;

    Node<Entry>* insert(Node<Entry>* node, KeyType key, ValueType value);

    ValueType search(Node<Entry>* node, KeyType key);

    void traverse(Node<Entry>* node);

    void destroy(Node<Entry>* node);

public:
    BinaryTree();

    void addWord(KeyType key, ValueType value);

    ValueType getTranslation(KeyType key);

    void displayDictionary();

    ~BinaryTree();
};

// Function template definition moved to the header
template <typename KeyType, typename ValueType>
void fillDictionaryFromFile(BinaryTree<KeyType, ValueType>& dictionary, const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    KeyType key;
    ValueType value;
    while (file >> key >> value) {
        dictionary.addWord(key, value);
    }

    file.close();
}

#endif // BINARYTREE_H
