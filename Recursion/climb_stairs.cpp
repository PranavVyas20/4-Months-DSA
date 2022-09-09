#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// We are on 0th step and want to reach 4th step
// no of ways would be -> no of ways to reach 3rd step + no of ways to reach 2nd step
// Same as fibonacci number 
 int climbStairs(int n, vector<int> &visitedNodes) {
     if(n <= 1) {
        // Not saving for this value of n because its a base case and 
        // hence it wont make further recursive call
            return 1;
        }
        // If we have already made a call for this 'n' value then use the saved value 
        if(visitedNodes[n] != -1) return visitedNodes[n];
        
        int res1 = climbStairs(n - 1, visitedNodes);
        int res2 = climbStairs(n - 2, visitedNodes);
        visitedNodes[n] = res1 + res2;
        return res1 + res2;
    }

    int climbStairs(int n) {
        vector<int> visitedNodes(n + 1, -1);
        return climbStairs(n, visitedNodes);
    }

int main(){
    int n = 4; // nth step that we want to reach from 0;
    vector<int> visitedNodes(n + 1, -1);
    return climbStairs(n, visitedNodes);

}

