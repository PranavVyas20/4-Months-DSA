#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Basically count the no of connected components
void dfs(int node, vector<int> adjList[], vector<bool> visited) {
    visited[node] = true;
    for (auto neighbour: adjList[node]) {
        if (!visited[neighbour]) {
            dfs(neighbour, adjList, visited);
        }
    }
}
int findCircleNum(vector<vector<int>>& isConnected) {
    // Create the adjList
    int n = isConnected.size();
    vector<bool> visited(n,false);
    vector<int> adjList[n];
    
    for(int i = 0; i < isConnected.size(); i++) {
        for(int j = 0; j < isConnected[i].size(); j++) {
            adjList[i].push_back(j);
            adjList[j].push_back(i);
        }
    }

    // Run loop on all nodes
    int componentsCount = 0; 
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            dfs(i, adjList, visited);
            componentsCount++;
        }
    }
    return componentsCount;
}
int main(){





}

