#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Finding shortest distance from a source node
// Using dijkstra's algorith (implemented using priority queue == min_heap)
// CLean BFS thats all
class Pair{
    public:
    int node;
    int weight;
    Pair(int node, int weight) {
        this -> node = node;
        this -> weight = weight;
    }
};
vector <int> dijkstra(int V, vector<vector<int>> adj[], int S) {
    vector<int> distances(V, 1e9);
    // Distance of src node from itself would be 0!
    distances[S] = 0;
    // This is a max heap !!!
    priority_queue<pair<int, int>> pq;

    pq.push(make_pair(S, 0));

    while(!pq.empty()) {
        int frontNode = pq.top().first;
        int frontNodeWeight = pq.top().second;
        pq.pop();

        for(auto adjPair: adj[frontNode]) {
            int adjNode = adjPair[0];
            int edgeWeight = adjPair[1];

            if(frontNodeWeight + edgeWeight < distances[adjNode]) {
                distances[adjNode] = frontNodeWeight + edgeWeight;
                pq.push(make_pair(adjNode, distances[adjNode]));
            }
        }

    }
    return distances;
}
int main(){





}

