#include "Game.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include "Utils.h"

using namespace std;

Game::Game() {}

void Game::icrScore(int lines) {
    switch (lines) {
    case 1:
        score += 1;
        break;

    case 2:
        score += 3;
        break;
    case 3:
        score += 8;
        break;
    case 4:
        score += 15;
        break;
    }
}

void Game::showScore() {
    Utils::gotoxy(50, 0);
    cout << "score: " << score;
}

void Game::gameOver() {
    Utils::gotoxy(50, 0);
   
    cout << "Game Over" << endl;
    Utils::gotoxy(50, 1);
    //cout << "                                                  Набрано очков: "<< score << endl;
    cout << "Набрано очков: " << score << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
   system("pause");
}

int Game::run() {
    Map map;
    map.init(WIDTH, HEIGHT);
    map.show();
    showScore();

    Figure fig;
    fig.spawn();

    int ch = 0;

    while (true) {
        while (!_kbhit()) {
            fig.hide();
            if (fig.allowMove()) {
                fig.moveDown();
            }
            if (map.isCollision(fig)) {
                fig.moveUp();
                map.fixed(fig);
                fig.show();
                int lines = map.deleteLines(WIDTH);

                icrScore(lines);
                showScore();

                map.show();

                fig.spawn();
                if (map.isCollision(fig)) {
                    fig.show();
                    this->gameOver();
                    return 0;
                }
            }

            fig.show();
            Sleep(SLEEP_MAIN_LOOP);
        }

        ch = _getch();

     /*   if (ch == 224) {
            ch = _getch();
            Utils::gotoxy(20, 20);
            cout << ch;
        }*/

        switch (ch) {
        case 77:  //вправо
            fig.hide();
            fig.moveRight();

            if (map.isCollision(fig)) {
                fig.moveLeft();
            }
            break;
        case 80:
            fig.hide();
            fig.moveDown();
            if (map.isCollision(fig)) {
                fig.moveUp();
            }
            break;
        case 75:
            fig.hide();
            fig.moveLeft();
            if (map.isCollision(fig)) {
                fig.moveRight();
            }
            break;

        case 72:
            fig.hide();
            fig.rotateR();
            if (map.isCollision(fig)) {
                fig.rotateL();
            }
            break;

        case 32:
            fig.hide();
            fig.rotateL();
            if (map.isCollision(fig)) {
                fig.rotateR();
            }
            break;
        }
    }

    return 0;
}

int Game::run2() {  // (пока оставьте этот метод, если он вам нужен)

    Map map;

    map.init(WIDTH, HEIGHT);
    map.show();


    Figure fig;

    fig.spawn();


    int ch = 0;
    int i = 0;

    int x = 5, y = 5;

    while (true) {
        while (!_kbhit()) {
            fig.hide();
            //fig.moveDown();

            if (map.isCollision(fig)) {
                fig.moveUp();
                map.fixed(fig);
                map.deleteLines(WIDTH);
                map.show();


                fig.spawn();
            }

            fig.show();

            //Sleep(200);






        }
        ch = _getch();

        if (ch == 224) {  //when push arrow button we have two codes
            ch = _getch();
            Utils::gotoxy(20, 20);
            cout << ch;
        }

        switch (ch) {
        case 77:  //вправо
            fig.hide();
            fig.moveRight();

            if (map.isCollision(fig)) {
                fig.moveLeft();
            }
            break;
        case 80:
            fig.hide();
            fig.moveDown();

            if (map.isCollision(fig)) {
                fig.moveUp();
            }
            break;
        case 75:
            fig.hide();
            fig.moveLeft();
            if (map.isCollision(fig)) {
                fig.moveRight();
            }
            break;

        case 72:
            fig.hide();
            fig.rotateR();
            if (map.isCollision(fig)) {
                fig.rotateL();
            }
            break;


        case 32:
            fig.hide();
            fig.rotateL();
            if (map.isCollision(fig)) {
                fig.rotateR();
            }
            break;
        }

    }
}