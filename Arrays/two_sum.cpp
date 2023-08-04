#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// Brute Force approach - O(N^2)

// Better Approach - Use a hashmap
// SC - O(N)
// TC - if use ordered_map -> N * Log(N)
// if use unordered_map -> O(N * 1) for best and average case
// and O(N^2) for worst case because, unordered map can take O(N) for searching 
// in the worst case 
vector<int> twoSum(vector<int> &numbers, int target)
{
    //Key is the number and value is its index in the vector.
	unordered_map<int, int> hash;
	vector<int> result;
	for (int i = 0; i < numbers.size(); i++) {
		int numberToFind = target - numbers[i];

            //if numberToFind is found in map, return them
		if (hash.find(numberToFind) != hash.end()) {
                    //+1 because indices are NOT zero based
			result.push_back(hash[numberToFind]);
			result.push_back(i );			
			return result;
		}

            //number was not found. Put it in the map.
		hash[numbers[i]] = i;
	}
	return result;
}

// Optimal Approach using two pointer to reduce space complexity
// But we wont be able to return the indices of the two elements in this case
bool twoSumOptimal(vector<int> & numbers, int target) {
    int lp = 0;
    int rp = numbers.size() - 1;

    while(lp <= rp) {
        int sum = numbers[lp] + numbers[rp];
        if(sum == target) return true;
        else if(sum < target) lp++;
        else rp--;
    }
    return false;
}

