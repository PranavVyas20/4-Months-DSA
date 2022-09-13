#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// [10, 20, 30, 40, 50] 

vector<vector<int>> ans;

void getTargetSubsets(vector<int> nums, vector<int> temp, int target, int idx, int sum) {
    if(idx == nums.size()) {
        if(sum == target) {
            ans.push_back(temp);
            for(int i = 0; i < temp.size(); i++) {
                cout << temp[i] << " ";
            }
            cout << endl;
        }
        return;
    }
    // element not included in subset;
    getTargetSubsets(nums, temp, target, idx + 1, sum);
    // element included in subset;
    temp.push_back(nums[idx]);
    getTargetSubsets(nums, temp, target, idx + 1, sum + nums[idx]);
}
int main(){
    vector<int> questionVector = {10,20,30,40,50};
    getTargetSubsets(questionVector, {}, 60, 0, 0);
}

