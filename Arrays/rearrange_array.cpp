#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> rearrangeArray(vector<int>& nums) {
    // Approach 1:
    vector<int> pos;
    vector<int> neg;
    vector<int> ans;
    int n = nums.size();

    for(auto it : nums) {
        if(it > 0 ) {
            pos.push_back(it);
        } else {
            neg.push_back(it);
        }
    }

    for(int i = 0; i < n / 2; i++) {
        ans.push_back(pos[i]);
        ans.push_back(neg[i]);
    }

    // Approach 2:
    // Slightly better approach - we observer that after rearranging the array all the +ve elements 
    // are on even indices and all the -ve elements are on the odd indices
    int posIdx = 0;
    int negIdx = 1;
    vector<int> ans(nums.size());

    for(int i = 0; i < nums.size(); i++) {
        // If +ve element
        if(nums[i] > 0) {
            ans[posIdx] = nums[i];
            posIdx = posIdx +2;
        }
        // If -ve element 
        else {
            ans[negIdx] = nums[i];
            negIdx = (negIdx + 2);
        }
    }
    return ans;
}
int main(){





}

