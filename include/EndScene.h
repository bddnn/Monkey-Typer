#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class EndScene {
public:
    EndScene(const sf::Font& kyrouFont, int score);
    bool run(sf::RenderWindow& window);

private:
    sf::Text gameOverText;
    sf::Text scoreText;
    sf::Text promptText;
};