#include <iostream>
#include <cstdlib>
#include <conio.h>
#include "board.h"
#include "ui.h"

using namespace std;

int main(int argc, char **argv){
    Board board(10, 10);
    while(true){
        bool isContinue = true;
        char choice = UI::showMainMenu();
        switch (choice){
        case '1':
            board.init();
            system("cls");
            printf("=> Player 1 = X, Player 2 = O:\n\n");
            UI::drawBoard(board);
            while(true);
            break;
        default:
            isContinue = false;
            break;
        }
        if(isContinue == false){
            system("cls");
            break;
        }
    }
    return 0;
}
