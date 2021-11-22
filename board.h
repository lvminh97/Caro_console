#ifndef _BOARD_H
#define _BOARD_H

class Board{
private:
    int height, width;
    int **map;
public:
    Board(int w = 10, int h = 10){
        height = h;
        width = w;
        map = new int*[height];
        for(int i = 0; i < height; i++){
            map[i] = new int[width];
        }
    }

    ~Board(){
        for(int i = 0; i < height; i++){
            delete[] map[i];
        }
        delete[] map;
    }

    void initBoard(){

    }

    int getWidth() const {
        return width;
    }

    int getHeight() const {
        return height;
    }

    int get(int x, int y){
        return map[y][x];
    }

    void set(int x, int y, int v){ // v in {0: empty, 1: player 1, 2: player 2}
        map[y][x] = v;
    }
};

#endif
