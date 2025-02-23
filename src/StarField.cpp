#include "StarField.h"

StarField::StarField( int count, float speed) {
    for ( int i = 0; i < count; ++i) {
        float x = static_cast<float>(rand() % 800);
        float y = static_cast<float>(rand() % 500);
        stars.emplace_back(x, y, speed);
    }
}

void StarField::update(float deltaTime) {
    for (auto& star : stars) {
        star.update(deltaTime);
    }
}

void StarField::render(sf::RenderWindow& window) {
    for (auto& star : stars) {
        star.render(window);
    }
}