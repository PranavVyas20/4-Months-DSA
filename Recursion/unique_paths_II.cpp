#include<iostream>
#include<bits/stdc++.h>
 using namespace std;

 // Clean up the code and optimize space complexity !!
    int uniquePathsHelper(int m, int n, int srcRow, int srcCol, vector<vector<int>> &visitedBoxes, vector<vector<int>> obstacleGrid) {
        // Base cases
        if(srcCol >= n || srcRow >= m || obstacleGrid[srcRow][srcCol] == 1) {
            return 0;
        }
        if(srcRow == m-1 && srcCol == n - 1) 
            return 1;
         
        if(visitedBoxes[srcRow] [srcCol] != -1) 
            return visitedBoxes[srcRow][srcCol];
        
        int res1 = uniquePathsHelper(m, n, srcRow + 1, srcCol, visitedBoxes, obstacleGrid);
        int res2 = uniquePathsHelper(m, n, srcRow, srcCol + 1, visitedBoxes, obstacleGrid);
        visitedBoxes[srcRow][srcCol] = res1 + res2;
        
        return res1 + res2;
    }
    // Leetcode function to be run by compiler
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        vector<vector<int>> visitedBoxes(m, vector<int>(obstacleGrid[0].size(), -1));
        return uniquePathsHelper(m, obstacleGrid[0].size(), 0, 0, visitedBoxes, obstacleGrid);
    }
int main(){





}

