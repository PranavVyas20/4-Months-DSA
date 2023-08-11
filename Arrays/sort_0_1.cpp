#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Basically low denotes - the last location of 1 found, so that we can 
// swap arr[i], arr[low] when we find a 0
// [0,0,0,1,0,1,1,0,0]
void segregate0and1(int arr[], int n)
{
    int low = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            swap(arr[i], arr[low]);
            low++;
        }
    }
}

int main()
{
}
