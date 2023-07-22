#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Orange {
    public:
    int row;
    int col;
    int unitTime;
    Orange(int row, int col, int unitTime) {
        this -> row = row;
        this -> col = col;
        this -> unitTime = unitTime;
    }
};

int orangesRotting(vector<vector<int>> & grid) {
    int r = grid.size(); 
    int c = grid[0].size();

    bool visited[r][c];

    int dRow[] = {-1, 0, 1, 0};

    int dCol[] = {0, 1, 0, -1};

    queue<Orange> q;

    int time = 0;
    int totalFreshOranges = 0;
    int freshOrangsRotten = 0;

    // Pushing iniital values in the queue ie - initial rotten oranges
    for(int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            // Found a rotten orange
            if(grid[i][j] == 2) {
                Orange orange = Orange(i , j, time);
                q.push(orange);
                visited[i][j] = true;
            } else {
                if(grid[i][j] == 1) {
                    totalFreshOranges++;
            }
                visited[i][j] = false;
            }
        }
    }

    while(!q.empty()) {
        // Take the front element
        Orange frontOrange = q.front();
        int frontOrangeTime = frontOrange.unitTime;
        time = frontOrangeTime;
        q.pop();

        // Now check the neigbours of the front neighbours
        for(int i = 0; i < 4; i++) {
            int nextRow = frontOrange.row + dRow[i];
            int nextCol = frontOrange.col + dCol[i];
            // Check if we can rot the orange at [nextRow][nextCol]
            if(nextRow >= 0 && nextRow < r && nextCol >= 0 && nextCol < c 
            && grid[nextRow][nextCol] == 1 && visited[nextRow][nextCol] == false) {
                // Rot the orange and mark visited 
                visited[nextRow][nextCol] = true;
                freshOrangsRotten ++;
                // add to to the queue
                q.push(Orange(nextRow, nextCol, frontOrangeTime));
            }
        }

    }
    if(totalFreshOranges != freshOrangsRotten) {
        return -1;
    } else {
        return time;
    }
}
int main(){
vector<vector<int>> grid = {{2,1,1},{0,1,1},{1,0,1}};
cout << orangesRotting(grid);
}

