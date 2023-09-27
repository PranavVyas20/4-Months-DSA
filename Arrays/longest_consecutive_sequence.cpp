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
    int longestConsecutive(vector<int>& nums) {
        int maxSequenceLen = 1;
        unordered_set<int> st;
        if(nums.size() == 0) return 0;
        for(auto it: nums) {
            st.insert(it);
        }
        for(auto it: st) {
            int pre = it - 1;
            int post = it + 1;
            int currentLen = 1;

            if(st.contains(post) && !st.contains(pre)) {
                while(st.contains(post)) {
                    currentLen++;
                    post++;
                }
                maxSequenceLen = max(currentLen, maxSequenceLen);
            }
        }
        return maxSequenceLen;
    }


