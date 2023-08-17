#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> ans;
    int topIdx = 0;
    int leftIdx = 0;
    int rightIdx = matrix[0].size() - 1;
    int bottomIdx = matrix.size() - 1;

    while (topIdx <= bottomIdx && leftIdx <= rightIdx)
    {
        // traverse right
        for (int i = leftIdx; i <= rightIdx; i++)
        {
            int element = matrix[topIdx][i];
            ans.push_back(element);
        }
        topIdx++;

        // Traverse bottom
        for (int i = topIdx; i <= bottomIdx; i++)
        {
            int element = matrix[i][rightIdx];
            ans.push_back(element);
        }
        rightIdx--;

        // Traverse left
        // Check if only single row exists now
        if (topIdx <= bottomIdx)
        {
            for (int i = rightIdx; i >= leftIdx; i--)
            {
                int element = matrix[bottomIdx][i];
                ans.push_back(element);
            }
            bottomIdx--;
        }

        // Traverse up
        if (leftIdx <= rightIdx)
        {
            for (int i = bottomIdx; i >= topIdx; i--)
            {
                int element = matrix[i][leftIdx];
                ans.push_back(element);
            }
            leftIdx++;
        }
    }
    return ans;
}
