#pragma once
#include <vector>
#include <string>

class Utils {
public:
    static auto loadWords(const std::string& filename) -> std::vector<std::string>;
};
