#ifndef GAMEOVER_HPP
#define GAMEOVER_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
using namespace std;

class GameOver : public sf::Drawable {
    sf::Text overTitle;
    sf::Text retry;
    sf::Text exit;
public:
    GameOver(sf::Font& font, const string& title);
    ~GameOver();
    void retrySetColor(sf::Color color);
    void exitSetColor(sf::Color color);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif