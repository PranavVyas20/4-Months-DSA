#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Method 1 - get subAns and do operation on it to make the final ans
// example - abc 
// a, b, c, ab, bc, ac, abc are its subsequence 
//we can leave letters in between (a_c) but they shoudl be in sequence

vector<string> getSubsequences(string str) {
    if(str.length() == 0){
        return { "" };
    }
    char firstChar = str[0];
    vector<string> ros = getSubsequences(str.substr(1));
    vector<string> newStr;

    for(int i = 0; i < ros.size(); i++){
        newStr.push_back(ros[i]);
        newStr.push_back(ros[i] + firstChar);
    }
    return newStr;
}

// Method 2 - travel and solve
// Same as subsets, only difference there wont be an empty string as subsequence 
// analogus to empty [] in the case of subsets

vector<string> ans;
void genSubsequence(string str, string asf, int idx) {
    if(!asf.empty()) {
            ans.push_back(asf);
    }
    for(int i = idx; i < str.length(); i++) {
       asf.push_back(str[i]);
       genSubsequence(str, asf, i + 1);
       asf.pop_back();
    }
}
int main(){
vector<string> ans = getSubsequences("abcd");

for(int i = 0; i < ans.size(); i++) {
    cout << ans[i] << endl;
}

}

