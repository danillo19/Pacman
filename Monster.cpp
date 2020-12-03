//
// Created by danil on 26.11.2020.
//

#include "Monster.h"

#include <cmath>

double Monster::calcDistance(Point target, Point point) {
    double x_squared = (target.x - point.x) * (target.x - point.x);
    double y_squared = (target.y - point.y) * (target.y - point.y);
    double distance = sqrt(x_squared + y_squared);
    return distance;
}

void Monster::Monster::move(Point targetPoint, Map map) {
    std::map<double, Point> distances;
    Point nextPoint;
    // right
    if(closedMapItem == 'x') { // Выход из домика
        currentPoint.y -= 2;
        return;
    }
    if ((map.getMapElem(this->currentPoint.x + 1, this->currentPoint.y) != '#') &&
        (map.getMapElem(currentPoint.x + 1, currentPoint.y) != 'x') && (this->currentPoint.x + 1 != getPrevPoint().x) &&
            (map.getMapElem(currentPoint.x + 1,currentPoint.y) != '-')) {
        nextPoint.x = this->currentPoint.x + 1;
        nextPoint.y = this->currentPoint.y;

        double distance = calcDistance(targetPoint, nextPoint);
        distances[distance] = nextPoint;
    }
    // down
    if ((map.getMapElem(this->currentPoint.x, this->currentPoint.y + 1) != '#') &&
         (map.getMapElem(currentPoint.x, currentPoint.y + 1) != 'x') && (this->currentPoint.y + 1 != getPrevPoint().y) &&
         (map.getMapElem(currentPoint.x,currentPoint.y + 1) != '-')) {
        nextPoint.x = this->currentPoint.x;
        nextPoint.y = this->currentPoint.y + 1;
        double distance = calcDistance(targetPoint, nextPoint);
        distances[distance] = nextPoint;

    }
    // left
    if ((map.getMapElem(this->currentPoint.x - 1, this->currentPoint.y) != '#') &&
         (map.getMapElem(currentPoint.x - 1, currentPoint.y) != 'x') && (this->currentPoint.x - 1 != getPrevPoint().x) &&
         (map.getMapElem(currentPoint.x - 1,currentPoint.y) != '-'))  {
        nextPoint.x = this->currentPoint.x - 1;
        nextPoint.y = this->currentPoint.y;

        double distance = calcDistance(targetPoint, nextPoint);
        distances[distance] = nextPoint;
    }
    //  up
    if ((map.getMapElem(this->currentPoint.x, this->currentPoint.y - 1) != '#') &&
         (map.getMapElem(currentPoint.x, currentPoint.y - 1) != 'x') && (this->currentPoint.y - 1 != getPrevPoint().y) &&
         (map.getMapElem(currentPoint.x,currentPoint.y - 1) != '-')) {
        nextPoint.x = this->currentPoint.x;
        nextPoint.y = this->currentPoint.y - 1;
        double distance = calcDistance(targetPoint, nextPoint);
        distances[distance] = nextPoint;
    }
    setPrevPoint(this->currentPoint);
    this->currentPoint = distances.begin()->second;
}

Point Monster::Monster::getMonsterPos() {
    return currentPoint;
}

Point Monster::Monster::getRecessionPoint() {
    return recessionPoint;
}

char Monster::Monster::getSprite() {
    return sprite;
}

void Monster::Monster::reset() {
    currentPoint = startPoint;
    prevPoint = {};
    closedMapItem = 'x';
    windowSprite.setPosition(currentPoint.x*20,currentPoint.y*20);
}

void Monster::Monster::setPrevPoint(Point newPrevPoint) {
    prevPoint = newPrevPoint;
}

Point Monster::Monster::getPrevPoint() {
    return prevPoint;
}


std::string Monster::Monster::getIndexColor() {
    return IndexColor;
}

char Monster::Monster::getClosedMapItem() {
    return closedMapItem;
}

void Monster::Monster::setClosedMapItem(Map &map, Point point) {
    if (map.getMapElem(point.x, point.y) != ' ' && map.getMapElem(point.x, point.y) != '.' &&
        map.getMapElem(point.x, point.y) != 'o' && map.getMapElem(point.x, point.y) != '-'
            ) {
        closedMapItem = ' ';
    } else closedMapItem = map.getMapElem(point.x, point.y);
}

bool Monster::Monster::isActive() {
    return active;
}

void Monster::Monster::makeActive() {
    active = true;
}

sf::Vector2i Monster::Monster::getPosOnWindow() {
    return {currentPoint.x*20,currentPoint.y*20};
}

void Monster::Monster::setWindowSprite(sf::Vector2i& point) {
    windowSprite.setPosition(point.x,point.y);
}

sf::Sprite Monster::Monster::getSpriteOnWindow() {
    return windowSprite;
}
