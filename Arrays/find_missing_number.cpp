#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int missingNumber(vector<int>& nums) {
        int missingNumber(vector<int>& nums) {
        int actualSum = 0;
        int n = nums.size();
        int nSum = (n * (n + 1))/2;
        for(auto it : nums) {
            actualSum+=it;
        }
        return nSum - actualSum;
    }
}

int main(){





}

