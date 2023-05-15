#ifndef PREFIXMATCHER_H
#define PREFIXMATCHER_H

#include <vector>
#include <string>

class PrefixMatcher {
public:
    void insert(std::string address, int routerNumber);
    int selectRouter(std::string networkAddress);

private:
    struct TrieNode {
        std::vector<int> routerNumbers;
        std::vector<TrieNode*> children;
        TrieNode() : routerNumbers(), children(256, nullptr) {}
    };

    TrieNode* root = nullptr;

    void insertHelper(std::string address, int routerNumber, TrieNode* node);
};

#endif
