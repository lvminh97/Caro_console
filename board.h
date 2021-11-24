#ifndef _BOARD_H
#define _BOARD_H

class Board{
private:
    int height, width;
    int **map;
    int remain;
public:
    // khởi tạo board với kích thước w x h
    Board(int w = 10, int h = 10){
        height = h;
        width = w;
        remain = width * height;
        map = new int*[height];
        for(int i = 0; i < height; i++){
            map[i] = new int[width];
        }
    }

    // Giải phóng bộ nhớ đã cấp phát con trỏ map khi kết thúc chương trình
    ~Board(){
        for(int i = 0; i < height; i++){
            delete[] map[i];
        }
        delete[] map;
    }

    // Khởi tạo ma trận map với các giá trị 0 (empty)
    void init(){
        for(int i = 0; i < height; i++){
            for(int j = 0; j < width; j++){
                map[i][j] = 0;
            }
        }
    }

    // Lấy chiều rộng
    int getWidth() const {
        return width;
    }

    // Lấy chiều cao
    int getHeight() const {
        return height;
    }

    // Lấy số ô trống còn lại
    int getRemain() const {
        return remain;
    }

    // Lấy trạng thái hiện tại của 1 ô: {0: empty, 1: player 1, 2: player 2}
    int get(int x, int y){
        return map[y][x];
    }

    // Set trạng thái cho 1 ô: {0: empty, 1: player 1, 2: player 2}
    bool set(int x, int y, int v){
        if(map[y][x] == 0 && v != 0){
            remain--;
            map[y][x] = v;
            return true;
        }
        return false;
    }

    // Kiểm tra điều kiện thắng: {0: hòa, 1: player 1 thắng, 2: player 2 thắng}
    int checkWinCondition(){
        for(int y = 0; y < height; y++){
            for(int x = 0; x < width; x++){
                // hàng ngang
                if(x + 3 < width && map[y][x] != 0 && map[y][x] == map[y][x + 1] && map[y][x] == map[y][x + 2] && map[y][x] == map[y][x + 3]){
                    return map[y][x];
                }
                // hàng dọc
                if(y + 3 < height && map[y][x] != 0 && map[y][x] == map[y + 1][x] && map[y][x] == map[y + 2][x] && map[y][x] == map[y + 3][x]){
                    return map[y][x];
                }
                // đường chéo (1,1) -> (4,4)
                if(x + 3 < width && y + 3 < height && map[y][x] != 0 && map[y][x] == map[y + 1][x + 1] && map[y][x] == map[y + 2][x + 2] && map[y][x] == map[y + 3][x + 3]){
                    return map[y][x];
                }
                // đường chéo (4,1) -> (1,4)
                if(x + 3 < width && y >= 3 && map[y][x] != 0 && map[y][x] == map[y - 1][x + 1] && map[y][x] == map[y - 2][x + 2] && map[y][x] == map[y - 3][x + 3]){
                    return map[y][x];
                }
            }
        }
        return 0;
    }
};

#endif
