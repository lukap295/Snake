#include "Food.hpp"

Food::Food() {
	food.setRadius(8);
	food.setFillColor(sf::Color::Blue);
	food.setPosition(rand() % 780, rand() % 580);
}

Food::~Food() {

}

void Food::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(food);
}
