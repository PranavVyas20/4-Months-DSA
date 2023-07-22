#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int uniquePaths(int m, int n, int srcRow, int srcCol, vector<vector<int>> &visitedBoxes) {
        // Base cases
        if(srcCol >= n || srcRow >= m) 
            return 0;
        
        if(srcRow == m-1 && srcCol == n - 1) 
            return 1;
        
        if(visitedBoxes[srcRow] [srcCol] != -1) 
            return visitedBoxes[srcRow][srcCol];
        
        int res1 = uniquePaths(m, n, srcRow + 1, srcCol, visitedBoxes);
        int res2 = uniquePaths(m, n, srcRow, srcCol + 1, visitedBoxes);

        visitedBoxes[srcRow][srcCol] = res1 + res2;
        
        return res1 + res2;
    }
    
int main(){
    int m = 3;
    int n = 3;
vector<vector<int>> visitedBoxes(m, vector<int>(n, -1));
return uniquePaths(m, n, 0, 0, visitedBoxes);




}

