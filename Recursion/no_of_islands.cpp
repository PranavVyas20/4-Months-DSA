#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Basically explore every cell to its max and then increment no of islands
int totalIslands = 0;
void numIslandsHelper(vector<vector<char>> &mGrid, int sr, int sc) {
    // Base case here
    if(
        sr < 0 || sr >= mGrid.size() || sc < 0 || sc >= mGrid[0].size()|| mGrid[sr][sc] == '0' || mGrid[sr][sc] == '2') {
        return;
    }

    // If it is '1' then mark it as visited
    if(mGrid[sr][sc] == '1') mGrid[sr][sc] = '2';
    numIslandsHelper(mGrid, sr + 1, sc);
    numIslandsHelper(mGrid, sr - 1, sc);
    numIslandsHelper(mGrid, sr, sc + 1);
    numIslandsHelper(mGrid, sr, sc - 1);
    // Do not increment here because the codee will reach here for neighbour cells too,
    // hence no of islands will be much more than expected ans.
    
}
    int numIslands(vector<vector<char>>& grid) {
        for(int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            // If it is '1' and also not visited ie != '2'
            if(grid[i][j] == '1') {
                numIslandsHelper(grid, i, j);
                // Once exploring is done for a single box, then increment no of islands.
                totalIslands++;
                
            }
        }
    }
    return totalIslands;
    }
int main(){





}


