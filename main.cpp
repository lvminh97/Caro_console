#include <iostream>
#include <cstdlib>
#include "board.h"
#include "ui.h"

using namespace std;

UI ui;
Board board(10, 10);

int turn;
int main(int argc, char **argv){
    ui.init(&board);
    while(true){
        bool isContinue = true;
        char choice = ui.showMainMenu();
        switch (choice){
        case '1':
            board.init();
            system("cls");
            printf("=> Player 1 = X, Player 2 = O:\n\n");
            ui.drawBoard();
            turn = 1;
            short x, y;
            while(board.checkWinCondition() == 0 && board.getRemain() > 0){
                ui.turn(turn, x, y);
                ui.put(x, y, turn);
                board.set(x, y, turn);
                turn = turn != 1 ? 1 : 2;
            }
            ui.showResult(board.checkWinCondition());
            system("pause");
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
