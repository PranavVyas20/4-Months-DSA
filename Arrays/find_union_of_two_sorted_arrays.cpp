#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
Example: Arr1 = [1 2 3 5 7]
         Arr2 = [3 4 5 6 7]
         result = [1 2 3 4 5 6 7]

### VVIP - The order should be maintained ie they should be sorted ####

Since the array is sorted we can use a two pointer approach.
- Keep both pointers at 0 idx
- we also need a variable to keep track of the last element that was inserted into our 
result vector so that we only keep distinct elements and no duplicated
- whenever we want to insert an element in our result vector we will first compare that element
with our last element present in the result vector. If they are not same then only we will add that 
element.

- Now we compoare the arr1 and arr2 elements:
- case 1 => both are equal - we first compare it with last element and take the element 
from any of the array and put in in the result. We increase both the pointers

- case 2 => when any one the element is greater than the other:
            we need to take the smaller one in this case because we want the union to be sorted
            so we take the smaller element and compare it with the last element. If they are not 
            same, we insert it into the result vector.
            Increase the pointer corrosponding to the smaller element
vector

*/
vector<int> findUnion(int arr1[], int arr2[], int n, int m)
{
    int i = 0;
    int j = 0;
    int latestElement = -1;
    vector<int> result;

// We stop the loop even if one of the pointer reaches the max size of the array
// doing this because the arrays can be of different sizes
    while (i < n && j < m)
    {
        if (arr1[i] == arr2[j])
        {
            if (arr1[i] != latestElement)
            {
                result.push_back(arr1[i]);
                latestElement = arr1[i];
            }
            i++;
            j++;
        }
        else if (arr1[i] > arr2[j])
        {
            if (latestElement != arr2[j])
            {
                result.push_back(arr2[j]);
                latestElement = arr2[j];
            }
            j++;
        }
        else
        {
            if (latestElement != arr1[i])
            {
                result.push_back(arr1[i]);
                latestElement = arr1[i];
            }
            i++;
        }
    }

// If the arrays were of different sizes, then there must be some elements unprocessed
// We process them here and simply add them in the result vector but we do check for duplicated
// by comparing every element with the last element in the result vector
    while (i < n)
    {
        if (arr1[i] != latestElement)
        {
            result.push_back(arr1[i]);
            latestElement = arr1[i];
        }
        i++;
    }
    while (j < m)
    {
        if (arr2[j] != latestElement)
        {
            result.push_back(arr2[j]);
            latestElement = arr2[j];
        }
        j++;
    }
    return result;
}
