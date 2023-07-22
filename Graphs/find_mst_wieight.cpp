#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int minimumSpanningTree(vector<vector<int>>& edges, int n) {
    // Create the adjlist
    vector<pair<int, int>>adjList[n];
    for(auto vec: edges) {
        int u = vec[0];
        int v = vec[1];
        int weight = vec[2];

        adjList[u].push_back({v, weight});
        adjList[v].push_back({u, weight});
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;

    vector<bool> vis(n, false);
    
    int mstWeight = 0;

    // {weight, node}
    pq.push( {0, 0} );

    // do no mark node 0 as visited now !!

    while(! pq.empty()) {
        int frontNode = pq.top().second;
        int weight = pq.top().first;
        pq.pop();

        if(vis[frontNode]) continue;

        vis[frontNode] = true;
        mstWeight += weight;

        for(auto adjNodePair: adjList[frontNode]) {
            int adjNode = adjNodePair.first;
            int adjNodeWeight = adjNodePair.second;

            if(vis[adjNode] == false) {
                pq.push({adjNodeWeight, adjNode});
            }
        }
    }
    return mstWeight;
}

int main(){





}

