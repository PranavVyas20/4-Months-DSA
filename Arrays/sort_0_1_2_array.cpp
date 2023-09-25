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

/*
Using Dutch national flag algorithm
TC - O(N)
why mid '<=' high - dry run this example - [2,0,1]

We believe that our array is somewhat like this:
    {0 0 0 0 0}       {1 1 1 1}         {2 1 0 1 2 1}        {2 2 2 2}
   [0 --- low -1]   [low --- mid -1]   [mid --- high]   [high + 1 --- n - 1]    

   1. 0 -> low - 1 => contains only 0s
   2. low -> mid - 1 => contains only 1s
   3. mid -> high => contains unsorted elements
   4. high + 1 -> n - 1 => contains only 2s

   We will use mid as an iterator and on iterating over each element we will put it in its correct
   space 

   Why mid <= high?
   mid to high represents the space in which there are unsorted elements, but if mid get greater
   than high - it means that that space is no longer there.

*/
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
