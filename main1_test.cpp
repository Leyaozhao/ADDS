#include "Autocomplete.h"
#include <iostream>

int main() {
    Autocomplete autocomplete;
    
    // Insert words into the Autocomplete system
    autocomplete.insert("apple");
    autocomplete.insert("banana");
    autocomplete.insert("apricot");
    autocomplete.insert("grape");
    autocomplete.insert("grapefruit");
    autocomplete.insert("mango");

    // Get suggestions
    std::string testWord = "ap";
    std::vector<std::string> suggestions = autocomplete.getSuggestions(testWord);

    // Print out the suggestions
    std::cout << "Suggestions for \"" << testWord << "\":\n";
    for (const std::string& word : suggestions) {
        std::cout << word << std::endl;
    }

    return 0;
}
