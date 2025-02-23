#pragma once

#include <SFML/Graphics.hpp>

class Star {
public:
    Star(float x, float y, float speed);
    void update(float deltaTime);
    void render(sf::RenderWindow& window);

private:
    sf::CircleShape shape;
    float speed;
};