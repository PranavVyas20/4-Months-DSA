#include<iostream>
#include<bits/stdc++.h>
using namespace std;

    void setRow(vector<vector<int>>& grid, int row) {
        // transform entire row into -1
        for(int i = 0; i < grid[0].size(); i++) {
            grid[row][i] = 0;
        }
    }
    void setCol(vector<vector<int>>& grid, int col) {
        // transform entire col into -1
        for(int i = 0; i < grid.size(); i++) {
            grid[i][col] = 0;
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {
        vector<bool> row(matrix.size(), false);
        vector<bool> col(matrix[0].size(), false);

        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[i].size(); j++) {
                if(matrix[i][j] == 0) {
                    row[i] = true;
                    col[j] = true;
                }
            }
        }

        for(int i = 0; i < row.size(); i++) {
            if(row[i] == true) {
                setRow(matrix, i);
            }
        }

        for(int i = 0; i < col.size(); i++) {
            if(col[i] == true) {
                setCol(matrix, i);
            }
        }
    }