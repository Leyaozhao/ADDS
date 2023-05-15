#ifndef AUTOCOMPLETE_H
#define AUTOCOMPLETE_H

#include <vector>
#include <string>
#include <unordered_map>

class TrieNode {
public:
    bool is_word;
    std::unordered_map<char, TrieNode*> children;
    TrieNode() : is_word(false) {}
};

class Autocomplete {
public:
    Autocomplete();
    void insert(std::string word);
    std::vector<std::string> getSuggestions(std::string partialWord);
    
private:
    TrieNode* root;
    void findWords(TrieNode* node, std::string word, std::vector<std::string>& res);
};

#endif
