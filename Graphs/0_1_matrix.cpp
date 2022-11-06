#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Its a good question, dimak khol dega bidu-
// Using BFS

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
    queue<Node> q;

    int m = mat.size();
    int n = mat[0].size();

    vector<int> dRow = {-1, 0, 1, 0};
    vector<int> dCol = {0, -1, 0, 1};

    vector<vector<int>> result(m, vector<int>(n, 0));
    vector<vector<int>> vis(m, vector<int>(n, 0));


    for(int i = 0; i < mat.size(); i++) {

        for(int j = 0; j < mat[i].size(); j++) {
            if(mat[i][j] == 0) {
                q.push(Node(i, j, 0));
                vis[i][j] = 1;
                result[i][j] = 0;
            } 
        }
    }

    while(!q.empty()) {
        Node frontNode = q.front();
        q.pop();
        result[frontNode.row][frontNode.col] = frontNode.distance;

        // Now check for 4 directions
        for(int i = 0; i < 4; i++) {
            int nextRowToCheck = frontNode.row + dRow[i];
            int nextColtoCheck = frontNode.col + dCol[i];
            int nextDistance = frontNode.distance;

            if(nextRowToCheck >= 0 && nextRowToCheck < m &&
               nextColtoCheck >= 0 && nextColtoCheck < n &&
               vis[nextRowToCheck][nextColtoCheck] == 0
            ) {
                q.push(Node(nextRowToCheck, nextColtoCheck, nextDistance + 1));
                vis[nextRowToCheck][nextColtoCheck] = 1;
            }
        }
    }
}
int main(){





}

