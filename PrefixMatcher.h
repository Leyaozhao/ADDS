#ifndef PREFIXMATCHER_H
#define PREFIXMATCHER_H

#include <vector>
#include <string>

// Define PrefixMatcher class
class PrefixMatcher {
public:
    // Inserts a router address
    void addAddress(const std::string& ipAddress, int routerId);
    // Selects a router based on network address
    int chooseRouter(const std::string& networkIp);

private:
    // Define TrieNode structure
    struct TrieNode {
        std::vector<int> routerIds;
        std::vector<TrieNode*> nextNodes;
        TrieNode() : routerIds(), nextNodes(256, nullptr) {}
    };

    TrieNode* rootNode = nullptr;

    // Helper function for inserting a router address
    void insertAddress(const std::string& ipAddress, int routerId, TrieNode* currentNode);
};

#endif