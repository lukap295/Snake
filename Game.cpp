#include "Game.hpp"

Game::Game() {
	
}

Game::~Game() {

}
void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	sf::Texture text, text2;
    target.draw(grass, states);
	target.draw(wall, states);
	target.draw(wall2, states);
	target.draw(wall3, states);
	target.draw(wall4, states);
}

void Game::textures() {
	sf::Texture text, text2;
	text2.loadFromFile("assets/wall.png");
	if (!text2.loadFromFile("assets/wall.png")) {
		cout << "Error loading texture!" << endl;
	}
	wall.setTexture(text2);
	wall.setTextureRect(sf::IntRect(0, 0, 800, 20));
	wall.setColor(sf::Color::Cyan);
	wall2.setTexture(text2);
	wall2.setTextureRect(sf::IntRect(0, 0, 20, 600));
	wall2.setColor(sf::Color::Cyan);
	wall3.setTexture(text2);
	wall3.setTextureRect(sf::IntRect(0, 0, 800, 20));
	wall3.setColor(sf::Color::Cyan);
	wall3.setPosition(0, 580);
	wall4.setTexture(text2);
	wall4.setTextureRect(sf::IntRect(0, 0, 20, 600));
	wall4.setColor(sf::Color::Cyan);
	wall4.setPosition(780, 0);
}