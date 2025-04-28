#include "Figure.h"
#include <iostream>
#include <stdlib.h>

using namespace std;
#include <windows.h>

int Figure::GetX(int i) {
    return vec[i].x;
}

int Figure::GetY(int i) {
    return vec[i].y;
}

int Figure::GetVecSize() {
    return vec.size();
}

void Figure::push(int x, int y) {
    Point temp;
    temp.x = x;
    temp.y = y;
    vec.push_back(temp);
}

void Figure::show() {
    for (int i = 0; i < vec.size(); i++) {
        Utils::gotoxy(vec[i].x, vec[i].y);
        cout << "*";
    }
}

void Figure::hide() {
    for (int i = 0; i < vec.size(); i++) {
        Utils::gotoxy(vec[i].x, vec[i].y);
        cout << " ";
    }
}

void Figure::moveDown() {
    for (int i = 0; i < vec.size(); i++) {
        vec[i].y++;
    }
}

void Figure::moveUp() {
    for (int i = 0; i < vec.size(); i++) {
        vec[i].y--;
    }
}

void Figure::moveLeft() {
    for (int i = 0; i < vec.size(); i++) {
        vec[i].x--;
    }
}

void Figure::moveRight() {
    for (int i = 0; i < vec.size(); i++) {
        vec[i].x++;
    }
}

bool Figure::allowMove() {
    if (countTact < tick_rate) {
        countTact++;
        return false;
    }
    else {
        countTact = 0;
        return true;
    }
}

void Figure::spawn() {
    vec.clear();
    int r = rand() % 7;
    switch (r) {
    case 0:
        this->push(4, 0);
        this->push(5, 0);
        this->push(4, 1);
        this->push(5, 1);
        break;

    case 1:
        this->push(4, 0);
        this->push(5, 0);
        this->push(6, 0);
        this->push(7, 0);
        break;

    case 2:
        this->push(4, 0);
        this->push(5, 0);
        this->push(6, 0);
        this->push(6, 1);
        break;

    case 3:
        this->push(4, 0);
        this->push(5, 0);
        this->push(6, 0);
        this->push(4, 1);
        break;

    case 4:
        this->push(4, 0);
        this->push(5, 0);
        this->push(5, 1);
        this->push(6, 1);
        break;

    case 5:
        this->push(4, 1);
        this->push(5, 1);
        this->push(5, 0);
        this->push(6, 0);
        break;

    case 6:
        this->push(4, 1);
        this->push(5, 1);
        this->push(6, 1);
        this->push(5, 0);
        break;
    }
}

void Figure::rotateR() {
    for (int i = 0; i < vec.size(); i++)
    {
        int x = -(vec[i].y - vec[1].y) + vec[1].x;
        int y = (vec[i].x - vec[1].x) + vec[1].y;

        vec[i].x = x;
        vec[i].y = y;
    }
}

void Figure::rotateL() {
    for (int i = 0; i < vec.size(); i++)
    {
        int x = (vec[i].y - vec[1].y) + vec[1].x;
        int y = -(vec[i].x - vec[1].x) + vec[1].y;

        vec[i].x = x;
        vec[i].y = y;
    }
}