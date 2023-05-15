#include "PrefixMatcher.h"
#include<Autocomplete.h>
#include <iostream>

int main() {
    PrefixMatcher matcher;

    matcher.insert("1010", 1);
    matcher.insert("1011", 2);
    matcher.insert("1111", 3);

    std::cout << "Router for 10101: " << matcher.selectRouter("10101") << std::endl;
    std::cout << "Router for 10110: " << matcher.selectRouter("10110") << std::endl;
    std::cout << "Router for 11111: " << matcher.selectRouter("11111") << std::endl;


    Autocomplete ac;
    ac.insert("hello");
    ac.insert("hell");
    ac.insert("heaven");
    ac.insert("goodbye");

    std::vector<std::string> suggestions = ac.getSuggestions("he");
    for (std::vector<std::string>::iterator it = suggestions.begin(); it != suggestions.end(); ++it) {
        std::cout << *it << std::endl;
    }

    return 0;
}
