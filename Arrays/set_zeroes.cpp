#include<iostream>
#include<bits/stdc++.h>
using namespace std;

    void makeRowZero(int row, vector<vector<int>>& grid) {
        for(int i = 0; i < grid[0].size(); i++) {
            grid[row][i] = 0;
        }
    }

    void makeColZero(int col, vector<vector<int>>& grid) {
        for(int i = 0; i < grid.size(); i++) {
            grid[i][col] = 0;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int, int>> dp;
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                if(matrix[i][j] == 0) {
                    dp.push_back({i, j});
                }
            }
        }

        for(auto it: dp) {
            makeRowZero(it.first, matrix);
            makeColZero(it.second, matrix);
        }
    }