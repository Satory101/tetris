#include "Utils.h"

namespace Utils {
    void gotoxy(int x, int y)
    {
        HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO cursor = { 1, false };
        SetConsoleCursorInfo(hCons, &cursor);

        COORD p = { x, y };
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
    }
}
