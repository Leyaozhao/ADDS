#include "PrefixMatcher.h"

Node::Node() {
    routerId = -1;
    branch[0] = nullptr;
    branch[1] = nullptr;
}

Node::~Node() {
    delete branch[0];
    delete branch[1];
}

PrefixMatcher::PrefixMatcher() {
    rootNode = new Node();
}

PrefixMatcher::~PrefixMatcher() {
    delete rootNode;
}

void PrefixMatcher::insertAddress(const std::string& address, int routerId) {
    Node* current = rootNode;
    for (std::string::const_iterator it = address.begin(); it != address.end(); ++it) {
        int index = *it - '0';
        if (current->branch[index] == nullptr) {
            current->branch[index] = new Node();
        }
        current = current->branch[index];
    }
    current->routerId = routerId;
}

int PrefixMatcher::findRouter(const std::string& networkAddress) {
    Node* current = rootNode;
    int lastRouterId = -1;
    for (std::string::const_iterator it = networkAddress.begin(); it != networkAddress.end(); ++it) {
        int index = *it - '0';
        if (current->branch[index] == nullptr) {
            break;
        }
        current = current->branch[index];
        if (current->routerId != -1) {
            lastRouterId = current->routerId;
        }
    }
    return lastRouterId;
}
