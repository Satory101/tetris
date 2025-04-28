#pragma once
#ifndef MAP_H
#define MAP_H

#include <vector>
#include "Figure.h"
#include "Utils.h"
class Map {
private:
    std::vector<std::vector<int>> vec;
    int _width;
    int _height;
    const int BORDER = 1;
    const int EMPTY = 0;
    const int BLOCK = 2;
    const int BLOCKS_IN_LINE = 10;
    const int SLEEP_ANIM_DEL_LINES = 50;

public:
    void init(int width, int height);
    void show();
    void animDeleteLines(const std::vector<int> lines);
    int deleteLines(int width);
    bool isCollision(Figure& fig);
    void fixed(Figure& fig);
};

#endif