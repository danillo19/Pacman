//
// Created by danil on 20.11.2020.
//

#include "Map.h"
#include "Point.h"

void Map::initMap() {
     arr_.emplace_back("############################");
     arr_.emplace_back("#  ..........##........... #");
     arr_.emplace_back("# #### ##### ## ##### #### #");
     arr_.emplace_back("# #  # #   # ## #   # #  # #");
     arr_.emplace_back("#o#### ##### ## ##### ####o#");
     arr_.emplace_back("#                o        .#");
     arr_.emplace_back("#.#### ## ######## ## ####.#");
     arr_.emplace_back("#.#### ## ######## ## ####.#");
     arr_.emplace_back("#.     ##    ##    ##     .#");
     arr_.emplace_back("#.#### ##### ## ##### ####.#");
     arr_.emplace_back("#.#  # ##### ## ##### #  #.#");
     arr_.emplace_back("#.#  # ##          ## #  #.#");
     arr_.emplace_back("#.#  # ## ##----## ## #  #.#");
     arr_.emplace_back("#.#### ## ##xxxx## ## ####.#");
     arr_.emplace_back("#.        ########    .....#");
     arr_.emplace_back("#.#### ##          ## ####.#");
     arr_.emplace_back("#.#  # ## ######## ## #  #.#");
     arr_.emplace_back("#.#  # ##          ## #  #.#");
     arr_.emplace_back("#.#  # ## ######## ## #  #.#");
     arr_.emplace_back("#.#### ## ######## ## ####.#");
     arr_.emplace_back("#.           ##           .#");
     arr_.emplace_back("#.#### ##### ## ##### ####.#");
     arr_.emplace_back("#.#### ##### ## ##### ####.#");
     arr_.emplace_back("#...##....   ..   ....##...#");
     arr_.emplace_back("###.##.##.########.##.##.###");
     arr_.emplace_back("###.##.##.########.##.##.###");
     arr_.emplace_back("#o.....##....##....##.....o#");
     arr_.emplace_back("#.##########.##.##########.#");
     arr_.emplace_back("# ##########.##.########## #");
     arr_.emplace_back("#           ....           #");
     arr_.emplace_back("############################");

}

void Map::changePoint(int x,int y,char symbol) {
    this->arr_[y][x] = symbol;// Сделать структуру точки и добавить oldPoint and newPoint;
}

std::vector<std::string> Map::getMap() {
    return arr_;
}

char Map::getMapElem(int x, int y) {
    return arr_[y][x];
}

