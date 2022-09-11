#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int maxAreaOfIslandHelper(vector<vector<int>> &grid, int sr, int sc, int &currArea) {
        // Base cases 
        if(sr < 0 || sr >= grid.size() || sc < 0 || sc >= grid[0].size() || grid[sr][sc] == 0) {
            return 0;
        }
        if(grid[sr][sc] == 2) return 0; // already visited
        
        if(grid[sr][sc] == 1) {
            grid[sr][sc] = 2;
            currArea++;
        }
        int left = maxAreaOfIslandHelper(grid, sr + 1, sc, currArea);
        int right = maxAreaOfIslandHelper(grid, sr - 1, sc, currArea);
        int up = maxAreaOfIslandHelper(grid, sr, sc + 1, currArea);
        int down = maxAreaOfIslandHelper(grid, sr, sc - 1, currArea);
        return currArea;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int localArea = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] == 1) {
                    int k = 0;
                     localArea = max(maxAreaOfIslandHelper(grid, i, j, k), localArea);
                }
            }
        }
        return localArea;
    }
int main(){





}

