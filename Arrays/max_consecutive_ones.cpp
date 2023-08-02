#include<iostream>
#include<bits/stdc++.h>
using namespace std;

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
        return max(count,maxCount);

        // another approach
        // int maxCount = INT_MIN;
        // int count = 0;
        // for(auto it: nums) {
        //     if(it == 1) {
        //         maxCount = max(count ++, maxCount);
        //     }
        //     else {
        //         count = 0;
        //     }
        // }
        // return count;
    }

