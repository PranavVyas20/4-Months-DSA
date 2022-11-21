#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Can be solved through topo sort(dfs/bfs)
// Step 1 - Create a directed graph from the list<word>
// Step 2 - Do topo sort on the directed graph formed

// dict = {"baa","abcd","abca","cab","cad"}

void topoSortHelperDfs(int node, vector<bool>& vis, vector<int> adj[], stack<int>& st) {
    vis[node] = true;

    for(auto adjNode: adj[node]) {
        if(vis[adjNode] == false) {
            topoSortHelperDfs(adjNode, vis, adj, st);
        }
    }
    st.push(node);
}

string findOrder(string dict[], int N, int K) {
    vector<int> adj[K];
    vector<bool> vis(K, false);
    stack<int> st;

// Creating graph from the dict
    for(int i = 0; i < N; i++) {
        string word1 = dict[i];
        string word2 = dict[i + 1];

        int len = min(word1.size(), word2.size());
        for(int charIdx = 0; charIdx < len; charIdx++) {
            if(word1[charIdx] != word2[charIdx]) {
                adj[word1[charIdx] - 'a'].push_back(word2[charIdx] - 'a');
                cout << adj[word1[charIdx] - 'a'] << " " << adj[word2[charIdx] - 'a'];
                break;
            }
        }
        
        for(auto it: adj) {
            for(auto ch: it) {
                cout << ch;
            }
            cout << endl;
        }
    }
    
    topoSortHelperDfs(0, vis, adj, st);

    // Apply toposort
    string result = "";
    while(!st.empty()) {
        char ch = st.top() + 'a';
        st.pop();
        result += ch;
    }
    return result;
}
int main(){
string dict[] = {"caa","aaa","aab"};
cout << findOrder(dict, 3, 3);



}

