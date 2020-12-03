//
// Created by danil on 20.11.2020.
//

#ifndef PACMAN_MAP_H
#define PACMAN_MAP_H

#include "Point.h"
#include <vector>
#include <string>
#include <map>

const int MAP_HEIGHT = 31;
const int MAP_WIDTH = 28;

class Map {
private:
    std::vector<std::string> arr_;
public:
    void initMap();
    void changePoint(int x,int y, char symbol);
    std::vector<std::string> getMap();
    char getMapElem(int x, int y);

};


#endif //PACMAN_MAP_H
