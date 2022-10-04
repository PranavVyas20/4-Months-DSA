#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> permuteHelper(vector<int> nums, vector<vector<int>> result) {
    // Base case
    if(nums.size() <= 1) {
        return { nums };
    }
    for(int i = 0; i < nums.size(); i++) {
        int firstElement = nums[i];
        vector<int> temp(nums.begin(), nums.end());
        temp.erase(temp.begin() + i);

        vector<vector<int>> res;
        vector<vector<int>> rovResult = permuteHelper(temp, res);

        for(int j = 0; j < rovResult.size(); j++) {
            rovResult[j].push_back(firstElement);
            result.push_back(rovResult[j]);
        }
    }
    return result;
} 

// Method 2 - Travel and solve
vector<vector<int>> ans;
void permuteHelperII(vector<int> & nums, vector<int> asf, vector<bool> visited) {
    if(asf.size() == nums.size()) {
        ans.push_back(asf);
        return;
    }
    for(int i = 0; i < nums.size(); i++) {
        if(visited[i]) continue;
        visited[i] = true;
        asf.push_back(nums[i]);
        permuteHelperII(nums, asf, visited);
        asf.pop_back();
        visited[i] = false;
    }
}
int main(){}

