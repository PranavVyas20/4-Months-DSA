#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Approach 1 - Detect if the graph contain a cycle (DFS)
// it it does then topo sort cannot be applied -> nodes cant places linearly
// hence we cannot fininsh

// Approach 2 - Apply topo sort and check if the final result array size
// is equal to no of nodes, yes -> topo sort possible hence canFinish 
// if final result array size < no of nodes -> topo sort not possible
// therefore cannotFinish
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    // Create adjacency list
    int n = numCourses;
    vector<int> adj[n];

    // Very smart code, smirk huhh
    for(auto adjNodes: prerequisites) {
        adj[adjNodes[0]].push_back(adjNodes[1]);
    }

    // Now check for toposort
    vector<int> indegrees(n, 0);
    vector<int> topoSortResult;
    queue<int> q;

    // Filling the indegrees array
    for(int i = 0; i < n; i++) {
        for(auto adjNode: adj[i]) {
            indegrees[adjNode]++;
        }
    }

    // Pushing all the elements with indegree == 0 in the queue
    for(int i = 0; i < n; i++) {
        if(indegrees[i] == 0) {
            q.push(i);
        }
    }

    // BFS
    while(!q.empty()) {
        int frontNode = q.front();
        topoSortResult.push_back(frontNode);
        q.pop();

        for(auto adjNode: adj[frontNode]) {
            // Cut off edge
            indegrees[adjNode] --;
            if(indegrees[adjNode] == 0) {
                // If edges becomes 0, then push in the queue
                q.push(adjNode);
            }
        }
    }
    if(topoSortResult.size() == n) {
        return true;
    }
    return false;

}
int main(){





}

