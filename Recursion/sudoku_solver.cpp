#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isSafeToPlace(vector<vector<char>> &board, int row, int col, char c) {
    for (int i = 0; i < 9; i++){
        if (board[i][col] == c)
            return false;

        if (board[row][i] == c)
            return false;

        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
            return false;
    }
    return true;
}
bool solve(vector<vector<char>> &board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {

            if (board[i][j] == '.'){

                for (char ch = '1'; ch <= '9'; ch++) {

                    if (isSafeToPlace(board, i, j, ch)) {
                        board[i][j] = ch;
                        bool canPlaceNext = solve(board);

                        if (canPlaceNext == false) {
                            board[i][j] = '.';
                        }
                        else {
                            return true;
                        }
                    }
                }
                // If we couldn't place any no from 1 - 9
                return false;
            }
        }
    }
    // just for the sake of returning a bool
    return true;
}
void solveSudoku(vector<vector<char>> &board) {
    bool solveAns = solve(board);
}
int main() {

}
