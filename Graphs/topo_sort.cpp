#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void doDfs(int node, vector<bool>& vis, vector<vector<int>> graph, stack<int> st) {
    vis[node] = true;

    for(auto adjNode: graph[node]) {
        if(vis[adjNode] == false) {
            doDfs(adjNode, vis, graph, st);
        }
    }
    st.push(node);
}


vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int nodes) {
    // Write your code here!
    stack<int> st;
    vector<bool>vis(graph.size(), false);
    vector<int> ans;

    for(int i = 0; i < graph.size(); i++) {
        if(vis[i] == false) {
            doDfs(i, vis, graph, st);
        }
    }
    while(! st.empty() ) {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}
int main(){





}

