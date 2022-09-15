#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isSafeToPlace(vector < vector < char >> & board, int row, int col, char c) {
  for (int i = 0; i < 9; i++) {
    if (board[i][col] == c)
      return false;

    if (board[row][i] == c)
      return false;

    if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
      return false;
  }
  return true;
}
bool solve(vector<vector<char>> & board, int r, int c) {
    // Base case here
    if(r == board.size()) {
        return true;
    }
    int nextRowIdx = 0;
    int nextColIdx = 0;

    if(c == board[0].size() - 1) {
        nextRowIdx = r + 1;
        nextColIdx = 0;
    } else {
        nextRowIdx = r;
        nextColIdx = c + 1;
    }

    if(board[r][c] == '.') {
        for (char ch = '1'; ch <= '9'; ch++) {
            if(isSafeToPlace(board, r, c, ch)) {
                board[r][c] = ch;
                bool canPlaceNext = solve(board, nextRowIdx, nextColIdx);
                if(canPlaceNext == false) {
                    board[r][c] = '.';
                } else {
                    return true;
                }
            }
        }
        // If we couldn't place any no from 1 - 9
        return false;
    } else {
        bool canPlaceNext = solve(board, nextRowIdx, nextColIdx);
        return canPlaceNext;
    }
    // just for the sake of returning a bool
    return true;
}
    void solveSudoku(vector<vector<char>>& board) {
        bool solveAns = solve(board, 0, 0);
    }
int main(){





}

