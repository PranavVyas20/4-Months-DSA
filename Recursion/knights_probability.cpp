#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dir = { {-2, -1}, {-1, -2}, {1,-2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1} };

double knightProbability(int n, int k, int row, int column) {
    // Base cases
    // Out of grid
    // If no of moves becomes zero
    // If the box is already visited
    if(row < 0 || column < 0 || row >= n || column >= n) {
        return 0.0;
    }       
    if(k == 0) {
        return 1.0;
    }
    double probability = 0.0;
    // Explore in every 8 directions and sum all the probabilities
    // Dividing by eight because eight moves are there that the knight can make
    for(int i = 0; i < dir.size(); i++) {
        probability += knightProbability(n, k - 1, row + dir[i][0], column + dir[i][1]) / 8;
    }
    return probability;
}
int main(){





}

