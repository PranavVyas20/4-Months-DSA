#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Finding shortest distance from a source node
// Using dijkstra's algorith (implemented using set)
// Difference between implementing it with priority que vs set:
// In priority queue - we cannot erase an element if we have found a better
// distance for the same node.
// Where as in a set we can do that
// But time complexity wise there wont be much of a difference because
// erase fun take logrithmic time but would save some future iterations
// It depends on the graphs size
// So in a nutshell there is not much of a difference wrt complexity
// CLean BFS thats all

vector<int> dijfkstraUsingSet(int V, vector<vector<int>> adj[], int S) {
    // pair<distance, node>
    set<pair<int, int>> st;
    vector<int> distances(V, 1e9);
    distances[S] = 0;

    st.insert(make_pair(0, S));

    while(!st.empty()) {
        auto topPair = *(st.begin());
        int topNode = topPair.second;
        int topNodeDistance = topPair.first;
        // remove from the set
        st.erase(topPair);

        for(auto adjPair: adj[topNode]) {
            int adjNode = adjPair[0];
            int edgeWeight = adjPair[1];

            if(topNodeDistance + edgeWeight < distances[adjNode]) {
                if(distances[adjNode] != 1e9) {
                    // Remove the node if we find a better (smaller) rasta!
                    st.erase(make_pair(distances[adjNode], adjNode));
                }
                distances[adjNode] = topNodeDistance + edgeWeight;
                // Insert new better(smaller) rasta in set
                st.insert(make_pair(distances[adjNode], adjNode));
            }
        }
    }
    return distances;
}
int main(){





}





























































































































































