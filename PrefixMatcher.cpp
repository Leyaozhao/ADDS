#include "PrefixMatcher.h"

void PrefixMatcher::addAddress(const std::string& ipAddress, int routerId) {
    if (rootNode == nullptr) {
        rootNode = new TrieNode();
    }
    insertAddress(ipAddress, routerId, rootNode);
}

void PrefixMatcher::insertAddress(const std::string& ipAddress, int routerId, TrieNode* currentNode) {
    for (char character : ipAddress) {
        if (currentNode->nextNodes[character] == nullptr) {
            currentNode->nextNodes[character] = new TrieNode();
        }
        currentNode = currentNode->nextNodes[character];
    }
    currentNode->routerIds.push_back(routerId);
}

int PrefixMatcher::chooseRouter(const std::string& networkIp) {
    TrieNode* currentNode = rootNode;
    int longestMatch = 0;
    int selectedRouter = -1;
    for (char character : networkIp) {
        if (currentNode->nextNodes[character] == nullptr) {
            break;
        }
        currentNode = currentNode->nextNodes[character];
        if (!currentNode->routerIds.empty()) {
            longestMatch = currentNode->routerIds.size();
            selectedRouter = currentNode->routerIds[0];
        }
    }
    return selectedRouter;
}