#include<iostream>
#include<bits/stdc++.h>
using namespace std;


vector<int> doBfs(int V, vector<int> adj[]) {
    vector<int> result;
    vector<int> vis(V, false);
    queue<int> q;

    q.push(0);
    vis[0] = true;

    while(! q.empty()) {
        int frontNode = q.front();
        q.pop();
        result.push_back(frontNode);

        for(auto adjNode: adj[frontNode]) {
            if(vis[adjNode] == false) {
                vis[adjNode] = true;
                q.push(adjNode);
            }
        }
    }
    return result;
}

int main(){





}

