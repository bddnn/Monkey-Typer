#include "CustomDifficultyScene.h"

CustomDifficultyScene::CustomDifficultyScene(const sf::Font& font)
    : selectedIndex(0), speed(5), frequency(5), amount(5) {
    title.setFont(font);
    title.setString("CUSTOM DIFFICULTY");
    title.setCharacterSize(35);
    title.setFillColor(sf::Color::White);
    title.setPosition(100.f, 50.f);

    labels[0].setFont(font);
    labels[0].setCharacterSize(15);
    labels[0].setString("Speed");
    labels[0].setPosition(200.f, 150.f);

    labels[1].setFont(font);
    labels[1].setCharacterSize(15);
    labels[1].setString("Frequency");
    labels[1].setPosition(200.f, 200.f);

    labels[2].setFont(font);
    labels[2].setCharacterSize(15);
    labels[2].setString("Amount");
    labels[2].setPosition(200.f, 250.f);

    for (int i = 0; i < 3; ++i) {
        values[i].setFont(font);
        values[i].setCharacterSize(15);
        values[i].setFillColor(sf::Color::White);
        values[i].setPosition(400.f, 150.f + i * 50.f);
    }

    backgroundRect.setSize(sf::Vector2f(550.f, 30.f));
    backgroundRect.setFillColor(sf::Color::White);

    updateValues();
}

void CustomDifficultyScene::updateValues() {
    values[0].setString(std::string(speed, '#'));
    values[1].setString(std::string(frequency, '#'));
    values[2].setString(std::string(amount, '#'));

    for (int i = 0; i < 3; ++i) {
        labels[i].setFillColor(sf::Color::White);
        values[i].setFillColor(sf::Color::White);
    }
    labels[selectedIndex].setFillColor(sf::Color::Black);
    values[selectedIndex].setFillColor(sf::Color::Black);

    backgroundRect.setPosition(labels[selectedIndex].getPosition().x - 150.f, labels[selectedIndex].getPosition().y - 5.f);
}

CustomSettings CustomDifficultyScene::run(sf::RenderWindow& window) {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                exit(0);
            }

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Up) {
                    selectedIndex = (selectedIndex - 1 + 3) % 3;
                } else if (event.key.code == sf::Keyboard::Down) {
                    selectedIndex = (selectedIndex + 1) % 3;
                } else if (event.key.code == sf::Keyboard::Left) {
                    if (selectedIndex == 0 && speed > 0) speed--;
                    if (selectedIndex == 1 && frequency > 0) frequency--;
                    if (selectedIndex == 2 && amount > 0) amount--;
                } else if (event.key.code == sf::Keyboard::Right) {
                    if (selectedIndex == 0 && speed < 10) speed++;
                    if (selectedIndex == 1 && frequency < 10) frequency++;
                    if (selectedIndex == 2 && amount < 10) amount++;
                } else if (event.key.code == sf::Keyboard::Enter) {
                    return {speed, frequency, amount};
                }
                updateValues();
            }
        }

        window.clear();
        window.draw(title);
        window.draw(backgroundRect);
        for (int i = 0; i < 3; ++i) {
            window.draw(labels[i]);
            window.draw(values[i]);
        }
        window.display();
    }

    return {speed, frequency, amount};
}