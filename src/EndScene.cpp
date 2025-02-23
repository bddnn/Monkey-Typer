#include "EndScene.h"

EndScene::EndScene(const sf::Font& kyrouFont, int score) {
    gameOverText.setFont(kyrouFont);
    gameOverText.setCharacterSize(50);
    gameOverText.setFillColor(sf::Color::White);
    gameOverText.setString("Game Over");
    gameOverText.setPosition(200.f, 150.f);

    scoreText.setFont(kyrouFont);
    scoreText.setCharacterSize(20);
    scoreText.setFillColor(sf::Color::Green);
    scoreText.setString("Score: " + std::to_string(score));
    scoreText.setPosition(330.f, 250.f);

    promptText.setFont(kyrouFont);
    promptText.setCharacterSize(10);
    promptText.setFillColor(sf::Color::White);
    promptText.setString("<Press Enter to return to difficulty selection>");
    promptText.setPosition(220.f, 420.f);
}

bool EndScene::run(sf::RenderWindow& window) {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
                return true;
            }
        }

        window.clear();
        window.draw(gameOverText);
        window.draw(scoreText);
        window.draw(promptText);
        window.display();
    }
    return false;
}