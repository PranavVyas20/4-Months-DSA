#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// TC - O(N)
// we can use set as well
int removeDuplicates(vector<int>& nums) {
    int i = 0;

    for(int j = 0; j < nums.size(); j++) {
        if(nums[i] != nums[j]) {
            nums[i+1] = nums[j];
            i++;
        }
    } 
    return i + 1;       
}
int main(){





}

