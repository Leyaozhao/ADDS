#include "PrefixMatcher.h"

void PrefixMatcher::insert(std::string address, int routerNumber) {
    if (!root) {
        root = new TrieNode();
    }
    insertHelper(address, routerNumber, root);
}

void PrefixMatcher::insertHelper(std::string address, int routerNumber, TrieNode* node) {
    for (char c : address) {
        if (!node->children[c]) {
            node->children[c] = new TrieNode();
        }
        node = node->children[c];
    }
    node->routerNumbers.push_back(routerNumber);
}

int PrefixMatcher::selectRouter(std::string networkAddress) {
    TrieNode* node = root;
    int longest = 0;
    int routerNumber = -1;
    for (char c : networkAddress) {
        if (!node->children[c]) {
            break;
        }
        node = node->children[c];
        if (!node->routerNumbers.empty()) {
            longest = node->routerNumbers.size();
            routerNumber = node->routerNumbers[0];
        }
    }
    return routerNumber;
}
