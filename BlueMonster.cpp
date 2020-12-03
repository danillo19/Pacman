//
// Created by danil on 27.11.2020.
//

#include "BlueMonster.h"

BlueMonster::BlueMonster(sf::Texture& texture) {
    startPoint.x = START_BLUE_X_POS;
    startPoint.y = START_BLUE_Y_POS;
    currentPoint = startPoint;
    recessionPoint.x = 0;
    recessionPoint.y = 30;
    sprite = 'B';
    IndexColor = "36";
    closedMapItem = 'x';
    active = false;
    windowSprite.setTexture(texture);
    windowSprite.setTextureRect(sf::IntRect(0,121,20,20));
    currentFrame = 0;
    topOnTexture = 120;
}

Point BlueMonster::getChasedTarget(Player &player, Point redPos) {
    int differenceX = player.getPlayerPoint().x - redPos.x;
    int differenceY = player.getPlayerPoint().y - redPos.y;
    Point targetPoint;
    switch (player.getDirection()) {
        case Up:
            targetPoint = findValidTargetPoint(player, differenceX, differenceY - 4);
            break;
        case Down:
            targetPoint = findValidTargetPoint(player,differenceX,differenceY + 4);
            break;
        case Left:
            targetPoint = findValidTargetPoint(player,differenceX - 4,differenceY);
            break;
        case Right:
            targetPoint = findValidTargetPoint(player,differenceX + 4,differenceY);
            break;
        default:
            targetPoint = {};
    }
    return targetPoint;
}

Point BlueMonster::findValidTargetPoint(Player &player, int differenceX, int differenceY) {
    Point targetPoint;
    if (player.getPlayerPoint().y + differenceY >= 0) {
        if (player.getPlayerPoint().y + differenceY < MAP_HEIGHT)
            targetPoint.y = player.getPlayerPoint().y + differenceY;
        else targetPoint.y = MAP_HEIGHT - 1;
    } else targetPoint.y = 0;

    if (player.getPlayerPoint().x + differenceX >= 0) {
        if (player.getPlayerPoint().x + differenceX < MAP_WIDTH)
            targetPoint.x = player.getPlayerPoint().x + differenceX;
        else targetPoint.x = MAP_WIDTH - 1;
    } else targetPoint.x = 0;
    return targetPoint;
}


