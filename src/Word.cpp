#include "Word.h"

Word::Word(const std::string& word, const sf::Font& font, const float x, const float y, const float speed, const int size)
    : speed(speed) {
    text.setFont(font);
    text.setString(word);
    text.setCharacterSize(size);
    text.setFillColor(sf::Color::White);
    text.setPosition(x, y);
}

void Word::update(const float deltaTime) {
    text.move(speed * deltaTime, 0.f);
}

bool Word::isOutOfScreen(const float windowWidth) const {
    return text.getPosition().x > windowWidth;
}

void Word::checkPositionAndUpdateColor(const float windowWidth) {
    if (text.getPosition().x > windowWidth * 0.75f) {
        text.setFillColor(sf::Color::Red);
    } else {
        text.setFillColor(sf::Color::White);
    }
}
