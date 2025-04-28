#ifndef FIGURE_H
#define FIGURE_H

#include <vector>
#include "Utils.h"

struct Point {
    int x;
    int y;
};

class Figure {
private:
    std::vector<Point> vec;
    int countTact = 0;
    const int tick_rate = 5;
public:
    int GetX(int i);
    int GetY(int i);
    int GetVecSize();
    void push(int x, int y);
    void show();
    void hide();
    void moveDown();
    void moveUp();
    void moveLeft();
    void moveRight();
    bool allowMove();
    void spawn();
    void rotateR();
    void rotateL();
};

#endif