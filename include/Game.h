#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <string>
#include <vector>
#include "WindowManager.h"
#include "WordManager.h"
#include "TypingSpeedTracker.h"
#include "Utils.h"
#include "DifficultyScene.h"
#include "StarField.h"

class Game {
public:
    Game();
    void run();

private:
    void render();

    WindowManager windowManager;
    std::vector<std::string> words;
    std::unique_ptr<WordManager> wordManager;
    int score;
    int missedWords;
    int maxMissedWords;
    Difficulty difficulty;
    std::unique_ptr<TypingSpeedTracker> typingSpeedTracker;
    std::vector<Word> activeWords;
    StarField starField;

    sf::Font courbdFont;
    sf::Font kyrouFont;
    sf::Font courFont;
    sf::Text inputText;
    sf::Text scoreText;
    sf::Text missedText;
    sf::Text wpmText;
    sf::Text pauseText;
    std::string currentInput;
    float spawnInterval;
    bool paused;
};
