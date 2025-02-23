#include "Game.h"

#include <iostream>

#include "CustomDifficultyScene.h"
#include "EndScene.h"
#include "TypingSpeedTracker.h"

#include "Game.h"
#include "EndScene.h"

Game::Game()
    : windowManager("Monkey Typer", 800, 500, 60),
      words(Utils::loadWords("./words_English.txt")),
      wordManager(std::make_unique<WordManager>(courbdFont, words)),
      score(0),
      missedWords(0),
      maxMissedWords(5),
      difficulty(Difficulty::Easy),
      typingSpeedTracker(std::make_unique<TypingSpeedTracker>()),
      paused(false),
      starField(60, 50.f) {
    if (!courbdFont.loadFromFile("courbd.ttf")) {
        std::cerr << "Nie można załadować czcionki!\n";
        exit(1);
    }

    if (!kyrouFont.loadFromFile("Kyrou 7 Wide Bold.ttf")) {
        std::cerr << "Nie mozna zaladowac czcionki kyrou\n";
        exit(1);
    }

    if (!courFont.loadFromFile("cour.ttf")) {
        std::cerr << "Nie mozna zaladowac czcionki cour\n";
        exit(1);
    }

    inputText.setFont(courFont);
    inputText.setCharacterSize(15);
    inputText.setFillColor(sf::Color::White);
    inputText.setPosition(40.f, 450.f);

    scoreText.setFont(courFont);
    scoreText.setCharacterSize(15);
    scoreText.setFillColor(sf::Color::Green);
    scoreText.setPosition(40.f, 400.f);

    missedText.setFont(courFont);
    missedText.setCharacterSize(15);
    missedText.setFillColor(sf::Color::Red);
    missedText.setPosition(150.f, 400.f);

    wpmText.setFont(courFont);
    wpmText.setCharacterSize(15);
    wpmText.setFillColor(sf::Color::Blue);
    wpmText.setPosition(170.f, 450.f);

    pauseText.setFont(courFont);
    pauseText.setCharacterSize(30);
    pauseText.setFillColor(sf::Color::Yellow);
    pauseText.setString("Pause");
    pauseText.setPosition(350.f, 200.f);
}

void Game::run() {
    while (windowManager.isOpen()) {
        score = 0;
        missedWords = 0;
        currentInput.clear();
        paused = false;

        DifficultyScene difficultyScene(kyrouFont, courFont);
        difficulty = difficultyScene.run(windowManager.getWindow());

        wordManager = std::make_unique<WordManager>(courbdFont, words);
        typingSpeedTracker->start();

        CustomSettings settings;

        if (difficulty == Difficulty::Custom) {
            CustomDifficultyScene customScene(kyrouFont);
            settings = customScene.run(windowManager.getWindow());
        } else {
            if (difficulty == Difficulty::Easy) {
                settings.speed = 2;
                settings.frequency = 2;
                settings.amount = 10;
            } else if (difficulty == Difficulty::Medium) {
                settings.speed = 5;
                settings.frequency = 5;
                settings.amount = 5;
            } else if (difficulty == Difficulty::Hard) {
                settings.speed = 8;
                settings.frequency = 8;
                settings.amount = 3;
            }
        }

        float spawnInterval = 3.f / settings.frequency;
        maxMissedWords = settings.amount;
        float wordSpeed = 50.f + (settings.speed * 10.f);
        wordManager->setSpawnFrequency(settings.frequency);

        sf::Clock clock;

        while (windowManager.isOpen()) {
            float deltaTime = clock.restart().asSeconds();

            bool gameRunning = missedWords < maxMissedWords;
            windowManager.pollEvents(currentInput, gameRunning);

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                paused = !paused;
                sf::sleep(sf::milliseconds(200));
            }

            if (!paused) {
                starField.update(deltaTime);
                wordManager->spawnWord(spawnInterval, deltaTime, windowManager.getWindow(), wordSpeed);
                wordManager->updateWords(deltaTime, currentInput, score, missedWords, windowManager.getWindowSize().x, *typingSpeedTracker);

                if (missedWords >= maxMissedWords) {
                    EndScene endScene(kyrouFont, score);
                    if (endScene.run(windowManager.getWindow())) {
                        break;
                    } else {
                        windowManager.getWindow().close();
                    }
                }

                inputText.setString("[ " + currentInput + " ]");
                scoreText.setString("Score: " + std::to_string(score));
                missedText.setString("Missed: " + std::to_string(missedWords));
                wpmText.setString("CPM: " + std::to_string(static_cast<int>(typingSpeedTracker->calculateCPM())));
            }

            render();
        }
    }
}

void Game::render() {
    windowManager.clear();
    starField.render(windowManager.getWindow());
    wordManager->render(windowManager.getWindow());
    windowManager.draw(activeWords, inputText, scoreText, missedText);
    windowManager.getWindow().draw(wpmText);
    if (paused) {
        windowManager.getWindow().draw(pauseText);
    }
    windowManager.display();
}