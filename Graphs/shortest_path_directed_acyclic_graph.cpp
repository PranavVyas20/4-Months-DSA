#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Change this green color !!!!!
void shortestPathHelper(int node, int edgeWeight, int parentWeight, vector<int>& distances, vector<pair<int, int>> adj[]) {
    if(node != 0) {
        int newWeight = edgeWeight + parentWeight;
        if(distances[node] == 0) {
            distances[node] = min(newWeight, distances[node]);
        } else {
            distances[node] = newWeight;
        }
    }

    for(auto adjNodePair: adj[node]) {
        shortestPathHelper(adjNodePair.first, adjNodePair.second, distances[node], distances, adj);
    }
}

void shortestPathHelperTopoSort(int node, stack<int>& st, vector<bool>& vis, vector<pair<int,int>> adj[]) {
    vis[node] = true;

    for(auto adjNode: adj[node]) {
        if(vis[adjNode.first] == false) {
            // .first -> node
            // .second -> weight
            shortestPathHelperTopoSort(adjNode.first, st, vis, adj);
        }
    }
    st.push(node);
}
vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // Create adjacency list
        // Pair<node, weight>
        vector<pair<int,int>> adj[N];
        vector<bool> vis(N, false);
        vector<int> distance(N, 0);
        stack<int> st;
        
        // Creating adj list here
        for(int i = 0; i < M; i++) {
            vector<int> edge = edges[i];
            int fromEdge = edge[0];
            int toEdge = edge[1];
            int edgeWeight = edge[2];

            adj[fromEdge].push_back(make_pair(toEdge, edgeWeight));
            cout << fromEdge << " -> " << "pair<" << toEdge << "," << edgeWeight << ">" << endl;
        }

        for(int i = 0; i < N; i++) {
            if(vis[i] == false) {
                shortestPathHelperTopoSort(i, st, vis, adj);
            }
        }

        // Now calculate the distances
        vector<int> distance(N, INT_MAX);
        // make distance[srcNode] = 0 (in this case source node is 0) 
        distance[0] = 0;
        while(!st.empty()) {
            int topNode = st.top();
            st.pop();

            for(auto adjNodePair: adj[topNode]) {
                int adjNode = adjNodePair.first;
                int weight = adjNodePair.second;

                if(distance[topNode] + weight < distance[adjNode]) {
                    distance[adjNode] = distance[topNode] + weight;
                }
            }
        }

        for(int i = 0; i < distance.size(); i++) {
            if(distance[i] == INT_MAX) {
                distance[i] = -1;
            }
        }


        // shortestPathHelper(0, 0, 0, distance, adj);

        // for(int i = 0; i < distance.size(); i++) {
        //     if(distance[i] == 0) {
        //         distance[i] = -1;
        //     }
        // }
        return distance;
}
int main(){

}

