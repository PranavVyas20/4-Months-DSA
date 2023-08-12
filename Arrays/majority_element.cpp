#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// find element in array that occurs more than n/2 times(no = array length)
// It is guaranteed that there exists a solution (ie an element that occurs more than n/2 times)

// Brute Force:
// Run loop on every element and count its frequency -> TC - O(N ^ 2)

// Better:
// Use a hashmap store frequency of the elements -> TC - O(N), SC - O(N)

// Optimal Approach: Moore's voting algorithm
// initially set an element(first element of the array) as the ans and its freq as 0;
// Traverse the array and compare the element with array [i] if they match increase the freq
// if they do not - reduce the freq
// when freq becomes 0 - change the element and freq = 1
// Basically reduce freq to 0 and change then change the element, at last the remaining element with freq
// greater than 0 will be our ans

int majorityElement(vector<int>& nums) {
        int count = 0;
        int element = nums[0];
        for(auto it: nums) {
            if(it == element) {
                count ++;
            } else {
                count--;
                if(count == 0) {
                    element = it;
                    count = 1;
                }
            }
        }
        return element;
    }
int main(){





}

