#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include "Word.h"
#include "Utils.h"

class WindowManager {
public:
    WindowManager(const std::string& title, int width, int height, int framerate);

    bool isOpen() const;
    void pollEvents(std::string& currentInput, bool& gameRunning);
    void clear();
    void draw(const std::vector<Word>& words, const sf::Text& inputText, const sf::Text& scoreText, const sf::Text& missedText);
    void display();

    sf::Vector2u getWindowSize() const;
    sf::RenderWindow& getWindow();

private:
    sf::RenderWindow window;
};
