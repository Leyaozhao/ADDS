#include "Autocomplete.h"
#include <iostream>

int main() {
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
