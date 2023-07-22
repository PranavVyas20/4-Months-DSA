#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// [2,3,1,1,4]
// [0]
// [2,0]
// [2,0,0]
// [1,1,1,0]
// [3,0,8,2,0,0,1]

bool jumpGameHelper(vector<int> nums, int idx) {
    int maxReachableIdx = 0;

    for(int i = 0; i < nums.size(); i++) {
        if(i > maxReachableIdx) {
            return false;
        }
        maxReachableIdx = max (i + nums[i], maxReachableIdx);
    }
    return true;
}



int main(){





}

