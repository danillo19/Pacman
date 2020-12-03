//
// Created by danil on 24.11.2020.
//

#include "RedMonster.h"
#include "Player.h"


RedMonster::RedMonster(sf::Texture& t) {
    startPoint.x = START_RED_X_POS;
    startPoint.y = START_RED_Y_POS;
    currentPoint.x = startPoint.x;
    currentPoint.y = startPoint.y;
    recessionPoint.x = 0;
    recessionPoint.y = 0;
    sprite = 'R';
    IndexColor = "31";
    closedMapItem = 'x';
    active = true;
    windowSprite.setTexture(t);
    windowSprite.setTextureRect(sf::IntRect(0,80,20,20));
    currentFrame = 0;
    topOnTexture = 80;
}

Point RedMonster::getChasedTarget(Player& player, Point redPos) {
    return player.getPlayerPoint();
}
