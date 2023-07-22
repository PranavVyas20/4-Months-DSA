#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Dfs
// If any node is a part of a cycle -
// then its not a safe node (ie it wont lead to a terminal node)
vector<int> result;
bool safeNodesHelper(int node, vector<int> adj[], vector<bool> &vis, vector<bool> &pathVis)
{
    vis[node] = true;
    pathVis[node] = true;

    for (auto adjNode : adj[node])
    {
        if (vis[adjNode] == false)
        {
            bool isPartOfCycle = safeNodesHelper(adjNode, adj, vis, pathVis);
            if (isPartOfCycle == true)
            {
                return true;
            }
        }
        else if (pathVis[adjNode] == true)
        {
            return true;
        }
    }
    result.push_back(node);
    // check[node] = 1(read below for 'WHY')
    pathVis[node] = false;
    return false;
}

vector<int> eventualSafeNodes(vector<vector<int>> &graph)
{
    int n = graph.size();
    int m = graph[0].size();
    vector<int> adj[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < graph[i].size(); j++)
        {
            adj[i].push_back(graph[i][j]);
        }
    }

    vector<bool> vis(n,false);
    vector<bool> pathvis(n,false);

    for(int i = 0; i < graph.size(); i++) {
        if(vis[i] == false) {
            safeNodesHelper(i, adj, vis, pathvis);        
        }
    }
    // To remove this sorting time complexity, another array can be used and 
    // as soon as we figure out than an element is safe node or terminal then 
    // array[node] = 1, and finally all the elements of this array can be transferred to a 
    // final result array. Thus resulting in a sorted final array !!
    sort(result.begin(), result.end());
    return result;
}

int main()
{
}
