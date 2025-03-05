#include <iostream>
#include <windows.h>
#include <conio.h>
#include <vector>

// анимация удаления
// рефакторинг кода
// фигура фиксируется относительно установленных фигур
// удаление заполненных рядов
// контроль границ, чтобы фигура не выходила за пределы игрового поля.
//  фиксация фигуры

using namespace std;
void gotoxy(int x, int y)
{

    COORD p = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);

}

const int WIDTH = 10 + 2;
const int HEIGHT = 20 + 1;

const int BORDER = 1;
const int EMPTY = 0;
const int BLOCK = 2;

const int BLOCKS_IN_LINE = 10;

struct Point {
    int x;
    int y;

};

class Figure {

    vector <Point> vec;
    
public:
    
    int GetX(int i) {
        
       return vec[i].x;

    }

    int GetY(int i) {

        return vec[i].y;

    }

    int GetVecSize() {

        return vec.size();

    }

    void push(int x, int y) {
        Point temp;
        temp.x = x;
        temp.y = y;
        vec.push_back(temp);

    } 

    void show() {
        for (int i = 0; i < vec.size(); i++) {
            gotoxy(vec[i].x, vec[i].y);
            cout << "*";

        }
    }

    void hide() {
        for (int i = 0; i < vec.size(); i++) {
            gotoxy(vec[i].x, vec[i].y);
            cout << " ";

        }
    }


    void moveDown() {
        for (int i = 0; i < vec.size(); i++) {
            vec[i].y++;

        }
    }

    void moveUp() {
        for (int i = 0; i < vec.size(); i++) {
            vec[i].y--;

        }
    }

    void moveLeft() {
        for (int i = 0; i < vec.size(); i++) {
            vec[i].x--;

        }
    }

    void moveRight() {
        for (int i = 0; i < vec.size(); i++) {
            vec[i].x++;

        }
    }

                       

    void spawn() {
        vec.clear();
        int r = rand() % 3;
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

        }
       

}

};
class Map {

    vector <vector <int>> vec;

public:
    
    void init(int width, int height)
    {
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

    void show() {

        for (int i = 0; i < vec.size(); i++) {
            gotoxy(19, i);
            for (int j = 0; j < vec[i].size(); j++) {
                cout << vec[i][j];
            }
            cout << endl;
        }
        gotoxy(0, 0);
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


    void deleteLines(int width) {

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

    }


    bool isCollision(Figure& fig) {
        for (int i = 0; i < fig.GetVecSize(); i++) {
            if (vec[fig.GetY(i)][fig.GetX(i)] == BORDER) {

                return true;
            }
            if (vec[fig.GetY(i)][fig.GetX(i)] == BLOCK) {  // столкновение с другой фигурой

                return true;
            }
        }
        return false;

    }

    void fixed(Figure& fig) {
        for (int i = 0; i < fig.GetVecSize(); i++) {
            vec[fig.GetY(i)][fig.GetX(i)] = BLOCK;

        }




    }
};



class Game {

  

   


public:
    Game() {
    }
      

    int run() {

        Map map;

        map.init(WIDTH, HEIGHT);
        map.show();
        /*initVec(vec, WIDTH, HEIGHT);
        showField(vec);*/

        Figure fig;

        fig.spawn();

       /* fig.push(4, 0);
        fig.push(5, 0);
        fig.push(4, 1);
        fig.push(5, 1);*/

        


        int ch = 0;
        int i = 0;

        int x = 5, y = 5;

        while (true) {
            while (!_kbhit()) {
                fig.hide();
                fig.moveDown();

                if (map.isCollision(fig)) {
                    fig.moveUp();
                    map.fixed(fig);
                    map.deleteLines(WIDTH);
                    map.show();

                  
                     fig.spawn();
                }

                fig.show();

                Sleep(200);
                
               
                
               


            }
            ch = _getch();

            if (ch == 224) {  //when push arrow button we have two codes
                ch = _getch();
                gotoxy(20, 20);
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
                y++;
                break;
            case 75:
                fig.hide();
                fig.moveLeft();
                if (map.isCollision(fig)) {
                    fig.moveRight();
                }
                break;
            }

        }
        
        return 0;
    }


};

int main()
{
    Game game;
    game.run();
     
}