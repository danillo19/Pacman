//
// Created by danil on 27.11.2020.
//

#ifndef PACMAN_BLUEMONSTER_H
#define PACMAN_BLUEMONSTER_H

#include "Monster.h"

#include "RedMonster.h"
const int START_BLUE_X_POS = 14;
const int START_BLUE_Y_POS = 13;
class BlueMonster: public Monster::Monster {
public:
    explicit BlueMonster(sf::Texture& texture);
    Point getChasedTarget(Player& player,Point red) override;
    Point findValidTargetPoint(Player& player, int differenceX, int differenceY);
};


#endif //PACMAN_BLUEMONSTER_H
