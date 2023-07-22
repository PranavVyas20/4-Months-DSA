#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;

void combinationSumIII(int k, int n, int idx, vector<int> asf) {
    if(asf.size() == k && n == 0) {
        ans.push_back(asf);
        return;
    }
    if(asf.size() > k || n < 0) return;

    for(int i = idx; i <= 9; i++) {
        asf.push_back(i);
        combinationSumIII(k, n - i, i + 1, asf);
        asf.pop_back();
    }
}
int main(){





}

