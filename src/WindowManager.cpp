#include "WindowManager.h"

WindowManager::WindowManager(const std::string& title, int width, int height, int framerate)
    : window(sf::VideoMode(width, height), title) {
    window.setFramerateLimit(framerate);
}

bool WindowManager::isOpen() const {
    return window.isOpen();
}

void WindowManager::pollEvents(std::string& currentInput, bool& gameRunning) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            gameRunning = false;
            window.close();
        }

        if (event.type == sf::Event::TextEntered) {
            if (event.text.unicode == 8) {
                if (!currentInput.empty())
                    currentInput.pop_back();
            } else if (event.text.unicode == 13) {
                currentInput.clear();
            } else if (event.text.unicode < 128) {
                currentInput += static_cast<char>(event.text.unicode);
            }
        }
    }
}

void WindowManager::clear() {
    window.clear();
}

void WindowManager::draw(const std::vector<Word>& words, const sf::Text& inputText, const sf::Text& scoreText, const sf::Text& missedText) {
    for (const auto& word : words) {
        window.draw(word.text);
    }
    window.draw(inputText);
    window.draw(scoreText);
    window.draw(missedText);
}

void WindowManager::display() {
    window.display();
}

sf::Vector2u WindowManager::getWindowSize() const {
    return window.getSize();
}

sf::RenderWindow& WindowManager::getWindow() {
    return window;
}
