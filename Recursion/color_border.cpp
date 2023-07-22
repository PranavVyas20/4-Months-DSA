#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void colorBorderHelper(vector<vector<int>> &grid, int &reqItem, int row, int col, int &color) {
    // Base cases
    if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size()) {
        return;
    }
    if(grid[row][col] != reqItem){
    cout << "returned " << "row: " << row << " col: " << col << " item: " << grid[row][col] << endl;
        return;
    }
    grid[row][col] = color;
        
    colorBorderHelper(grid, reqItem, row + 1, col, color);
    colorBorderHelper(grid, reqItem, row - 1, col, color);
    colorBorderHelper(grid, reqItem, row, col - 1, color);
    colorBorderHelper(grid, reqItem, row, col + 1, color);
}

// vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
//     int reqItem = grid[row][col];
    
//     for(int i = 0; i < grid.size(); i++) {
//         for(int j = 0; j < grid[i].size(); j++) {
//             if(grid[i][j] == reqItem)
//                 colorBorderHelper(grid, reqItem, i, j, color);
//         }
//     }
//     return grid;
// }

int main(){
vector<vector<int>> grid = { {1,2,2}, {2,3,2} };
int reqItem = grid[0][1];
int color = 3;
    
for(int i = 0; i < grid.size(); i++) {
    for(int j = 0; j < grid[i].size(); j++) {
        if(grid[i][j] == reqItem)
            colorBorderHelper(grid, reqItem, i, j, color);
    }
}



}

