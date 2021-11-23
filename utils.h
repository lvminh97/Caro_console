#ifndef _UTILS_H
#define _UTILS_H

#include <windows.h>

class Utils{
public:
    static void consoleGotoXY(short x, short y){
        HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD coor = {x, y};  
        SetConsoleCursorPosition(handle, coor);
    }

    static void consoleGetXY(short &x, short &y){
        HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO info;
        GetConsoleScreenBufferInfo(handle, &info);
        x = info.dwCursorPosition.X;
        y = info.dwCursorPosition.Y;
    }

    static void setColor(unsigned char textColor, unsigned char bgColor){
        HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(handle, (bgColor << 4) | textColor);
    }
};

#endif
