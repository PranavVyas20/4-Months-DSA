#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Can also be done by eliminating corner rows and cols 1's
int finalRes = 0;

int numEnclavesHelper(vector<vector<int>> & grid, int row, int col, vector<vector<bool>>& vis) {
    if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()) {
        return -1;
    } 
    if(vis[row][col]) {
        return 0;
    }
    if(grid[row][col] == 0) {
        return 0;
    }
    vis[row][col] = true;

    int upwardCallAns = numEnclavesHelper(grid, row - 1, col, vis);
    int rightCallAns = numEnclavesHelper(grid, row , col + 1, vis);
    int leftCallAns = numEnclavesHelper(grid, row, col - 1, vis);
    int downwardCallAns = numEnclavesHelper(grid, row + 1, col, vis);

    if(upwardCallAns != -1 && downwardCallAns != -1 && rightCallAns != -1 && leftCallAns != -1) {
        return upwardCallAns + downwardCallAns + leftCallAns + rightCallAns + 1;
    }
    else {
        return -1;
    }

}
int numEnclaves(vector<vector<int>>& grid) {
    vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), false));
    for(int i = 0; i < grid.size(); i++) {
        for(int j = 0; j < grid[i].size(); j++) {
            if(grid[i][j] == 1 && vis[i][j] == false) {
                int smallAns = numEnclavesHelper(grid, i, j, vis);
                if(smallAns >= 0) {
                    finalRes += smallAns;
                }
            }
        }
    }
    return finalRes;
}

int main(){





}



