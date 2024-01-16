#include <SFML/Graphics.hpp>
#include <string>
#include "GameOver.hpp"


GameOver::GameOver(sf::Font& font, const std::string& title) {
    overTitle.setFont(font);
    overTitle.setString(title);
    overTitle.setPosition(200, 40);
    overTitle.scale(sf::Vector2f(3, 3));
    overTitle.setFillColor(sf::Color::Green);

    retry.setFont(font);
    retry.setString("Retry");
    retry.setPosition(300, 300);
    retry.setFillColor(sf::Color::Yellow);

    exit.setFont(font);
    exit.setString("Exit Game");
    exit.setPosition(300, 350);
}

GameOver::~GameOver() {

}

void GameOver::retrySetColor(sf::Color color) {
    retry.setFillColor(color);
}

void GameOver::exitSetColor(sf::Color color) {
    exit.setFillColor(color);
}

void GameOver::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(overTitle, states);
    target.draw(retry, states);
    target.draw(exit, states);
}