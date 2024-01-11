#include "BinaryTree.h"

template <typename KeyType, typename ValueType>
Node<typename BinaryTree<KeyType, ValueType>::Entry>* BinaryTree<KeyType, ValueType>::insert(Node<Entry>* node, KeyType key, ValueType value) {
    if (node == nullptr) {
        return new Node<Entry>(Entry(key, value));
    }

    if (key < node->key.key) {
        node->left = insert(node->left, key, value);
    }
    else if (key > node->key.key) {
        node->right = insert(node->right, key, value);
    }

    return node;
}

template <typename KeyType, typename ValueType>
ValueType BinaryTree<KeyType, ValueType>::search(Node<Entry>* node, KeyType key) {
    if (node == nullptr) {
        return ValueType();
    }

    if (key == node->key.key) {
        return node->key.value;
    }
    else if (key < node->key.key) {
        return search(node->left, key);
    }
    else {
        return search(node->right, key);
    }
}

template <typename KeyType, typename ValueType>
void BinaryTree<KeyType, ValueType>::traverse(Node<Entry>* node) {
    if (node != nullptr) {
        traverse(node->left);
        std::cout << node->key.key << " - " << node->key.value << "\n";
        traverse(node->right);
    }
}

template <typename KeyType, typename ValueType>
void BinaryTree<KeyType, ValueType>::destroy(Node<Entry>* node) {
    if (node != nullptr) {
        destroy(node->left);
        destroy(node->right);
        delete node;
    }
}

template <typename KeyType, typename ValueType>
BinaryTree<KeyType, ValueType>::BinaryTree() : root(nullptr) {}

template <typename KeyType, typename ValueType>
void BinaryTree<KeyType, ValueType>::addWord(KeyType key, ValueType value) {
    root = insert(root, key, value);
}

template <typename KeyType, typename ValueType>
ValueType BinaryTree<KeyType, ValueType>::getTranslation(KeyType key) {
    return search(root, key);
}

template <typename KeyType, typename ValueType>
void BinaryTree<KeyType, ValueType>::displayDictionary() {
    std::cout << "Dictionary:\n";
    traverse(root);
    std::cout << std::endl;
}

template <typename KeyType, typename ValueType>
BinaryTree<KeyType, ValueType>::~BinaryTree() {
    destroy(root);
}


template class BinaryTree<std::string, std::string>;

template void fillDictionaryFromFile(BinaryTree<std::string, std::string>& dictionary, const std::string& filename);
