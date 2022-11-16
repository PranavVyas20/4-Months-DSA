#include<iostream>
#include<bits/stdc++.h>
using namespace std;


// When a node completes dfs calls for its adjNodes, push it in stack
// Only valid for DAG (Directed Acyclic Graph)
void topoSortHelper(int node, vector<bool>& vis, vector<int> adj[], stack<int>& st) {
    vis[node] = true;

    for(auto adjNode: adj[node]) {
        if(vis[adjNode] == false) {
            topoSortHelper(adjNode, vis, adj, st);
        }
    }
    st.push(node);
}

vector<int> topoSort(int V, vector<int> adj[]) {
    vector<bool> vis(V, false);
    stack<int> st;
    vector<int> result;

    for(int i = 0; i < V; i++) {
        if(vis[i] == false) {
            topoSortHelper(i, vis, adj, st);
        }
    }

    while( !st.empty()) {
        result.push_back(st.top());
        st.pop();
    }
    return result;
}

int main(){




}


