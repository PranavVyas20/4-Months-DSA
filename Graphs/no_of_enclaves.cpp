#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void doBoundaryDfs(int row, int col, vector<vector<int>> & grid, bool convert) {
    int maxRow = grid.size();
    int maxCol = grid[0].size();

    if(row < 0 || col < 0 || row >= maxRow || col >= maxCol || grid[row][col] == 0) {
        return;
    }

        grid[row][col] = 0;

    doBoundaryDfs(row + 1, col, grid, convert);
    doBoundaryDfs(row - 1, col, grid, convert);
    doBoundaryDfs(row, col + 1, grid, convert);
    doBoundaryDfs(row, col - 1, grid, convert);
}

int numEnclaves(vector<vector<int>>& grid) {
    int ans = 0;

    for (int i = 0; i < grid.size(); i++) {
        doBoundaryDfs(0, i, grid, true);
        doBoundaryDfs(grid.size() - 1, i, grid, true);
    }

    for (int i = 0; i < grid.size(); i++) {
        doBoundaryDfs(i, 0, grid, true);
        doBoundaryDfs(i, grid[0].size() - 1, grid, true);
    }

    for(int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if(grid[i][j] == 1) {
                ans ++;
            }
        }
    }
    return ans;
}
int main(){





}

