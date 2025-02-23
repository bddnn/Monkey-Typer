#pragma once

#include <SFML/Graphics.hpp>
#include "CustomSettings.h"

class CustomDifficultyScene {
public:
    CustomDifficultyScene(const sf::Font& font);
    CustomSettings run(sf::RenderWindow& window);

private:
    void updateValues();

    sf::Text title;
    sf::Text labels[4];
    sf::Text values[4];
    sf::RectangleShape backgroundRect;
    int selectedIndex;
    int speed;
    int frequency;
    int amount;
    int wordSize;
};