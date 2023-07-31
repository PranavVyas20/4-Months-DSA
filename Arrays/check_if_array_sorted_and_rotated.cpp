#include<iostream>
#include<bits/stdc++.h>
using namespace std;


// How to check if the array was rotated? - check how many drops were there
// drops = arr[i] > arr[i + 1]
// example - [2,7,4,1,2,6,2] here drops = 2 but in a sorted-then-rotated-array there can only be 1 drop
// for example - org array = [1,3,5,8,9] and rotated by 2 = [8,9,1,3,5] 
// also notice that in a sorted-then-rotated-array the first element will be >= the last element

// example - [2,1,3,4] here drops is exactly one but the first element is not >= last element
// [1,2,3,4] if this was the original sorted array and if we rotate it by 'x' then its first element
// will always be >= last element
// why >'=' ??. Take this example - [6, 10, 6];
bool check(vector<int>& nums) {
    int drops = 0;
    for(int i = 0; i < nums.size() - 1; i++) {
        if(nums[i] > nums[i + 1]) {
            drops++;
        }
    }
    if(drops > 0) {
        if(drops == 1&& nums[0] >= nums[nums.size() - 1]) return true;
        return false;
    }
    // if there are no drops ie the array is already sorted
    return true;
}
int main(){





}

