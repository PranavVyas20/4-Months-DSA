#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Good example - [1,1,0,1,1,1]
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount = INT_MIN;
        int count = 0;
        for(auto it: nums) {
            if(it == 1) count ++;
            else {
                maxCount = max(maxCount, count);
                count = 0;
            }
        }
        // why return max(count, maxcount) ?
        // because after the first interruption ie non-one element the maxCount is 2
        // now when the traversal will end the currentCount will be 3 but since the 
        // else condition is not triggered, maxCount will not be updated to 3
        return max(count,maxCount);
    }

