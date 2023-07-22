#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// A graph is said to be bipartite if you can color every adjacent node with
// opposite color

// BFS
bool bipartiteHelper(int startNode, vector<int>& colored, vector<vector<int>>& graph) {
    int noColor = -1;
    int colorZero = 0;
    int colorOne = 1;
    queue<int> q;
    q.push(startNode);
    colored[startNode] = colorZero;

    while(!q.empty()) {
        int frontNode = q.front();
        q.pop();

        for(auto adjNode: graph[frontNode]) {
            // Color the adjNode with opposite color
            if(colored[adjNode] == noColor) {
                if(colored[frontNode] == colorOne) {
                    colored[adjNode] = colorZero;
                } else {
                    colored[adjNode] = colorOne;
                }
                q.push(adjNode);
            } else if(colored[adjNode] == colored[frontNode]) {
                return false;
            }
        }
    }   
    return true;
}

// dfs 
bool bipartiteHelperDfs(int node, vector<vector<int>>& graph, vector<int>& colored) {
    int colorOne = 1;
    int colorZero = 0;
    int noColor = -1;
    // For first time only
    if(colored[node] == noColor) {
        colored[node] = colorOne;
    }

    for(auto adjNode: graph[node]) {
        // Color the adjNode with opposite color
        if(colored[adjNode] == noColor) {
                if(colored[node] == colorOne) {
                    colored[adjNode] = colorZero;
                } else {
                    colored[adjNode] = colorOne;
                }
            // called dfs on adjNode and if that node returns false 
            //then return false as the graph is not bipartite
            // If returned true, then continue dfs
            bool ans = bipartiteHelperDfs(adjNode, graph, colored);
            if(ans == false) {
                return false;
            }
        } else if(colored[adjNode] == colored[node]) {
            return false;
        }
    }
    return true;
}
bool isBipartite(vector<vector<int>>& graph) {
    int noColor = -1;
    int colorZero = 0;
    int colorOne = 1;
    vector<int> colored(graph.size(), noColor);

    // If there are connected components:
    // If any of the connected components is not bipartite, then the whole graph is
    // not bipartite
    // But for a graph to be bipartite, every component should be bipartite
    for(int i = 0; i < graph.size(); i++) {
        if(colored[i] == noColor) {
            if(bipartiteHelper(i, colored, graph) == false) {
                return false;
            }
        }
    }
    return true;
}
int main(){





}

