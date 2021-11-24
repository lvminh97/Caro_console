#include <iostream>
#include <cstdlib>
#include "board.h"
#include "ui.h"
#include "play.h"

using namespace std;

UI ui;
Board board(10, 10);
char choice, choice2;
int result;

int main(int argc, char **argv){
    ui.init(&board);
    while(true){
        bool isContinue = true;
        choice = ui.showMainMenu();
        switch (choice){
        case '1':
            board.init();
            ui.drawBoard();
            result = Play::run(&ui, &board);
            ui.showResult(result);
            system("pause");
            break;
        case '2':
            while(true){
                choice2 = ui.selectBotLevel();
                if(choice2 >= '1' && choice2 <= '3'){
                    Utils::consoleGotoXY(0, 12);
                    if(choice2 == '1')
                        printf("Select easy mode\n");
                    else if(choice2 == '2')
                        printf("Select normal mode\n");
                    else if(choice2 == '3')
                        printf("Select hard mode\n");
                    system("pause");
                    break;
                }
                else if(choice2 == '4')
                    break;
            }
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
