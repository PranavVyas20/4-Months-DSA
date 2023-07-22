#include<bits/stdc++.h>
#include<iostream>
using namespace std;

vector<vector<int>> getSubsetsHelper(vector<int> &nums,int idx){
    if(idx == nums.size()){
        return { { } };
    }

    vector<vector<int>> subAns = getSubsetsHelper(nums,idx + 1);
    vector<vector<int>> ansVector;

    for (int i = 0; i < subAns.size(); i++) {
        ansVector.push_back (subAns [i]);
        subAns[i].push_back(nums[idx]);
        ansVector.push_back (subAns [i]);
    }
    return ansVector;
}

// Method 2 - Travel and solve
vector<vector<int>> ans;
void genSubsequence(vector<int> &nums, vector<int> asf, int idx) {
    // Because empty [] is also a part of the subset
    ans.push_back(asf);
    
    for(int i = idx; i < nums.size(); i++) {
       asf.push_back(nums[i]);
       genSubsequence(nums, asf, i + 1);
       asf.pop_back();
    }
}

int main(){

vector<int> ip = {1,2,3};
vector<vector<int>> ans = getSubsetsHelper(ip,0);

}

