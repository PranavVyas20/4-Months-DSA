#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void combineHelper(int n, const int k, int idx, vector<int> &asf, vector<vector<int>> &ans) {
    // Base case
    if(asf.size() == k) {
        ans.push_back(asf);
        return;
    }
    
    for(int i = idx; i <= n; i++) {
        asf.push_back(i);
        combineHelper(n, k, i + 1, asf, ans);
        asf.pop_back();
    }
}
vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ans;
    vector<int> asf;
    combineHelper(n, k, 1, asf, ans);
    return ans;
}
int main(){





}

