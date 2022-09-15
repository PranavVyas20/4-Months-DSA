#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void colorBorderHelper(vector<vector<int>> &grid, int sr, int sc, int prevR, int prevC, int color) {
    // Base cases
    if(sr <= 0 || sc <= 0 || sr >= grid.size() - 1 || sc >= grid.size() - 1) {
        return;
    }
    if(grid[sr][sc] == -1 || grid[sr][sc] == color) return;

    if(grid[sr][sc] == grid [prevR][prevC]) {
        grid[sr][sc] = color;
        grid[prevR][prevC] = color;
    } 
    else {
        grid[sr][sc] = -1;
    }
    colorBorderHelper(grid, sr + 1, sc, sr, sc, color);
    colorBorderHelper(grid, sr - 1, sc, sr, sc, color);
    colorBorderHelper(grid, sr, sc + 1, sr, sc, color);
    colorBorderHelper(grid, sr, sc - 1, sr, sc, color);
}



int main(){





}

