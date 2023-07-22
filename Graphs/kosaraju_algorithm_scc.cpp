#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void addToStackDfs(int node, vector<vector<int>>& adj, vector<bool>& vis, stack<int>& st) {
   vis[node] = true;

   for(auto adjNode: adj[node]) {
        if(vis[adjNode] == false) {
            addToStackDfs(adjNode, adj, vis, st);
        }
    }
    st.push(node);
}

void doDfs(int node, vector<int> adj[], vector<bool>& vis) {
vis[node] = true;

   for(auto adjNode: adj[node]) {
        if(vis[adjNode] == false) {
            doDfs(adjNode, adj, vis);
        }
    }
}


int kosaraju(int V, vector<vector<int>>& adj) {
        vector<bool> vis(V, false);
        stack<int> st;

        // sort the nodes(basically toposort)
        addToStackDfs(0, adj, vis, st);

        vis.resize(V, false);
        
        // reverse the graph
        vector<int> reversedAdj[V];
        for(int i = 0; i < adj.size(); i++) {
            for(auto it : adj[i]) {
                reversedAdj[it].push_back(i);
            }
        }

        // Do plain dfs
        int sccCount = 0;
        while( ! st.empty() ) {
            int node = st.top();
            st.pop();

            if(vis[node] == false) {
                doDfs(node, reversedAdj, vis);
                sccCount++;
            } 
        }
}

