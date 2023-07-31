#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// Two pointer approach 
// TC - 0(N)
void moveZeroes(vector<int>& nums) {
        int i;
        for(int k = 0; k < nums.size(); k++) {
            if(nums[k] == 0) {
                i = k;
                break;
            }
        }

        for(int j = i+1; j < nums.size(); j++) {
            if(nums[j] != 0) {
                swap(nums[i], nums[j]);
                i++;
            }
        }
    }
int main(){





}

