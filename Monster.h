//
// Created by danil on 26.11.2020.
//

#ifndef PACMAN_MONSTER_H
#define PACMAN_MONSTER_H

#include "Point.h"
#include "Map.h"
#include "Player.h"

namespace Monster {
    double calcDistance(Point target, Point point);

    class Monster {
    protected:
        Point startPoint;
        Point recessionPoint;
        Point currentPoint;
        char sprite;
        Point prevPoint;
        std::string IndexColor;
        char closedMapItem;
        bool active;
    public:

        int currentFrame;
        int topOnTexture;
        sf::Sprite windowSprite;
        virtual void move(Point targetPoint, Map map) final;

        void reset();

        Point getMonsterPos();

        char getSprite();

        Point getRecessionPoint();

        Point getPrevPoint();

        void setPrevPoint(Point newPrevPoint);

        virtual Point getChasedTarget(Player &player, Point redPos) {
            return {};
        };

        std::string getIndexColor();


        char getClosedMapItem();

        void setClosedMapItem(Map &map, Point point);

        bool isActive();

        void makeActive();

        sf::Vector2i getPosOnWindow();
        void setWindowSprite(sf::Vector2i& point);
        sf::Sprite getSpriteOnWindow();
    };
}

#endif //PACMAN_MONSTER_H
