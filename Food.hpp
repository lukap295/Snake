#ifndef FOOD_HPP
#define FOOD_HPP
#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
using namespace std;

class Food : public sf::Drawable {
public:
	sf::CircleShape food;
	Food();
	~Food();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif
