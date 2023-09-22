#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Two pointer approach 
// TC - 0(N)
// The idea is to keep moving until we find a non zero element and then swap it with the pointer var
// Example - 0 0 0 1 2 0 0 4
// Initially ptr = 0 and we start a loop on the array
// till idx 2, we dont do anything, but on idx 3 we find that the element is non-zero
// so we swap nums[i] nums[ptr]
// Now the array is - 1 0 0 0 2 0 0 4
// we can keep doing this
// Dry run this example - 1 2 3 0 5
void moveZeroes(vector<int>& nums) {
        int ptr = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != 0) {
                swap(nums[i], nums[ptr]);
                ptr++;
            }
        }
    }
int main(){





}

