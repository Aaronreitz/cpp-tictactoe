#include<iostream>
#include<vector>
#include<string>
#include"field.hpp"

using namespace std;

int main() {
    TicTacToe game;
    string rematch = "n";
    short x = 0, y = 0;
    while(true) {
        game.display();
        cout << endl << "Gib eine Koordinate (X/Y): ";
        cin >> x >> y;
        x -= 1;
        y -= 1;
        game.turn(x,y);
        if(game.win() || game.draw()) {
            break;
        }
        cout << endl;
        game.switchplayer();

    }

}
