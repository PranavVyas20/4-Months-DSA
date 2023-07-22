#include<iostream>
#include<bits/stdc++.h>
using namespace std;

    bool isPalindrome(string str, int start, int end){
    while (start <= end) {
        if(str[start] != str[end]) {
        return false;
        }
        start ++;
        end --;
    }
    return true;
}
    void palindromePartition(string &s, int idx, vector<string> asf, vector<vector<string>> &ans) {
    // base case
    if(idx == s.length()) {
        ans.push_back(asf);
        return;
    }

    for(int i = idx ; i < s.length(); i++) { 
        if(isPalindrome( s, idx, i ) ) {
            asf.push_back( s.substr(idx , i - idx + 1) );
            palindromePartition(s, i + 1, asf, ans);
            asf.pop_back();
        } 
    }
    
}
    vector<vector<string>> partition(string s) {
        vector<string> asf;
        vector<vector<string>> ans;
        palindromePartition(s, 0, asf, ans);
        return ans;
    }
int main(){





}

