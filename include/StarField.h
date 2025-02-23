#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Star.h"

class StarField {
public:
    StarField( int count, float speed);
    void update(float deltaTime);
    void render(sf::RenderWindow& window);

private:
    std::vector<Star> stars;
};