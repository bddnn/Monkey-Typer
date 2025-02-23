#pragma once

#include <SFML/Graphics.hpp>

class Word {
public:
    Word(const std::string& word, const sf::Font& font, float x, float y, float speed, int size);
    void update(float deltaTime);
    bool isOutOfScreen(float windowWidth) const;
    void checkPositionAndUpdateColor(float windowWidth);

    sf::Text text;

private:
    float speed;
};