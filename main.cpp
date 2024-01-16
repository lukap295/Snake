#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include "MainMenu.hpp"
#include "Game.hpp"
#include "Snake.hpp"
#include "Food.hpp"
#include "GameOver.hpp"
#include <ctime>

enum class GameState { MainMenu, Game, GameOver };

enum class Dir { Up, Down, Left, Right, None };

enum class Key { Up, Down };

int main() {
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(800, 600), "Zmija");
    window.setFramerateLimit(60);
    sf::Texture texture;
    sf::Font font;
    sf::Text text;

    texture.loadFromFile("assets/grass.png");
    font.loadFromFile("assets/Salsa-Regular.ttf");
    MainMenu menu(font, "Zmija");
    GameOver over(font, "Game Over?");
    Game game;
    Snake snake;
    Food food;
    snake.drawSnake();
    game.textures();
    menu.startSetColor(sf::Color::Yellow);
    GameState state = GameState::MainMenu;
    Dir dirstate;
    Key keystate;
    texture.setRepeated(true);
    game.grass.setTexture(texture);
    game.grass.setTextureRect(sf::IntRect(0, 0, 800, 600));
    dirstate = Dir::None;
    int score = 0;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        switch (state) {
        case GameState::MainMenu:
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                menu.startSetColor(sf::Color::Yellow);
                menu.exitSetColor(sf::Color::White);
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                    state = GameState::Game;
                    break;
                }
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                menu.startSetColor(sf::Color::White);
                menu.exitSetColor(sf::Color::Yellow);
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
                    window.close();
            }
            
        }
        case GameState::Game:
        {
            if (state == GameState::Game) {
                if (dirstate != Dir::Down && sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                    snake.pos = sf::Vector2f(0, -7);
                    dirstate = Dir::Up;
                }
                else if (dirstate != Dir::Up && sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                    snake.pos = sf::Vector2f(0, 7);
                    dirstate = Dir::Down;
                }
                else if (dirstate != Dir::Right && sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                    snake.pos = sf::Vector2f(-7, 0);
                    dirstate = Dir::Left;
                }
                else if (dirstate != Dir::Left && sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                    snake.pos = sf::Vector2f(7, 0);
                    dirstate = Dir::Right;
                }
            }
            //Sudar sa zidom
            if (snake.head.getPosition().x < 20.f) {
                state = GameState::GameOver;
                break;
            }
            if (snake.head.getPosition().y < 20.f) {
                state = GameState::GameOver;
                break;
            }
            if (snake.head.getPosition().x > 755) {
                state = GameState::GameOver;
                break;
            }
            if (snake.head.getPosition().y > 555.f) {
                state = GameState::GameOver;
                break;
            }
            for (auto& bodyPart : snake.body) {
                if (snake.head.getGlobalBounds() == bodyPart.getGlobalBounds()) {
                    snake.body.clear();
                    state = GameState::GameOver;
                    
                }
            }
        }
        case GameState::GameOver:
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                over.retrySetColor(sf::Color::Yellow);
                over.exitSetColor(sf::Color::White);
                if(state == GameState::GameOver)
                    snake.head.setPosition(400, 300);
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                    state = GameState::Game;
                    break;
                }
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                over.retrySetColor(sf::Color::White);
                over.exitSetColor(sf::Color::Yellow);
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
                    window.close();
            }
        }
        //snake.grow(food);
        snake.move(food);
        
        window.clear();
        
    }
        switch (state) {
        case GameState::MainMenu:
            window.draw(menu);
            break;
        case GameState::Game:
            window.draw(game);
            window.draw(food);
            window.draw(snake);
            break;
        case GameState::GameOver:
            window.draw(over);
            break;
        }
        window.display();
    }
    return 0;
}