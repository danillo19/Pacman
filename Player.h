//
// Created by danil on 20.11.2020.
//

#ifndef PACMAN_PLAYER_H
#define PACMAN_PLAYER_H

#include "SFML/Graphics.hpp"
#include "Point.h"
#include <string>
#include "Map.h"
const int START_X_POS  = 13;
const int START_Y_POS = 5;

enum Direction {
    Left,
    Up,
    Right,
    Down
};

class Player {
private:
    Point currentPoint;
    int score;
    bool intimidation;
    Direction direction_;
    char health;
    sf::IntRect rect;
    int speed;
public:

    sf::Sprite sprite;
    Player(sf::Texture& t);
    void setPlayerPoint(Point& point);
    Point getPlayerPoint();
    int getScore();
    sf::Sprite getSprite();
    sf::IntRect getRect();
    void setSprite(sf::Vector2i& pos);
    void setDirection(Direction direction);
    Direction getDirection();
    void setIntimidation(bool flag);
    bool isIntimidation();
    void increaseScore(int value);
    void goUp();
    void goDown();
    void goLeft();
    void goRight();
    std::string getColorConsoleTemplate(Map& map);
    char getHealth();
    void decreaseHealth();
    Point getStartPoint();
    sf::Vector2i getPosInWindow();

};


#endif //PACMAN_PLAYER_H
