#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// If any node is a part of a cycle -
// then its not a safe node (ie it wont lead to a terminal node)
bool isPartOfCycle(int node, vector<bool> &vis, vector<bool> &pathVis, vector<vector<int>> &graph) {
    vis[node] = true;
    pathVis[node] = true;

    for(auto adjNode: graph[node]) {
        if(! vis[adjNode]) {
            if(isPartOfCycle(adjNode, vis, pathVis, graph)) return true;
        } else if (vis[adjNode] && pathVis[adjNode]) {
            return true;
        }
    }
    pathVis[node] = false;
    return false;
}

vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    vector<bool> vis(graph.size(), false);
    vector<bool> pathVis(graph.size(), false);
    vector<int> result;
    for(int i = 0; i < graph.size(); i++) {
        if(vis[i] == false) {
            if(isPartOfCycle(i, vis, pathVis, graph) == false) {
                result.push_back(i);
            } 
        }
    }
     sort(result.begin(), result.end());
     return result;
}
int main(){





}

