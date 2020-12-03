//
// Created by danil on 26.11.2020.

#ifndef PACMAN_PINKMONSTER_H
#define PACMAN_PINKMONSTER_H

#include "Map.h"
#include "Player.h"
#include "Monster.h"


const int START_PINK_X_POS = 13;
const int START_PINK_Y_POS = 13;
const int TARGET_OFFSET = 2;

class PinkMonster: public Monster::Monster {

public:
    explicit PinkMonster(sf::Texture& texture);
    Point getChasedTarget(Player& player, Point redPos) override;
};



#endif //PACMAN_PINKMONSTER_H
