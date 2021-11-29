#include <iostream>
#include <cstdlib>
#include <unordered_map>
#include <string>
#include "board.h"
#include "ui.h"
#include "play.h"
#include "player.h"

using namespace std;

UI ui;
Board board(10, 10);
char choice, choice2;
int result;
int nPlayer = 0;
Player *player1, *player2, playerList[1001];
unordered_map<string, int> hPlayers;

int main(int argc, char **argv){
    ui.loadPlayerHistory(hPlayers, playerList, nPlayer);
    ui.init(&board);
    while(true){
        string name;
        bool isContinue = true;
        choice = ui.showMainMenu();
        switch (choice){
        case '1':
            Utils::clrscr();
            printf("Enter player1\'s name: ");
            getline(cin, name);
            if(hPlayers[name] == 0){
                nPlayer++;
                hPlayers[name] = nPlayer;
                playerList[nPlayer].setName(name); 
            }
            player1 = &playerList[hPlayers[name]];
            printf("Enter player2\'s name: ");
            getline(cin, name);
            if(hPlayers[name] == 0){
                nPlayer++;
                hPlayers[name] = nPlayer;
                playerList[nPlayer].setName(name); 
            }
            player2 = &playerList[hPlayers[name]];
            board.init();
            ui.drawBoard(player1->getName(), player2->getName());
            result = Play::run(&ui, &board);
            ui.showResult(result, player1->getName(), player2->getName());
            if(result == 1){
                player1->win();
                player2->lose();
            }
            else if(result == 2){
                player1->lose();
                player2->win();
            }
            else if(result == 0){
                player1->draw();
                player2->draw();
            }
            system("pause");
            break;
        case '2':
            while(true){
                choice2 = ui.selectBotLevel();
                if(choice2 >= '1' && choice2 <= '3'){
                    Utils::consoleGotoXY(0, 12);
                    if(choice2 == '1')
                        cout << "Select easy mode\n";
                    else if(choice2 == '2')
                        cout << "Select normal mode\n";
                    else if(choice2 == '3')
                        cout << "Select hard mode\n";
                    system("pause");
                    break;
                }
                else if(choice2 == '4')
                    break;
            }
            break;
        case '3':
            if(board.getHistory().size() > 0){
                ui.drawBoard(player1->getName(), player2->getName());
                result = Play::replay(&ui, &board);
                ui.showResult(result, player1->getName(), player2->getName());
            }
            else{
                Utils::clrscr();
                cout << "No history\n"; 
            }
            system("pause");
            break;
        case '4':
            ui.showHistory(playerList, nPlayer);
            system("pause");
            break;
        case '5':
            isContinue = false;
            break;
        }
        if(isContinue == false){
            Utils::clrscr();
            ui.savePlayerHistory(playerList, nPlayer);
            break;
        }
    }
    return 0;
}
