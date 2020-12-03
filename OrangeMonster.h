//
// Created by danil on 27.11.2020.
//

#ifndef PACMAN_ORANGEMONSTER_H
#define PACMAN_ORANGEMONSTER_H

#include "Monster.h"
const int START_ORANGE_X_POS = 15;
const int START_ORANGE_y_POS = 13;
const int MAX_DISTANCE_TO_PACMAN = 6;


class OrangeMonster: public Monster::Monster {
public:
    explicit OrangeMonster(sf::Texture& texture);
    Point getChasedTarget(Player& player,Point red) override;
};


#endif //PACMAN_ORANGEMONSTER_H
