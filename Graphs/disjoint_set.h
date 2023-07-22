#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*
Custom graph-like data structure that has constant TC for operations like:
1. Finding wether 2 nodes belong to the same connected component or not
2. Dynamic graph (graph that keeps changing) it can do operation 1 in constant TC
*/

class DisjointSet {
    private:
    vector<int> rank, parent;

    public:
    vector<int> size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for(int i = 0; i < parent.size(); i++) {
            parent[i] = i;
        }
    }

    int findUltimateParent(int node) {
        // if node is self parent the return that node
        if(parent[node] == node) return node;
        // finds the ultimate and compresses the path as well
        return parent[node] = findUltimateParent(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ultParentU = findUltimateParent(u);
        int ultParentV = findUltimateParent(v);

        // if u and v have same ultimate parent, it means they are already in the same component
        if(ultParentU == ultParentV) return;

        // connect the ultimate parent of the smaller rank node beneath 
        // the ultimate parent of the greater rank
        if(rank[ultParentU] < rank[ultParentV]) {
            parent[ultParentU] = ultParentV;
        } 
        else if(rank[ultParentV] < rank[ultParentU]) {
            parent[ultParentV] = ultParentU;
        } 
        else {
            // ranks are equal
            parent[ultParentV] = ultParentU;
            // increase the rank by one
            rank[ultParentU]++;
        }
    }

    void unionBySize(int u, int v) {
        int ultParent_u = findUltimateParent(u);
        int ultParent_v = findUltimateParent(v);

        if(ultParent_u == ultParent_v) return;

        if(size[ultParent_u] > size[ultParent_v]) {
            parent[ultParent_v] = ultParent_u;
            size[ultParent_u] += size[ultParent_v];
        }
        else {
            parent[ultParent_u] = ultParent_v;
            size[ultParent_v] += size[ultParent_u];
        }
    }
    
};


