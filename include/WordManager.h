#pragma once

#include <vector>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "TypingSpeedTracker.h"
#include "Word.h"

class WordManager {
public:
    WordManager(const sf::Font& font, const std::vector<std::string>& wordList);
    void spawnWord(float spawnInterval, float deltaTime, const sf::RenderWindow& window, float wordSpeed);
    void updateWords(float deltaTime, std::string& currentInput, int& score, int& missedWords, float windowWidth, TypingSpeedTracker& tracker);
    void render(sf::RenderWindow& window) const;
    void setSpawnFrequency(float frequency);

private:
    const sf::Font& font;
    const std::vector<std::string>& wordList;
    std::vector<Word> activeWords;
    float spawnTimer = 0.f;
    float spawnFrequency = 1.f;
};
