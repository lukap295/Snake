#include <SFML/Graphics.hpp>
#include <string>
#include "MainMenu.hpp"


MainMenu::MainMenu(sf::Font& font, const std::string& title) {
    gameTitle.setFont(font);
    gameTitle.setString(title);
    gameTitle.setPosition(275, 40);
    gameTitle.scale(sf::Vector2f(3, 3));
    gameTitle.setFillColor(sf::Color::Green);

    start.setFont(font);
    start.setString("Start Game");
    start.setPosition(300, 300);
    start.setFillColor(sf::Color::Yellow);

    exit.setFont(font);
    exit.setString("Exit Game");
    exit.setPosition(300, 350);
}

MainMenu::~MainMenu() {

}

void MainMenu::startSetColor(sf::Color color) {
    start.setFillColor(color);
}

void MainMenu::exitSetColor(sf::Color color) {
    exit.setFillColor(color);
}

void MainMenu::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(gameTitle, states);
    target.draw(start, states);
    target.draw(exit, states);
}