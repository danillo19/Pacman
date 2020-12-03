//
// Created by danil on 27.11.2020.
//

#include "OrangeMonster.h"
using namespace Monster;

OrangeMonster::OrangeMonster(sf::Texture& texture) {
    startPoint = {START_ORANGE_X_POS, START_ORANGE_y_POS};
    currentPoint = startPoint;
    recessionPoint.x = 29;
    recessionPoint.y = 30;
    sprite = 'O';
    IndexColor = "32";
    closedMapItem = 'x';
    active = false;
    windowSprite.setTexture(texture);
    windowSprite.setTextureRect(sf::IntRect(0,141,20,20));
    currentFrame = 0;
    topOnTexture = 140;
}

Point OrangeMonster::getChasedTarget(Player &player, Point red) {
    double distanceToPlayer = calcDistance(player.getPlayerPoint(), getMonsterPos());
    if(distanceToPlayer >= MAX_DISTANCE_TO_PACMAN) return player.getPlayerPoint();
    else return recessionPoint;
}
