#include "WordManager.h"

#include <cstdlib>
#include <ctime>

#include "fmt/base.h"

WordManager::WordManager(const sf::Font& font, const std::vector<std::string>& wordList)
    : font(font), wordList(wordList) {
    std::srand(static_cast<unsigned>(std::time(nullptr)));
}

void WordManager::spawnWord(float spawnInterval, float deltaTime, const sf::RenderWindow& window, float wordSpeed) {
    spawnTimer += deltaTime;
    if (spawnTimer >= spawnInterval) {
        spawnTimer = 0.f;
        std::string newWord = wordList[std::rand() % wordList.size()];

        float minY = 0.f;
        float maxY = window.getSize().y - 100.f;

        float startY = minY + static_cast<float>(std::rand() % static_cast<int>(maxY - minY));
        activeWords.emplace_back(newWord, font, -100.f, startY, wordSpeed, 13);
    }
}

void WordManager::updateWords(const float deltaTime, std::string& currentInput, int& score, int& missedWords, const float windowWidth, TypingSpeedTracker& tracker) {
    for (auto it = activeWords.begin(); it != activeWords.end();) {
        it->update(deltaTime);
        it->checkPositionAndUpdateColor(windowWidth);

        if (it->text.getString() == currentInput) {
            score += it->text.getString().getSize();
            tracker.addTypedCharacters(currentInput);
            it = activeWords.erase(it);
            currentInput.clear();
        } else if (it->isOutOfScreen(windowWidth)) {
            missedWords++;
            it = activeWords.erase(it);
        } else {
            ++it;
        }
    }
}


void WordManager::render(sf::RenderWindow& window) const {
    for (const auto& word : activeWords) {
        window.draw(word.text);
    }
}

void WordManager::setSpawnFrequency(float frequency) {
    spawnFrequency = frequency;
}
