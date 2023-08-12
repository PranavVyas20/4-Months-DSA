#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
Algo:
=> Find pivot element - it basically tells us that we can now swap the pivot element with another element
to make the entire sequnce bigger
=> Find an element that is 'just' greater than the pivot element
=> Swap pivot element with that 'just' greater element
=> Reverse the array from pivot idx to end idx - to minimise the remaining sequence
 
// CHECK NOTES!!!

example: [1, 4, 3, 2] => [2, 1, 4, 3]
pivot element = 1
pivot idx = 0

*/ 

void nextPermutation(vector<int>& nums) {
    int pivotIdx = -1;
    int n = nums.size();

    for(int i = n - 1; i > 0; i--) {
        // found pivot
        if(nums[i] > nums[i - 1]) {
            pivotIdx = i - 1;
            break;
        }
    }
    if(pivotIdx == -1) {
        reverse(nums.begin(), nums.end());
        return;
    }
    // Find 'just' greater element that the pivot element
    for(int i = n - 1; i > pivotIdx; i--) {
        if(nums[i] > nums[pivotIdx]) {
            swap(nums[i], nums[pivotIdx]);
            break;
        }
    }
    reverse(nums.begin() + (pivotIdx + 1), nums.end());
    return;
}
int main(){





}

