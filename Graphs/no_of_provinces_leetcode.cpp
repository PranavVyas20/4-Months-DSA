#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    // using 1 based indexing
void doDfs(int node, vector<int> adjList[], vector<bool> &visitedVector) {
    visitedVector[node] = true;
    for(auto neighbourNode: adjList[node]) {
        if(visitedVector[neighbourNode] == false) {
            doDfs(neighbourNode, adjList, visitedVector);
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int noOfProvinces = 0;
        vector<bool> visitedVector(n + 1, false);
        // Create adjList
        vector<int>adjList[n + 1];
        for(int i = 0; i < n ; i++) {
            for(int j = 0; j < n; j++) {
                if(isConnected[i][j] == 1 && i != j) {
                    adjList[i + 1].push_back(j + 1);
                    adjList[j + 1].push_back(i + 1);
                }
            }
        }
        for(int i = 1; i <= n; i++) {
            if(visitedVector[i] == false) {
                noOfProvinces++;
                doDfs(i, adjList, visitedVector);
            }
        }
        return noOfProvinces;

    }
}
