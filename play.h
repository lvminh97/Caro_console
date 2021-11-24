#ifndef _PLAY_H
#define _PLAY_H

#include "ui.h"
#include "board.h"

class Play{
public:
    static int run(UI *ui, Board *board){
        int turn = 1;
        short x, y;
        while(board->getRemain() > 0 && board->checkWinCondition() == 0){
            ui->turn(turn, x, y);
            if(board->set(x, y, turn) == true){
                ui->put(x, y, turn);
                turn = turn != 1 ? 1 : 2;
            }
        }
        return board->checkWinCondition();
    }
};

#endif
