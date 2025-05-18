#ifndef FIELD_HPP
#define FIELD_HPP

#include<iostream>
#include<string>
#include<vector>

using namespace std;

class TicTacToe {
    vector<vector<string>> board;
    bool gameover = false;
    string player = "X";
    int counter = 1;

public:
    TicTacToe() {
        init();
    };
    void init(){
        board = vector<vector<string>>(3, vector<string>(3, ("#")));
        player = "X";
        counter = 1;
    }
    void turn(int x, int y) {
        board[x][y] = player;
        counter++;
    }
    void switchplayer() {
        if(player == "X") {
            player = "O";
        } else {
            player = "X";
        }
    }

    bool win() {
        for(int i = 0; i < 3; i++) {  //Reihen
            if(board[0][i] == player && board[1][i] == player && board[2][i] == player) {
                cout << "Player " << player << " wins" << endl;
                gameover = true;
            }
        }
        for(int i = 0; i < 3; i++) { //Spalten
            if(board[i][0] == player && board[i][1] == player && board[i][2] == player) {
                cout << "Player " << player << " wins" << endl;
                gameover = true;
            }
        }
        if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {  // Diagonalen
            cout <<"Player " << player<<  "wins!" << endl;
            gameover = true;
        }
        if (board[2][0] == player && board[1][1] == player && board[0][2] == player) {
            cout <<"Player " << player<<  "wins!" << endl;
            gameover = true;
        }
        return gameover;
    };
    bool draw() {
        int count = 0;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(board[i][j] != "#") {
                    count += 1;
                }
            }
        }
        if(count == 9 && !gameover) {
            cout << "It's a draw" << endl;
            gameover = true;
            return gameover;
        }
        gameover = false;;
        return gameover;
    };
    void reset() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = '#';
            }
        };
        counter = 1;
        player = "X";
    }
    void display() const {
        cout << endl;
        cout << "RUNDE: " << counter << endl;
        cout << "PLAYER: " << player << endl;
        cout << "  1 2 3" << endl; // Zeigt Spaltennummern oben
        for (int i = 0; i < 3; i++) {
            cout << i+1 << " "; // Zeigt Zeilennummer vor jeder Zeile
            for (int j = 0; j < 3; j++) {
                cout << board[j][i] << " ";
            }
            cout << endl;
        }
    }
    bool validturn(int x, int y) const {
        if(board[x][y]== "#") {
            return true;
        }
        return false;
    }
};

#endif //FIELD_HPP
