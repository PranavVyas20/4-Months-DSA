#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Basically toposort BFS
// Need to use indegree of nodes

vector<int> topoSort(int V, vector<int> adj[]) {
    vector<int> result;
    queue<int> q;
    vector<int> indegrees(V, 0);

    // Create indegrees array( indegree[rhs]++ )
    // 0 -> {}
    // 1 -> {}
    // 2 -> {3}
    // 3 -> {1}
    // 4 -> {0, 1}
    // 5 -> {0, 2}

    for(int i = 0; i < V; i++) {
        for(int adjNode: adj[i]) {
            indegrees[adjNode]++;
        }
    }

    // Pushing all nodes with indegree 0 in the queue
    for(int i = 0; i < V; i++) {
        if(indegrees[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        int frontNode = q.front();
        result.push_back(frontNode);
        q.pop();

        for(int adjNode: adj[frontNode]) {
            // Start cutting edges from adjNodes
            indegrees[adjNode]--;
            if(indegrees[adjNode] == 0) {
                // If the indegree of a node becomes 0, push it in the queue
                q.push(adjNode);
            }
        }
    }

    return result;
}
int main(){





}

