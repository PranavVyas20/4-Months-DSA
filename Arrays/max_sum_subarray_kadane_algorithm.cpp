#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Using kadane's algorithm
// Algo:
// cannot carry -ve sum as it will decrease the overall sum, so we drop it
// CHECK NOTES!!!

int maxSubArray(vector<int> &nums) {
    int maxSum = INT_MIN;
    int sum = 0;
    for (auto it : nums) {
        sum += it;
        maxSum = max(sum, maxSum);
        if (sum < 0) {
            sum = 0;
        }
    }
    return maxSum;
}
