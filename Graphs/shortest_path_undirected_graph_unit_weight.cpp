#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Will be doing with plain bfs

void doBfs(int node, vector<bool>& vis, vector<int> adj[], vector<int>& distance) {

}
vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
    // Creating the adj list
    vector<int> adj[N];
    vector<bool> vis(N, false);
    vector<int> distance(N, 1e9);
    distance[src] = 0;

    for(int i = 0; i < edges.size(); i++) {
        vector<int> vectItem = edges[i];
        adj[vectItem[0]].push_back(vectItem[1]);
        adj[vectItem[1]].push_back(vectItem[0]);
    }

    queue<int> q;
    q.push(src);

    while(!q.empty()) {
        int frontNode = q.front();

        for(auto adjNode: adj[frontNode]) {
            if(distance[frontNode] + 1 < distance[adjNode]) {
                distance[adjNode] = distance[frontNode] + 1;
                q.push(adjNode);
            }
        }
    }

    for(int i = 0; i < distance.size(); i++) {
        if(distance[i] == 1e9) {
            distance[i] = -1;
        }
    }

    return distance;
}
int main(){





}

