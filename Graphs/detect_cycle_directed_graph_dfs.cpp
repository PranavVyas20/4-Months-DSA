#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// A directed graph is cyclic if it visits a node again in the same path !!
bool isCyclicHelper(int node, vector<int>& vis, vector<int>& pathVisited, vector<int> adj[]) {
    vis[node] = 1;
    pathVisited[node] = 1;

    for(auto adjNode: adj[node]) {
        // If not visited
        if(vis[adjNode] == 0) {
            bool ans = isCyclicHelper(adjNode, vis, pathVisited, adj);

            if(ans == true) {
                return true;
            }
        }
        // Main thing !!
        // Already visited but not from the same path
        else if(vis[adjNode] == 1 && pathVisited[adjNode] == 1) {
        return true;
    }
    }
    pathVisited[node] = 0;
    return false;
}

bool isCyclic(int V, vector<int> adj[]) {
    vector<int> vis(V, 0);
    vector<int> pathVisited(V, 0);
    for(int i = 0; i < V; i++) {
        if(vis[i] == 0) {
            if(isCyclicHelper(i, vis, pathVisited, adj)) {
                return true;
            }
        }
    }
    return false;
}
int main(){





}

