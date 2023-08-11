#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// have to do it in place
// count number of 0, 1, 2
// and place them in the array
// TC - O(2N)
void sortColors(vector<int> &nums)
{
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;

    for (auto it : nums)
    {
        switch (it)
        {
        case 0:
            zeroCount++;
            break;
        case 1:
            oneCount++;
            break;
        case 2:
            twoCount++;
            break;
        }
    }
    for (int i = 0; i < zeroCount; i++)
        nums[i] = 0;
    for (int i = zeroCount; i < zeroCount + oneCount; i++)
        nums[i] = 1;
    for (int i = zeroCount + oneCount; i < nums.size(); i++)
        nums[i] = 2;
}

// Using Dutch national flag algorithm
// TC - O(N)
// why mid '<=' high - dry run this example - [2,0,1]
vector<int> sortColorsDNF(vector<int>& nums) {
    int low = 0;
    int mid = 0;
    int high = nums.size() - 1;

    while(mid <= high) {
        if(nums[mid] == 0) {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        } else if(nums[mid] == 1) {
            mid++;
        } else {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
    return nums;
}
int main()
{
}
