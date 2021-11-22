#include <iostream>
#include <cstdlib>
#include <conio.h>
#include "board.h"
#include "ui.h"

using namespace std;

int main(int argc, char **argv){
    system("cls");
    printf("=> Player 1 = X, Player 2 = O:\n\n");
    Board board(10, 10);
    UI::drawBoard(board);
    getch();
    return 0;
}
