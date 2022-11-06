#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isCycleHelper(int node, vector<int> adjList[], vector<bool> &vis) {
    // pair< node, parent >
    queue<pair<int, int>> q;
    // Pushing the first node ie - 0 (can be 1 as well depends on the question
    // and its parent ie -1 for the first node
    q.push({node, -1});

    while(!q.empty()) {
        int node = q.front().first;
        int nodeParent = q.front().second;
        q.pop();
        vis[node] = true;

        for(auto neighbour: adjList[node]) {
            // if node already visited
            if(vis[neighbour]) {
                // visited but not my parent, hence its a cycle
                if(nodeParent != neighbour) {
                    return true;
                }
            } else {
                q.push( { neighbour, node } );
            }
        }

    }
    return false;
}

bool isCycle(int V, vector<int> adj[]) {
    vector<bool> vis(V, false);
    for(int i = 0; i < V; i++) {
        if(!vis[i]) {
            if(isCycleHelper(i, adj, vis)) {
                return true;
            }
        }
    }
    return false;
}



int main(){





}

