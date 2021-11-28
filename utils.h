#ifndef _UTILS_H
#define _UTILS_H

#include <cstdlib>
#include <windows.h>

class Utils{
public:
    // Xóa màn hình console
    static void clrscr(){
        system("cls");
    }

    // Đưa con trỏ đi đến vị trí có tọa độ (x,y) trên console
    static void consoleGotoXY(short x, short y){
        HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD coor = {x, y};  
        SetConsoleCursorPosition(handle, coor);
    }

    // Lấy tọa độ hiện tại cúa con trỏ trên console và lưu vào 2 biến tham chiếu x, y
    static void consoleGetXY(short &x, short &y){
        HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO info;
        GetConsoleScreenBufferInfo(handle, &info);
        x = info.dwCursorPosition.X;
        y = info.dwCursorPosition.Y;
    }

    // Thay đổi màu chữ và màu nền trong console, giá trị màu 0-15
    static void setColor(unsigned char textColor, unsigned char bgColor){
        HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(handle, (bgColor << 4) | textColor);
    }
};

#endif
