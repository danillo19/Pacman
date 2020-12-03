//
// Created by danil on 24.11.2020.
//

#ifndef PACMAN_REDMONSTER_H
#define PACMAN_REDMONSTER_H

#include "Player.h"
#include "Map.h"
#include "Monster.h"

const int START_RED_X_POS = 12;
const int START_RED_Y_POS = 13;

class RedMonster: public Monster::Monster {
public:
    explicit RedMonster(sf::Texture& t);
    Point getChasedTarget(Player& player, Point redPos) override;

};


#endif //PACMAN_REDMONSTER_H
