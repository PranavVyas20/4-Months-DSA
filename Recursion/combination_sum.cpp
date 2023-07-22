#include<iostream>
#include<bits/stdc++.h>
using namespace std;

   vector<vector<int>> ans;
    void comninationSumHelper(vector<int> nums, int idx, int target, vector<int> asf) {
        // Base case
        if(target == 0) {
            ans.push_back(asf);
            return;
        }
        for(int i = idx; i < nums.size(); i++) {
          if(nums[i] <= target) {
            asf.push_back(nums[i]);
            comninationSumHelper(nums, i, target - nums[i], asf);
            asf.pop_back();
        }   
    }
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> asf;
        comninationSumHelper(candidates, 0, target, asf);
        return ans;
    }

int main(){





}


