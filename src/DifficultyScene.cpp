#include "DifficultyScene.h"

DifficultyScene::DifficultyScene(const sf::Font& kyrouFont, const sf::Font& courFont)
    : selectedDifficulty(Difficulty::Easy), selectedIndex(0) {

    title.setFont(kyrouFont);
    title.setString("DIFFICULTY");
    title.setCharacterSize(48);
    title.setFillColor(sf::Color::White);
    title.setPosition(150.f, 100.f);

    easyOption.setFont(courFont);
    easyOption.setString("Easy");
    easyOption.setCharacterSize(15);
    easyOption.setFillColor(sf::Color::White);
    easyOption.setPosition(370.f, 250.f);

    mediumOption.setFont(courFont);
    mediumOption.setString("Normal");
    mediumOption.setCharacterSize(15);
    mediumOption.setFillColor(sf::Color::White);
    mediumOption.setPosition(363.f, 280.f);

    hardOption.setFont(courFont);
    hardOption.setString("Hard");
    hardOption.setCharacterSize(15);
    hardOption.setFillColor(sf::Color::White);
    hardOption.setPosition(370.f, 310.f);

    customOption.setFont(courFont);
    customOption.setString("Custom");
    customOption.setCharacterSize(15);
    customOption.setFillColor(sf::Color::White);
    customOption.setPosition(363.f, 380.f);

    backgroundRect.setSize(sf::Vector2f(350.f, 30.f));
    backgroundRect.setFillColor(sf::Color::White);

    updateSelection();
}

void DifficultyScene::updateSelection() {
    easyOption.setFillColor(sf::Color::White);
    mediumOption.setFillColor(sf::Color::White);
    hardOption.setFillColor(sf::Color::White);
    customOption.setFillColor(sf::Color::White);
    backgroundRect.setFillColor(sf::Color::White);

    if (selectedIndex == 0) {
        easyOption.setFillColor(sf::Color::Black);
        backgroundRect.setPosition(easyOption.getPosition().x - 150.f, easyOption.getPosition().y - 5.f);
    } else if (selectedIndex == 1) {
        mediumOption.setFillColor(sf::Color::Black);
        backgroundRect.setPosition(mediumOption.getPosition().x - 145.f, mediumOption.getPosition().y - 5.f);
    } else if (selectedIndex == 2) {
        hardOption.setFillColor(sf::Color::Black);
        backgroundRect.setPosition(hardOption.getPosition().x - 150.f, hardOption.getPosition().y - 5.f);
    } else if (selectedIndex == 3) {
        customOption.setFillColor(sf::Color::Black);
        backgroundRect.setPosition(customOption.getPosition().x - 140.f, customOption.getPosition().y - 5.f);
    }
}

Difficulty DifficultyScene::run(sf::RenderWindow& window) {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                exit(0);
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Up) {
                    selectedIndex = (selectedIndex - 1 + 4) % 4;
                    updateSelection();
                } else if (event.key.code == sf::Keyboard::Down) {
                    selectedIndex = (selectedIndex + 1) % 4;
                    updateSelection();
                } else if (event.key.code == sf::Keyboard::Enter) {
                    if (selectedIndex == 0) {
                        selectedDifficulty = Difficulty::Easy;
                    } else if (selectedIndex == 1) {
                        selectedDifficulty = Difficulty::Medium;
                    } else if (selectedIndex == 2) {
                        selectedDifficulty = Difficulty::Hard;
                    } else if (selectedIndex == 3) {
                        selectedDifficulty = Difficulty::Custom;
                    }
                    return selectedDifficulty;
                }
            }
        }

        window.clear();
        window.draw(title);
        window.draw(backgroundRect);
        window.draw(easyOption);
        window.draw(mediumOption);
        window.draw(hardOption);
        window.draw(customOption);
        window.display();
    }
    return selectedDifficulty;
}