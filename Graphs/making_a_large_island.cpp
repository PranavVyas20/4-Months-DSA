#include <iostream>
#include <disjoint_set.h>
#include <bits/stdc++.h>
using namespace std;

bool isValid(int row, int col, int n)
{
    return (row >= 0 and col >= 0 and row < n and col < n);
}
int largestIsland(vector<vector<int>> &grid)
{
    int n = grid.size();

    DisjointSet ds(n * n);

    int xDir[4] = {-1, 0, 1, 0};
    int yDir[4] = {0, 1, 0, -1};

// STEP => 1
    // connect all one's and form components
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            if (grid[i][j] == 1)
            {
                for (int idx = 0; idx < 4; idx++)
                {
                    int nextRow = i + xDir[idx];
                    int nextCol = j + yDir[idx];

                    if (isValid(nextRow, nextCol, n) and grid[nextRow][nextCol] == 1)
                    {
                        int currentNode = (n * i) + j;
                        int adjNode = (n * nextRow) + nextCol;
                        ds.unionBySize(currentNode, adjNode);
                    }
                }
            }
        }
    }

    // STEP => 2
    int maxArea = INT_MIN;
    // Now traverse the matrix and try to convert a '0' to '1'
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 0)
            {
                set<int> st;
                int tempArea = 0;

                for (int i = 0; i < 4; i++)
                {
                    int nextRow = xDir[i] + i;
                    int nextCol = yDir[j] + j;

                    // Go in all 4 directions
                    if (isValid(nextRow, nextCol, n) and grid[nextRow][nextCol] == 1)
                    {
                        int adjNode = (n * nextRow) + nextCol;
                        int ultParOfAdjNode = ds.findUltimateParent(adjNode);
                        int sizeOfComponent = ds.size[ultParOfAdjNode];

                        st.insert(sizeOfComponent);
                    }
                }
                for (auto it : st)
                {
                    tempArea += ds.size[it];
                }
                maxArea = max(maxArea, tempArea);
            }
        }
    }
    // in case the entire matrix is filled with 1:
    maxArea = max(maxArea, ds.size[ds.findUltimateParent(0)]);
    return maxArea;
}

int main()
{
}
