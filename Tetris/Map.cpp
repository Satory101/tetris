#include "Map.h"
#include <iostream>
#include <vector>
#include <windows.h>
using namespace std;
void Map::init(int width, int height)
{
    _width = width;
    _height = height;
    vector<int> temp;
    temp.push_back(BORDER);
    for (int i = 1; i < width - 1; i++)
        temp.push_back(EMPTY);
    temp.push_back(BORDER);


    for (int i = 0; i < height - 1; i++)

        vec.push_back(temp);

    temp.clear();
    for (int i = 0; i < width; i++)
        temp.push_back(BORDER);
    vec.push_back(temp);
}

void Map::show() {

    /*for (int i = 0; i < vec.size(); i++) {
        Utils::gotoxy(19, i);
        for (int j = 0; j < vec[i].size(); j++) {
            cout << vec[i][j];
        }
        cout << endl;
    }*/

    Utils::gotoxy(0, 0);
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[i].size(); j++) {
            if (vec[i][j] == BORDER)
                cout << '#';

            if (vec[i][j] == BLOCK)
                cout << '*';

            if (vec[i][j] == EMPTY)
                cout << ' ';
        }
        cout << endl;
    }

}
void Map::animDeleteLines(const vector <int> lines) {

    if (lines.empty())
        return;

    for (int i = 0; i <= _width - 2; i++) {
        for (int j = 0; j < lines.size(); j++) {
            Utils::gotoxy(i, lines[j]);
            cout << " ";
        }
        Sleep(SLEEP_ANIM_DEL_LINES);
    }

}

int Map::deleteLines(int width) {

    vector <int> lines;
    // определение линий, которые нужно удалить
    for (int i = vec.size() - 2; i >= 0; i--) {
        int d = 0;
        for (int j = 1; j < vec[i].size() - 1; j++) {
            if (vec[i][j] == BLOCK) {
                d++;
            }

            else {
                break;
            }

        }
        if (d == BLOCKS_IN_LINE) {
            lines.push_back(i);

        }
    }



    // удаление рядов из вектора
    for (int i = 0; i < lines.size(); i++) {
        vec.erase(vec.begin() + lines[i]);
    }
    // добавление пустых рядов сверху в стакан взамен удаленных
    vector<int> temp;
    temp.push_back(BORDER);
    for (int i = 1; i < width - 1; i++)
        temp.push_back(EMPTY);
    temp.push_back(BORDER);


    for (int i = 0; i < lines.size(); i++)

        vec.insert(vec.begin(), temp);
    animDeleteLines(lines);

    return lines.size();

}


bool Map::isCollision(Figure& fig) {
    for (int i = 0; i < fig.GetVecSize(); i++) {

        if (fig.GetY(i) < 0) {

            return true;
        }

        if (vec[fig.GetY(i)][fig.GetX(i)] == BORDER) {

            return true;
        }



        if (vec[fig.GetY(i)][fig.GetX(i)] == BLOCK) {  // столкновение с другой фигурой

            return true;
        }
    }
    return false;

}

void Map::fixed(Figure& fig) {
    for (int i = 0; i < fig.GetVecSize(); i++) {
        vec[fig.GetY(i)][fig.GetX(i)] = BLOCK;

    }
}