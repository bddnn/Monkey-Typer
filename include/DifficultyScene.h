#pragma once

#include <SFML/Graphics.hpp>
#include <string>

enum class Difficulty { Easy, Medium, Hard, Custom };

class DifficultyScene {
public:
    DifficultyScene(const sf::Font& kyrouFont, const sf::Font& courFont);
    Difficulty run(sf::RenderWindow& window);

private:
    sf::Text title;
    sf::Text easyOption;
    sf::Text mediumOption;
    sf::Text hardOption;
    sf::Text customOption;
    sf::Text instructions;
    sf::RectangleShape backgroundRect;

    Difficulty selectedDifficulty;
    int selectedIndex;

    void updateSelection();
};