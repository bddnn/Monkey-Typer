#pragma once

#include <chrono>
#include <string>

class TypingSpeedTracker {
    int characterCount;
    std::chrono::time_point<std::chrono::steady_clock> startTime;

public:
    TypingSpeedTracker();

    void start();
    void addTypedCharacters(const std::string& word);
    double calculateCPM() const;
};

