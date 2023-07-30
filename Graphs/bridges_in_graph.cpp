#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void doDfs(
    int node, 
    int time,
    int parent, 
    vector<bool>& vis, 
    vector<int>& dis, 
    vector<int>& lowestReachableVertices, 
    vector<int> adj[],
    vector<vector<int>>& bridges 
) {
    vis[node] = true;
    dis[node] = lowestReachableVertices[node] = time;

    for(auto adjNode: adj[node]) {
        if(adjNode == parent) continue;

        else if( vis[adjNode] == false) {

            doDfs(adjNode, time + 1, node, vis, dis, lowestReachableVertices, adj, bridges);

            // upate the lowestReachable vertex of node
            lowestReachableVertices[node] = min(lowestReachableVertices[node], lowestReachableVertices[adjNode]);

            // check if the node is a articulation point
            if(lowestReachableVertices[adjNode] > lowestReachableVertices[node] ) {
                bridges.push_back({adjNode, node});
            }
        }
        // Back edge
        else {
            lowestReachableVertices[adjNode] = min(lowestReachableVertices[adjNode], dis[node]);
        }
    }
}
vector<vector<int>> articulationPoints(int V, vector<int>adj[]) {
    vector<bool> vis(V, false);
    vector<int> dis(V, 0);
    vector<int> lowestReachableVertices(V, 0);
    vector<vector<int>> bridges;

    doDfs(0, 0, -1, vis, dis, lowestReachableVertices, adj, bridges);

    return bridges;
}


