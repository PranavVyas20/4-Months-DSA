#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Space complexity = 
// Time complexity = 
void dfsGraph(int node, const vector<int> adjList[], vector<int> &visited) {
    cout << node << endl;
    visited[node] = 1;
    // Traverse all the neighbour of the 'node' if not visited already
    for(auto neighbour : adjList[node]) {
        if(visited[neighbour] == 0) {
            dfsGraph(neighbour, adjList, visited);
        }
    }
}
int main(){
vector<int> adjList[9] = { 
    {},
    {2, 3},
    {1, 5, 6},
    {1, 4, 7},
    {3, 8},
    {2},
    {2},
    {3, 8},
    {4, 7}
};
vector<int> visited(9,0);
dfsGraph(1, adjList, visited);
}

