#include <iostream>
#include <disjoint_set.h>
#include <bits/stdc++.h>
using namespace std;

vector<int> numOfIslandsII(int n, int m, vector<vector<int>> &q)
{
    int rows = n;
    int cols = m;

    // create a disjoint set
    DisjointSet ds(m * n);

    // Create a vis matrix and a operation matrix
    vector<vector<int>> vis(rows, vector<int>(cols, 0));

    // Answer vector
    vector<int> ans;

    // current islands count
    int islandsCount = 0;

    // arrays for going in 4 directions
    int xDir[4] = {-1, 0, 1, 0};
    int yDir[4] = {0, 1, 0, -1};

    for (auto queries : q)
    {
        int row = queries[0];
        int col = queries[1];

        if (vis[row][col] == 1)
        {
            ans.push_back(islandsCount);
            continue;
        }
        // if the node is not already visited, then visit it and increase islands count;
        // it will be reduced later if needed
        vis[row][col] = 1;
        islandsCount++;

        // Go in all the four directions
        for (int i = 0; i < 4; i++)
        {
            int nextRow = row + xDir[i];
            int nextCol = col + yDir[i];

            if (nextRow >= 0 and nextRow < rows and nextCol >= 0 and nextCol < cols )
            {
                if (vis[nextRow][nextCol] == 1)
                {
                    // To create node from given row, col:
                    // int node = (maxCol * currentRow) + currentCol
                    int currentNode = (cols * row) + col;
                    int nextPotentialNode = (cols * nextRow) + nextCol;

                    // connect them if they do not have same ult parent
                    // it if they are not alrady in the same component
                    if (ds.findUltimateParent(currentNode) != ds.findUltimateParent(nextPotentialNode))
                    {
                        ds.unionBySize(currentNode, nextPotentialNode);
                        islandsCount--;
                    }
                }
            }
        }
        ans.push_back(islandsCount);
    }
    return ans;
}

////////////////////////////////////////////////////////////////////////////////////////
