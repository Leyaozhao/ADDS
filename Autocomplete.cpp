#include "Autocomplete.h"

Autocomplete::Autocomplete() {
    root = new TrieNode();
}

void Autocomplete::insert(std::string word) {
    TrieNode* node = root;
    for (char c : word) {
        if (!node->children.count(c)) {
            node->children[c] = new TrieNode();
        }
        node = node->children[c];
    }
    node->is_word = true;
}

std::vector<std::string> Autocomplete::getSuggestions(std::string partialWord) {
    std::vector<std::string> res;
    TrieNode* node = root;
    for (char c : partialWord) {
        if (!node->children.count(c)) {
            return res;
        }
        node = node->children[c];
    }
    findWords(node, partialWord, res);
    return res;
}

void Autocomplete::findWords(TrieNode* node, std::string word, std::vector<std::string>& res) {
    if (node->is_word) {
        res.push_back(word);
    }
    for (auto& child : node->children) {
        findWords(child.second, word + child.first, res);
    }
}
