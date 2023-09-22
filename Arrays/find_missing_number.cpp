#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
We are given the range and all the numbers are present except for one
single number and that we have to find out
for example - [3 0 1]
the range would be => 0 - 3, but is missing here
we can easily find out the missing number 
step 1 - find out the total sum of this range - sum of n numbers ie 6 
in this case
step 2 - traverse the array and eliminate ie - substract arr[i] from total sum
step 3 - at last the sum will get reduced to that missing number 
step 4 - yes I came up with this approach by my self!!!
*/
  int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = ( n * (n+1) ) / 2;
        for(auto it: nums) {
            sum = sum - it;
        }
        return sum;
    }

int main(){





}

