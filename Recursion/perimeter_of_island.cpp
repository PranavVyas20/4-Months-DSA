#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int islandPerimeterHelper(vector<vector<int>> &islandGrid, int sr, int sc) {
    // When we are out of the grid or grid[i[j] == water
    if(sr < 0 || sr >= islandGrid.size() || sc < 0 || sc >= islandGrid[0].size() ) {
        return 1;
    }
    if(islandGrid[sr][sc] == 2) return 0;
    if (islandGrid[sr][sc] == 0) return 1;
    if(islandGrid[sr][sc] == 1) islandGrid[sr][sc] = 2;
    
    int p1 = islandPerimeterHelper(islandGrid, sr - 1, sc);
    int p2 = islandPerimeterHelper(islandGrid, sr + 1, sc);
    int p3 = islandPerimeterHelper(islandGrid, sr, sc - 1);
    int p4 = islandPerimeterHelper(islandGrid, sr, sc + 1);
    
    return p1 + p2 + p3 + p4;
}
int islandPerimeter(vector<vector<int>>& grid) {
    for(int i = 0; i < grid.size(); i++) {
        for(int j = 0; j < grid[i].size(); j++) {
            if(grid[i][j] == 1) {
                return islandPerimeterHelper(grid,i,j);
            }
        }
    }
    return 0;
}
int main(){





}

