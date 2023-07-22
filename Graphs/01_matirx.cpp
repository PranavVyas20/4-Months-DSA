#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int row;
    int col;
    int distance;
    Node(int row, int col, int distance) {
        this -> row = row;
        this -> col = col;
        this -> distance = distance;
    }
};
vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    vector<vector<int>> vis(mat.size(), vector<int>(mat[0].size(), false));
    queue<Node> q;
    int n = mat.size();
    int m = mat[0].size();
    
    for(int i = 0; i < mat.size(); i++) {
        for(int j = 0; j < mat[i].size(); j++) {
            if(mat[i][j] == 0) {
                q.push( Node(i, j, 0));
                vis[i][j] = true;
            }
        }
    }
    vector<int> dirX = {-1, 0, 1, 0};
    vector<int> dirY = {0, -1, 0, 1};

    while(!q.empty()) {
        Node frontNode = q.front();
        q.pop();

        // go in all the four directions
        for(int i = 0; i < 4; i++) {
            int nextRow = frontNode.row + dirX[i];
            int nextCol = frontNode.col + dirY[i];

            if(nextRow >= 0 && nextRow < n && nextCol >= 0 && nextCol < m 
                && mat[nextRow][nextCol] == 1 && vis[nextRow][nextCol] == false) {
                    vis[nextRow][nextCol] = true;
                    q.push( Node( nextRow, nextCol, frontNode.distance + 1));
                    mat[nextRow][nextCol] = frontNode.distance + 1;
                }
        }
    }
    return mat;
}
int main(){





}

