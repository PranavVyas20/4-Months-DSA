#include<iostream>
#include<vector>
using namespace std;

vector<int> findFirstAndLastOccurence(vector<int> nums, int target) {
    vector<int> ansVector;
        bool foundFirstOccurence = false;
        bool foundSecondOccurence = false;
        int firstOccurence;
        
        // Empty array case 
        if(nums.size() == 0) {
            return {-1, -1}; 
        } else if (nums.size() == 1 && nums[0] == target) {
            return {0,0};
        }
            
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target){
                if(!foundFirstOccurence) {
                    ansVector.push_back(i);
                    foundFirstOccurence = true;
                    firstOccurence = i;
                } else {
                    if(foundSecondOccurence) {
                        ansVector.pop_back();
                        ansVector.push_back(i);
                    } else {
                        ansVector.push_back(i);
                    }
                    foundSecondOccurence = true;
                }
            }
        }
        // Both occurence not found
        if(ansVector.size() == 0){
            return {-1, -1};

        // Only found first occurence
        } else if(foundSecondOccurence == false) {
            return {firstOccurence,firstOccurence};
        }
        else {
            return ansVector;
        }
    }

int main(){





}

