#pragma once
#ifndef GAME_H
#define GAME_H

#include "Map.h"
#include "Figure.h"
#include <iostream>

class Game {
private:
    int score = 0;
    const int WIDTH = 10 + 2;
    const int HEIGHT = 20 + 1;
    const int SLEEP_MAIN_LOOP = 50;
public:
    Game();
    void icrScore(int lines);
    void showScore();
    void gameOver();
    int run();
    int run2(); // (пока оставьте этот метод, если он вам нужен)
};

#endif