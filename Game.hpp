#ifndef GAME_HPP
#define GAME_HPP
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

class Game : public sf::Drawable{
public:
	sf::Sprite grass;
	sf::Sprite wall;
	sf::Sprite wall2;
	sf::Sprite wall3;
	sf::Sprite wall4;
	Game();
	~Game();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void textures();
};

#endif