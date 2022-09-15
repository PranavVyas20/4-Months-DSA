#include<iostream>
#include<bits/stdc++.h>
using namespace std;

   vector<vector<int>> ans;
    void comninationSumHelper(vector<int> nums, int idx, int target, vector<int> asf) {
        // Base case
        if(idx == nums.size()) {
            if(target == 0) {
                ans.push_back(asf);
            }
            return;
        }

        if(nums[idx] <= target) {
            asf.push_back(nums[idx]);
            comninationSumHelper(nums, idx, target - nums[idx], asf);
            asf.pop_back();
        }
    comninationSumHelper(nums, idx + 1, target, asf);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> asf;
        comninationSumHelper(candidates, 0, target, asf);
        return ans;
    }

int main(){





}


