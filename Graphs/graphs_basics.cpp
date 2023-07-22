#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void bfsOfGraph(int n, vector<int> adjList[]) {
    // Assuming the graph is 0base index
    vector<int> visited(n, 0);
    queue<int> q;
    // Push the first node ie 0
    q.push(0);
    while(!q.empty()) {
        // Get the first element of the queue
        int front = q.front();
        // Print / store the element 
        cout << front << endl;
        // Remove the element from the queue
        q.pop();
        // Add its children to the queue, if not already visited
        // basically looping over the neighbours (vector) of a node (frontNode)
        // 1: [2,3]
        // 2: [3,4,5] ....
        for(auto neighbour : adjList[front]) {
            // Checking if already visited 
            if(visited[neighbour] == 0) {
                visited[neighbour] = 1;
                q.push(neighbour);
            }
        }
    }
    
}
int main(){
int arr[2];
cout << sizeof(arr)/ 4;



}

