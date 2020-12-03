//
// Created by danil on 20.11.2020.
//

#include "Player.h"

Player::Player(sf::Texture& t) {
    score = 0;
    intimidation = false;
    direction_ = Down;
    health = 1;
    //currentFrame = 0;
    sprite.setTexture(t);
    rect.width = 20;
    rect.height = 20;
    rect.left = 20;
    rect.top = 20;
    speed = 20;
    //sprite.scale(1.8, 1.8);
    sprite.setTextureRect(sf::IntRect(rect.width,0,rect.width,rect.height));//Вырезаем спрайт
}

Point Player::getPlayerPoint() {
    return currentPoint;
}

void Player::goUp() {
    currentPoint.y--;
}

void Player::goDown() {
    currentPoint.y++;
}

void Player::goLeft() {
    currentPoint.x--;
}

void  Player::goRight() {
    currentPoint.x++;
}

void Player::increaseScore(int value) {
     score += value;
}

int Player::getScore() {
    return score;
}

void Player::setIntimidation(bool flag) {
    intimidation = flag;
}

bool Player::isIntimidation() {
    return intimidation;
}

void Player::setDirection(Direction direction) {
    direction_ = direction;
}

Direction Player::getDirection() {
    return direction_;
}

std::string Player::getColorConsoleTemplate(Map& map) {
    std::string colorTemplate = "\x1b[33m";
    colorTemplate.push_back(map.getMap()[this->getPlayerPoint().y][this->getPlayerPoint().x]);
    colorTemplate += "\x1b[0m";
    return colorTemplate;
}

char Player::getHealth() {
    return health;
}

void Player::decreaseHealth() {
     health--;
}

Point Player::getStartPoint() {
    return {START_X_POS,START_Y_POS};
}

void Player::setPlayerPoint(Point& point) {
    currentPoint = point;
}

sf::Vector2i Player::getPosInWindow() {
    return {currentPoint.x * rect.width, currentPoint.y* rect.height};
}

sf::Sprite Player::getSprite() {
    return sprite;
}

sf::IntRect Player::getRect() {
    return rect;
}

void Player::setSprite(sf::Vector2i& pos) {
     sprite.setPosition(pos.x,pos.y);
}

