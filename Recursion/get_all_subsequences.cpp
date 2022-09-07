#include<iostream>
#include<bits/stdc++.h>
using namespace std;

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
int main(){
vector<string> ans = getSubsequences("abc");

for(int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
}

}

