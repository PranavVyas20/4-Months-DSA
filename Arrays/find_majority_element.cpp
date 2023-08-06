#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Find max elemtn from the array that occur more than n/2 times

    int majorityElement(vector<int>& nums) {
        // This is a better approach, but can be further optimsed
        // unordered_map<int,int> mp;
        // int k = nums.size() / 2;
        // for(auto it : nums) {
        //     mp[it] ++;
        // }
        // for(auto it : mp) {
        //     if(it.second > k) return it.first;
        // }
        // return 0;


        // Using moore's voting algorithm
        int element = nums[0];
        int count = 0;
        for(auto it : nums) {
            if(it == element) {
                count ++;
            } else {
                count --;
                if(count == 0) {
                    element = it;
                    count = 1;
                }
            }
        }
        return element;

    }
