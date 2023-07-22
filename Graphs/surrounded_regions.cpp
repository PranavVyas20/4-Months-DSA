#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void doDfs(int row, int col, vector<vector<bool>>& vis, vector<vector<char>> board) {
    int maxRow = board.size();
    int maxCol = board[0].size();

    if(row < 0 || col < 0 || row >= maxRow 
    || col >= maxCol || board[row][col] == 'X' || vis[row][col] == true) {
        return;
    }
    vis[row][col] = true;

    doDfs(row + 1, col, vis, board);
    doDfs(row - 1, col, vis, board);
    doDfs(row, col + 1, vis, board);
    doDfs(row, col - 1, vis, board);
}
void solve(vector<vector<char>>& board) {
    vector<vector<bool>> vis(board.size(), vector<bool>(board[0].size(), false));
    // Dfs on first and last row
    for (int i = 0; i < board.size(); i++) {
        doDfs(0, i, vis, board);
        doDfs(board.size() - 1, i, vis, board);
    }

    for (int i = 0; i < board.size(); i++) {
        doDfs(i, 0, vis, board);
        doDfs(i, board[0].size() - 1, vis, board);
    }

    for(int i = 0; i < vis.size(); i++) {
        for(int j = 0; j < vis[i].size(); j++) {
            if(vis[i][j] == false) {
                board[i][j] = 'X';
            }
        }
    }
}
int main(){





}

