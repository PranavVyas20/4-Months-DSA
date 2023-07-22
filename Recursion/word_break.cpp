#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isPresentInDict(string str, vector<string> dict) {
    for(int i = 0; i < dict.size(); i++) {
        if(str == dict[i]) {
            return true;
        }
    }
    return false;
}
bool wordBreakHelper(string str, int idx, vector<string> dic) {
    // Base case



    for(int i = idx; i < str.size(); i++) {
        if( isPresentInDict(str.substr(i), dic) ) {
            // Call recursion on the rest of the string
            
        }
    }
}
int main(){

}

