#ifndef _UI_H
#define _UI_H

#include <iostream>
#include <conio.h>
#include "utils.h"
#include "board.h"

class UI{
private:
    Board *board;

public:
    void init(Board *b){
        this->board = b;
    }

    char showMainMenu(){
        short cX, cY;
        system("color 0f");
        system("cls");
        printf("*------MAIN MENU-------*\n");
        printf("Press number to choice: ");
        Utils::consoleGetXY(cX, cY);
        printf("\n1.Play with other player\n");
        printf("2.Replay\n");
        printf("3.Exit\n");
        Utils::consoleGotoXY(cX, cY);
        return getche();
    }

    void drawBoard(){
        system("cls");
        printf("=> Player 1 = X, Player 2 = O:\n\n   ");
        for(int i = 0; i < board->getWidth(); i++){
            printf(" %2d ", i);
        }
        printf("\n   ");
        for(int i = 0; i < board->getWidth(); i++){
            printf("|---");
        }
        printf("|\n");
        for(int i = 0; i < board->getHeight(); i++){
            printf("%2d |", i);
            for(int j = 0; j < board->getWidth(); j++){
                printf("   |");
            }
            printf("\n   |");
            for(int j = 0; j < board->getWidth(); j++){
                printf("---|");
            }
            printf("\n");
        }
    }

    void turn(int player, short &x, short &y){
        Utils::consoleGotoXY(0, board->getHeight() * 3 - 5);
        printf("Player %d\'s turn:                   ", player);
        Utils::consoleGotoXY(17, board->getHeight() * 3 - 5);
        scanf("%hu%hu", &x, &y);
    }

    void put(short x, short y, int v){
        if(v != 1 && v != 2)
            return;
        short cX, cY;
        Utils::consoleGetXY(cX, cY);
        Utils::consoleGotoXY(5 + 4 * x, 4 + 2 * y);
        if(v == 1){
            Utils::setColor(12, 0);
            printf("X");
        }
        else{
            Utils::setColor(10, 0); 
            printf("O");
        }
        Utils::consoleGotoXY(cX, cY);
        Utils::setColor(15, 0);
    }

    void showResult(int result){
        if(result == 0){
            Utils::consoleGotoXY(0, board->getHeight() * 3 - 5);
            printf("Result: Draw                          \n");
        }
        else{
            Utils::consoleGotoXY(0, board->getHeight() * 3 - 5);
            printf("Result: Player %d wins                \n", result);
        }
    }

};

#endif
