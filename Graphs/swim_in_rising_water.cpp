#include<iostream>
#include<bits/stdc++.h>
using namespace std;

    bool isValid(int row, int col, int n) {
    return (row >= 0 and row < n and col >= 0 and col < n);
}
int swimInWater(vector<vector<int>>& grid) {
    int n = grid.size();
    
    // priority queue < vector {maxElevatedHeight, row, col} >
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;

    vector<vector<bool>> vis(n, vector<bool>(n, false));

    vis[0][0] = true;

    pq.push({grid[0][0], 0, 0});

    int xDir[4] = {-1, 0, 1, 0};
    int yDir[4] = {0, 1, 0, -1};

    while(! pq.empty()) {
        int topMaxElevationHeight = pq.top()[0];
        int topRow = pq.top()[1];
        int topCol = pq.top()[2];

        pq.pop();

        if(topRow == n - 1 and topCol == n -1) return topMaxElevationHeight;

        for(int i = 0; i < 4; i++) {
            int nextRow = topRow + xDir[i];
            int nextCol = topCol + yDir[i];

            if(isValid(nextRow, nextCol, n) and vis[nextRow][nextCol] == false) {
                vis[nextRow][nextCol] = true;
                int maxElevatedHeight = max(topMaxElevationHeight, grid[nextRow][nextCol]);
                pq.push( {maxElevatedHeight, nextRow, nextCol} );
            }
        }
    }
    return 0;
}


