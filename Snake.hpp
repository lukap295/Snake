#ifndef SNAKE_HPP
#define SNAKE_HPP
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Food.hpp"
using namespace std;

class Snake : public sf::Drawable {
public:
	friend class Food;
	sf::RectangleShape head;
	vector<sf::RectangleShape> body;
	sf::Vector2f pos;
	sf::Vector2f bodyPos;
	Snake();
	~Snake();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void drawSnake();
	void move(Food& food);
	void grow(Food& food);
	
};


#endif