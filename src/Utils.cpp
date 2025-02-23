#include "Utils.h"
#include <fstream>
#include <iostream>
#include <vector>

std::vector<std::string> Utils::loadWords(const std::string& filename) {
    std::vector<std::string> words;
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Nie można otworzyć pliku: " << filename << std::endl;
        return words;
    }

    std::string word;
    while (file >> word) {
        words.push_back(word);
    }
    file.close();
    return words;
}
