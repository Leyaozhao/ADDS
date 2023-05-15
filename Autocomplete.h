#ifndef AUTOCOMPLETE_H
#define AUTOCOMPLETE_H

#include <vector>
#include <string>

struct TrieNode {
    char value;
    bool is_word;
    std::vector<TrieNode*> children;
    TrieNode(char val) : value(val), is_word(false) {}
};

class Autocomplete {
public:
    Autocomplete();
    void insert(std::string word);
    std::vector<std::string> getSuggestions(std::string partialWord);
    
private:
    TrieNode* root;
    void findWords(TrieNode* node, std::string word, std::vector<std::string>& res);
    TrieNode* findChild(TrieNode* parent, char ch);
};

#endif
