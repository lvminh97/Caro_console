#ifndef _UI_H
#define _UI_H

#include <iostream>
#include <fstream>
#include <conio.h>
#include <unordered_map>
#include <string>
#include "utils.h"
#include "board.h"
#include "player.h"

using namespace std;

class UI{
private:
    Board *board;

public:
    void init(Board *b){
        this->board = b;
    }

    // Load dữ liệu người chơi
    void loadPlayerHistory(unordered_map<string, int> &map, Player playerList[], int &N){
        ifstream historyFile;
        historyFile.open("player.dat", ios::in);
        int id = 1;
        string name;
        int win, draw, lose;
        historyFile >> N;
        for(int i = 0; i < N; i++){
            historyFile.get(); // xóa '\n' khỏi in buffer
            getline(historyFile, name);
            playerList[id].setName(name);
            historyFile >> win >> draw >> lose;
            playerList[id].setWin(win);
            playerList[id].setDraw(draw);
            playerList[id].setLose(lose);
            map[name] = id;
            id++;
        }
        historyFile.close();
    }

    // Ghi dữ liệu người chơi
    void savePlayerHistory(Player playerList[], int N){
        ofstream historyFile;
        historyFile.open("player.dat", ios::out);
        historyFile << N << endl;
        for(int i = 1; i <= N; i++){
            historyFile << playerList[i].getName() << endl;
            historyFile << playerList[i].getWin() << " " << playerList[i].getDraw() << " " << playerList[i].getLose() << endl;
        }
        historyFile.close();
    }

    // Hiển thị menu chọn chính
    char showMainMenu(){
        short cX, cY;
        system("color 0f");
        system("cls");
        printf("*------MAIN MENU-------*\n");
        printf("Press number to choice: ");
        Utils::consoleGetXY(cX, cY);
        printf("\n1.Play with other player\n");
        printf("2.Play with BOT\n");
        printf("3.Replay\n");
        printf("4.Player's information\n");
        printf("5.Exit\n");
        Utils::consoleGotoXY(cX, cY);
        return getche();
    }

    // Hiển thị menu chọn BOT level
    char selectBotLevel(){
        short cX, cY;
        Utils::consoleGotoXY(0, 6);
        printf("*------Play with BOT-------*\n");
        printf("Press number to choice: ");
        Utils::consoleGetXY(cX, cY);
        printf("\n1.Easy mode\n");
        printf("2.Normal mode\n");
        printf("3.Hard mode\n");
        printf("4.Back to Main menu\n");
        Utils::consoleGotoXY(cX, cY);
        return getche();
    }

    // Kẻ bàn cờ
    void drawBoard(string name1, string name2){
        system("cls");
        printf("=> %s = X, %s = O:\n\n   ", name1.c_str(), name2.c_str());
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

    // Nhập tọa độ ô muốn đánh: player in {1, 2}
    void turn(int player, short &x, short &y){
        Utils::consoleGotoXY(0, board->getHeight() * 3 - 5);
        printf("Player %d\'s turn:                   ", player);
        Utils::consoleGotoXY(17, board->getHeight() * 3 - 5);
        scanf("%hu%hu", &x, &y);
    }

    // Cập nhật ô mới đánh lên bàn cờ
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

    // Hiển thị kết quả
    void showResult(int result, string name1, string name2){
        if(result == 0){
            Utils::consoleGotoXY(0, board->getHeight() * 3 - 5);
            printf("Result: Draw                          \n");
        }
        else{
            Utils::consoleGotoXY(0, board->getHeight() * 3 - 5);
            printf("Result: %s wins                \n", result == 1 ? name1.c_str() : name2.c_str());
        }
    }

    void showHistory(Player playerList[], int N){
        Utils::clrscr();
        if(N == 0){
            cout << "No history\n";
        }
        else{
            cout << "Player's information:\n";
            for(int i = 1; i <= N; i++){
                printf("   %4d. ", i);
                cout << playerList[i].getName(); 
                cout << " => Win: " << playerList[i].getWin() << ", Draw: " << playerList[i].getDraw() << ", Lose: " << playerList[i].getLose();
                cout << endl;
            }
        }
        cout << endl;
    }
};

#endif
