#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*
[0,3,7,2,5,8,4,6,0,1]
Brute Force - O(N ^ 2)

Better - O(n Log N):
1. Sort the array => [0, 0, 1, 2, 3, 4, 5, 6, 7, 8] 
2. Keep checking if arr[i] == prev element + 1, if yes - keep  increasing the current subsequence length
3. If not then the subsequence ends and reset the current subsequence length and update the max of prev subsequnce length 
   and the current one

IMP !! - Reset the sequence when current elemet != lastMinElement, because we dont want to reset the current sequence if we 
get identical elements like 0, 0
*/
int longestConsecutiveBetter(vector<int>& nums) {
        int longest = 0;
        int count = 0;
        int lastMinElement = INT_MIN;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] - 1 == lastMinElement) {
                count++;
            // For a case where the curr element == prev element
            } else if(nums[i] != lastMinElement) {
                count = 1;
            }
            longest = max(longest, count);

            lastMinElement = nums[i];
        }
    return longest;
}

// Optimal - O(N)
int longestConsecutiveOptimal(vector<int> & nums) {
    int longestSubsequenceLength = 0;
    // map<element, can this be the start of a sequence: Bool>
    unordered_map<int, bool> mp;
    // Push element in the map;
    for(auto it : nums) {
        mp[it] = true;
    }
    // Traverse the array and check if curr element can be the start of a sequence by checking if curr element - 1 th 
    // element exists in the map or not
    for(auto it : nums) {
        if(mp.find(it - 1) != mp.end()) {
            mp[it] = false;
        }
    }

    // Traverse the map and pick the elements that can be the start of a sequence, check till how long we can find an element that 
    // is just + 1 of the element and keep increasing the current sequence length
    for(auto it : nums) {
        if(mp[it] == true) {

        int element = it;

        int incrementor = 1;
        int currentSequenceLength = 1;

        while(mp.find(element + incrementor) != mp.end()) {
            currentSequenceLength++;
            incrementor++;
        }
        longestSubsequenceLength = max(longestSubsequenceLength, currentSequenceLength);
        }
    }
    return longestSubsequenceLength;
}


