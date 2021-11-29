#ifndef _PLAYER_H
#define _PLAYER_H

#include <iostream>
#include <string>

class Player{
private:
    string name;
    int _win, _draw, _lose;
public:
    Player(){
        name = "";
        _win = _draw = _lose = 0;
    }

    void reset(){
        name = "";
        _win = _draw = _lose = 0;
    }

    void setName(string n){
        name = n;
    }

    string getName(){
        return name;
    }

    void setWin(int w){
        _win = w;
    }

    int getWin() const {
        return _win;
    }

    void setDraw(int d){
        _draw = d;
    }

    int getDraw() const {
        return _draw;
    }

    void setLose(int l){
        _lose = l;
    }

    int getLose() const {
        return _lose;
    }

    void win(){
        _win++;
    }

    void draw(){
        _draw++;
    }

    void lose(){
        _lose++;
    }
};

#endif
