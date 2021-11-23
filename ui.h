#ifndef _UI_H
#define _UI_H

#include <iostream>
#include <windows.h>
#include "board.h"

class UI{
private:
    static void consoleGotoXY(short x, short y){
        static HANDLE handle = NULL;  
        if(handle == NULL)
            handle = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD coor = {x, y};  
        SetConsoleCursorPosition(handle, coor);
    }

    static void consoleGetXY(short &x, short &y){
        static HANDLE handle = NULL;  
        if(handle == NULL)
            handle = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO info;
        GetConsoleScreenBufferInfo(handle, &info);
        x = info.dwCursorPosition.X;
        y = info.dwCursorPosition.Y;
    }

public:
    UI(){
        //
    }

    static char showMainMenu(){
        short cX, cY;
        system("cls");
        printf("*------MAIN MENU-------*\n");
        printf("Press number to choice: ");
        consoleGetXY(cX, cY);
        printf("\n1.Play with other player\n");
        printf("2.Replay\n");
        printf("3.Exit\n");
        consoleGotoXY(cX, cY);
        return getche();
    }

    static void drawBoard(Board board){
        int w, h;
        w = board.getWidth();
        h = board.getHeight();
        //
        printf("   ");
        for(int i = 0; i < w; i++){
            printf(" %2d ", i);
        }
        printf("\n   ");
        for(int i = 0; i < w; i++){
            printf("|---");
        }
        printf("|\n");
        for(int i = 0; i < h; i++){
            printf("%2d |", i);
            for(int j = 0; j < w; j++){
                printf("   |");
            }
            printf("\n   |");
            for(int j = 0; j < w; j++){
                printf("---|");
            }
            printf("\n");
        }
    }

    static void put(short x, short y, int v){
        if(v != 1 && v != 2)
            return;
        short cX, cY;
        consoleGetXY(cX, cY);
        consoleGotoXY(5 + 4 * x, 4 + 2 * y);
        if(v == 1)
            printf("X");
        else 
            printf("O");
        consoleGotoXY(cX, cY);
    }

};

#endif
