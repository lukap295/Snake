// Snake.cpp
#include "Snake.hpp"

Snake::Snake() {
    pos = sf::Vector2f(0, 0);
}

Snake::~Snake() {}

void Snake::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(head);
    for (const auto& part : body) {
        target.draw(part);
    }
}

void Snake::drawSnake() {
    head.setSize(sf::Vector2f(36, 36));
    head.setFillColor(sf::Color::Black);
    head.setPosition(400, 300);
}

void Snake::move(Food& food){
    //Poèinje od repa i svaki dio tijela prati dio koji je isprid
    for (int i = body.size() - 1; i > 0; --i) {
        body[i].setPosition(body[i - 1].getPosition());
    }

    if (!body.empty()) {
        body[0].setPosition(head.getPosition());
    }
    grow(food);
    head.move(pos);
    
}

void Snake::grow(Food& food) {
    if (head.getGlobalBounds().intersects(food.food.getGlobalBounds())) {
        sf::RectangleShape newBodyPart;
        newBodyPart.setSize(sf::Vector2f(36, 36));
        newBodyPart.setFillColor(sf::Color::Black);

        if (body.empty()) {
            newBodyPart.setPosition(head.getPosition());
        }
        else {
            newBodyPart.setPosition(body.back().getPosition().x, body.back().getPosition().y);
            cout << body.back().getPosition().x - head.getPosition().x << endl;
        }
        body.push_back(newBodyPart);
        food.food.setPosition(20 + rand() % 700, 20 + rand() % 500);
    }
}
