#ifndef _BOARD_H
#define _BOARD_H

class Board{
private:
    int height, width;
    int **map;
    int remain;
public:
    Board(int w = 10, int h = 10){
        height = h;
        width = w;
        remain = width * height;
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

    void init(){
        for(int i = 0; i < height; i++){
            for(int j = 0; j < width; j++){
                map[i][j] = 0;
            }
        }
    }

    int getWidth() const {
        return width;
    }

    int getHeight() const {
        return height;
    }

    int getRemain() const {
        return remain;
    }

    int get(int x, int y){
        return map[y][x];
    }

    bool set(int x, int y, int v){ // v in {0: empty, 1: player 1, 2: player 2}
        if(map[y][x] == 0 && v != 0){
            remain--;
            map[y][x] = v;
            return true;
        }
        return false;
    }

    int checkWinCondition(){
        for(int y = 0; y < height; y++){
            for(int x = 0; x < width; x++){
                // check horizontal
                if(x + 3 < width && map[y][x] != 0 && map[y][x] == map[y][x + 1] && map[y][x] == map[y][x + 2] && map[y][x] == map[y][x + 3]){
                    return map[y][x];
                }
                // check vertical
                if(y + 3 < height && map[y][x] != 0 && map[y][x] == map[y + 1][x] && map[y][x] == map[y + 2][x] && map[y][x] == map[y + 3][x]){
                    return map[y][x];
                }
                // check diagonal 1
                if(x + 3 < width && y + 3 < height && map[y][x] != 0 && map[y][x] == map[y + 1][x + 1] && map[y][x] == map[y + 2][x + 2] && map[y][x] == map[y + 3][x + 3]){
                    return map[y][x];
                }
                // check diagonal 2
                if(x + 3 < width && y >= 3 && map[y][x] != 0 && map[y][x] == map[y - 1][x + 1] && map[y][x] == map[y - 2][x + 2] && map[y][x] == map[y - 3][x + 3]){
                    return map[y][x];
                }
            }
        }
        return 0;
    }
};

#endif
