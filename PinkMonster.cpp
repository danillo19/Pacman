//
// Created by danil on 26.11.2020.
//

#include "PinkMonster.h"

PinkMonster::PinkMonster(sf::Texture& texture) {
    startPoint.x = START_PINK_X_POS;
    startPoint.y = START_PINK_Y_POS;
    currentPoint = startPoint;
    recessionPoint.x = 30;
    recessionPoint.y = 0;
    sprite = 'P';
    IndexColor = "35";
    closedMapItem = 'x';
    active = false;
    windowSprite.setTexture(texture);
    windowSprite.setTextureRect(sf::IntRect(0,101,20,20));
    currentFrame = 0;
    topOnTexture = 100;
}


Point PinkMonster::getChasedTarget(Player &player, Point redPos) {
    switch (player.getDirection()) {
        case Up:
            if(player.getPlayerPoint().y - TARGET_OFFSET >= 0) return {player.getPlayerPoint().x,player.getPlayerPoint().y - TARGET_OFFSET};
            else return  {player.getPlayerPoint().x, 0};
        case Down:
            if(player.getPlayerPoint().y + TARGET_OFFSET < MAP_HEIGHT) return  {player.getPlayerPoint().x,player.getPlayerPoint().y + TARGET_OFFSET};
            else return  {player.getPlayerPoint().x, MAP_HEIGHT - 1};
        case Left:
            if(player.getPlayerPoint().x - TARGET_OFFSET >= 0) return  {player.getPlayerPoint().x - TARGET_OFFSET,player.getPlayerPoint().y};
            else return  {0,player.getPlayerPoint().y};
        case Right:
            if(player.getPlayerPoint().x + TARGET_OFFSET < MAP_WIDTH) return  {player.getPlayerPoint().x + TARGET_OFFSET,player.getPlayerPoint().y};
            else return {MAP_WIDTH - 1,player.getPlayerPoint().y};
        default:
            return {};
    }

}

