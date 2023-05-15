#ifndef PREFIX_MATCHER_H
#define PREFIX_MATCHER_H

#include <string>

class Node {
public:
    int routerId;
    Node* branch[2];

    Node();
    ~Node();
};

class PrefixMatcher {
private:
    Node* rootNode;

public:
    PrefixMatcher();
    ~PrefixMatcher();

    void insert(const std::string& address, int routerId);
    int selectRouter(const std::string& networkAddress);
};

#endif  // PREFIX_MATCHER_H
