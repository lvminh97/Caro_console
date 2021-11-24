#include <iostream>
#include <cstdlib>
#include "board.h"
#include "ui.h"
#include "play.h"

using namespace std;

UI ui;
Board board(10, 10);
int result;

int main(int argc, char **argv){
    ui.init(&board);
    while(true){
        bool isContinue = true;
        char choice = ui.showMainMenu();
        switch (choice){
        case '1':
            board.init();
            ui.drawBoard();
            result = Play::run(&ui, &board);
            ui.showResult(result);
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
