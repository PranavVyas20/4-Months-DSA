#include <iostream>
#include <bits/stdc++.h>
using namespace std;


// using xor operator
// x ^ x = 0;
// x ^ 0 = x;
int singleNumber(vector<int> &nums)
{
    int ans = 0;
    for (auto it : nums)
    {
        ans = it ^ ans;
    }
    return ans;
}
