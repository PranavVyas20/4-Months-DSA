#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> visited(V,0);
        vector<int> vec;
        return dfs(0,adj,visited,vec);
        
    }
    
    vector<int> dfs(int s,vector<int> adj[],vector<int> &visited,vector<int> &vec){
        visited[s] = true;
        vec.push_back(s);
        for(auto x : adj[s]){
            if(!visited[x]) dfs(x,adj,visited,vec);
        }
        
        return vec;
    }

int main()
{
    int a;
    cin >> a;
    cout << a + 10;
}
