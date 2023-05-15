#include "Autocomplete.h"

Autocomplete::Autocomplete() {
    root = new TrieNode('\0');
}

void Autocomplete::insert(std::string word) {
    TrieNode* node = root;
    for (char c : word) {
        TrieNode* child = findChild(node, c);
        if (child != nullptr) {
            node = child;
        } else {
            TrieNode* newNode = new TrieNode(c);
            node->children.push_back(newNode);
            node = newNode;
        }
    }
    node->is_word = true;
}

std::vector<std::string> Autocomplete::getSuggestions(std::string partialWord) {
    std::vector<std::string> res;
    TrieNode* node = root;
    for (char c : partialWord) {
        node = findChild(node, c);
        if (node == nullptr) {
            return res;
        }
    }
    findWords(node, partialWord, res);
    return res;
}

void Autocomplete::findWords(TrieNode* node, std::string word, std::vector<std::string>& res) {
    if (node->is_word) {
        res.push_back(word);
    }
    for (auto& child : node->children) {
        findWords(child, word + child->value, res);
    }
}

TrieNode* Autocomplete::findChild(TrieNode* parent, char ch) {
    for (auto& child : parent->children) {
        if (child->value == ch) {
            return child;
        }
    }
    return nullptr;
}
