#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int A[] = {10, 5, 2, 7, 1, 9};
int N = 6;
int K = 6;

// Example - [10, 5, 2, 7, 1, 9]
// Brute force approach, gives TLE

int lenOfLongSubarr()
{
    int maxSubarray = 0;
    for (int i = 0; i < N; i++)
    {
        int sum = 0;
        int idx = i;
        int len = 0;
        for (int j = i; j < N; j++)
        {
            sum += A[j];
            len++;
            if (sum == K)
            {
                maxSubarray = max(len, maxSubarray);
            }
        }
    }
    return maxSubarray;
}

/*
hasing, better approach
Works for +ve and -ve arrays
map<sum, index>

Approach - We will do two things:
1. For every element in the array we will check if it is a part of a subarray that sums up to be K.
example - [7 1 2 2 -3 0 3], K = 3
indices -  0 1 2 3  4 5 6

sum = 7 + [1 + 2] + 2 + -3 + [0 + [3] ]
          sub-arr             sub-arr 2

how do we figure out that [1 + 2] is a valid subarray ?
ans - current sum till 2 = 10, now if [7 1 2] is equal to 10, if there exist a sum of 10 - 7 ie 3 before 2 then 2 will be 
a part of a valid subarray!!!

And how do we find if there exists a sum of 7 before? We need to store that in a map. Basically traverse the array and 
keep increasing currentSum and add it in the map corrosponding to the index

2. We keep track of sum ie - sum of current elements and check if it gets equal to k at any point.
*/

    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        unordered_map<int, int> mp;
        int maxSubarrayLen = 0;
        int currentSum = 0;

        for(int i = 0; i < N; i++) {
            currentSum += A[i];
            
            // check if at anypoint the sum gets equal to k, then update the max subarray len
            if(currentSum == K) {
                maxSubarrayLen = max(i + 1, maxSubarrayLen);
            }
            // Calculating the required sum before the current element
            int requiredSum = currentSum - K;
            
            // Yes we need to do this at every element, not only when the currentSum > K!!!!!
            // Check if the required sum exists in the map, if yes than there is a valid subarray
            if(mp.find(requiredSum) != mp.end()) {
                int len = i - mp[requiredSum];
                maxSubarrayLen = max(len, maxSubarrayLen);
            }
            
            // Only add the current sum in the map if it doesn't exists already, WHY ??
            // ANS - [2 0 0 1 3], in this case the max subarray len is - 4
            // but if we keep updating the sum everytime then there will be an entry like this is the map => 2nd (idx) - sum(2)
            // And when we will reach on 1 and check if there exists a sum of 2 before it will give idx - 2 as result and
            // the final ans would be (current idx - 2) + 1 => 2 which is wrong!!!
            // Correct ans => (current idx - 0) + 1 => 4
            // Hence we need to keep the sum idx minimised!!
            if(mp.find(currentSum) == mp.end()) {
                mp[currentSum] = i;
            }
        }
        return maxSubarrayLen;
    }

// Two pointer approach - sliding window
// Only works when the arraay is positive
/*
The main idea is that as we progress forward in the array, the sum is bound to increase.
So we change the size of our window like this:
- current sum > k - shrink the window from behind ie - decrement the left pointer
*/
int longestSubarrayWithSumK(vector<int> a, long long k)
{
    int left = 0;
    int right = 0;
    int n = a.size();
    int maxSubarraySize = INT_MIN;
    int currentSum = 0;

    while (right < n)
    {
        while (currentSum > k)
        {
            currentSum -= a[left];
            left++;
        }

        if (currentSum == k)
        {
            int newSubarrayLen = (right - left) + 1;
            maxSubarraySize = max(newSubarrayLen, maxSubarraySize);
        }
        right++;
    }
    return maxSubarraySize;
}
