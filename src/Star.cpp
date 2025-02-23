#include "Star.h"

Star::Star(float x, float y, float speed)
    : speed(speed) {
    shape.setRadius(1.f);
    shape.setFillColor(sf::Color::White);
    shape.setPosition(x, y);
}

void Star::update(float deltaTime) {
    shape.move(-speed * deltaTime, 0.f);
    if (shape.getPosition().x < 0) {
        shape.setPosition(800.f, shape.getPosition().y);
    }
}

void Star::render(sf::RenderWindow& window) {
    window.draw(shape);
}