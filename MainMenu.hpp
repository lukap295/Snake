#ifndef MAINMENU_HPP
#define MAINMENU_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
using namespace std;

class MainMenu : public sf::Drawable {
    sf::Text gameTitle;
    sf::Text start;
    sf::Text exit;
public:
    MainMenu(sf::Font& font, const string& title);
    ~MainMenu();
    void startSetColor(sf::Color color);
    void exitSetColor(sf::Color color);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif
