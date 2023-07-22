#include<iostream>
#include<bits/stdc++.h>
using namespace std;


bool isCycleHelper(int node, int parent, vector<bool> &vis, vector<int> adj[]) {
    vis[node] = true;

    for(auto neighbour: adj[node]) {
        if(!vis[neighbour]) {
            if(isCycleHelper(neighbour, node, vis, adj)) {
                return true;
            }
        }
        else if(neighbour != parent) {
            return true;
        }
    }
    return false;
}


bool isCycle(int V, vector<int> adj[]) {
    vector<bool> vis(V, false);
    for(int i = 0; i < V; i++) {
        if(!vis[i]) {
            if(isCycleHelper(i, -1, vis, adj)) {
                return true;
            }
        }
    }
    return false;
}
int main(){





}


