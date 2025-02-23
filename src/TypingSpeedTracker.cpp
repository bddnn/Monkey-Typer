#include "TypingSpeedTracker.h"

TypingSpeedTracker::TypingSpeedTracker() 
    : characterCount(0), startTime(std::chrono::steady_clock::now()) {}

void TypingSpeedTracker::start() {
    startTime = std::chrono::steady_clock::now();
    characterCount = 0;
}

void TypingSpeedTracker::addTypedCharacters(const std::string& word) {
    characterCount += word.size();
}

double TypingSpeedTracker::calculateCPM() const {
    auto endTime = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsedSeconds = endTime - startTime;
    double minutes = elapsedSeconds.count() / 60.0;

    if (minutes == 0) return 0;
    return characterCount / minutes;
}
