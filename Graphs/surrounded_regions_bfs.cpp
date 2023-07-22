#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>> & board) {
    vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
    int totalRows = board.size();
    int totalCols = board[0].size();

    vector<int> rowDir = {-1, 0, 1, 0};
    vector<int> colDir = {0, 1, 0, -1};
    
    queue<pair<int, int>> q;
    
    // Traverse over the 0th and last row
    for(int j = 0; j < totalCols; j++) {
        if(visited[0][j] == false) {
            q.push( {0, j} );
        }
        if(visited[totalRows - 1][j] == false) {
            q.push( {totalRows - 1, j} );
        }
    }

    // Traverse over the 0th column and last column
    for(int i = 0; i < totalRows; i++) {
        if(visited[i][0] == false) {
            q.push( {i, 0} );
        }
        if(visited[i][totalCols] == false) {
            q.push( {i, totalCols} );
        }
    }

    while(! q.empty()) {
        int frontRow = q.front().first;
        int frontCol = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nextRow = frontRow + rowDir[i];
            int nextCol = frontCol + colDir[i];

            if(nextRow >= 0 and 
            nextRow < totalRows and 
            nextCol >= 0 and 
            nextCol < totalCols and
            board[nextRow][nextCol] == 'O' and
            visited[nextRow][nextCol] == false
            ) {
                visited[nextRow][nextCol] = true;
                q.push( {nextRow, nextCol} );
            }
        }
    }
    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[i].size(); j++) {
            if(board[i][j] == 'O' && visited[i][j] == false) {
                board[i][j] = 'X';
            }
        }
    }
}
int main(){





}

