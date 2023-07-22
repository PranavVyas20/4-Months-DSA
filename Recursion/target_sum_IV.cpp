#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int combinationSum4Helper(vector<int> &nums, int target, vector<int> &vis) {
    if(target == 0) {
        return 1;
    }
    if(target < 0) return 0;
    
    if(vis[target] != -1) return vis[target];
    
    int asf = 0;
    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] <= target) {
                asf += combinationSum4Helper(nums, target - nums[i], vis);
        }
    }
    vis[target] = asf;
    return asf;
}
int combinationSum4(vector<int>& nums, int target) {
    vector<int> visited(target + 1, -1);
    return combinationSum4Helper(nums, target, visited);
}
int main(){
    vector<int> v1 = {1,2,3};
    int a = combinationSum4(v1, 4);
    cout << "final ans: " << a;
}

