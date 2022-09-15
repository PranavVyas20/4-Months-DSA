#include<iostream>
#include<bits/stdc++.h>
using namespace std;


vector<string> ans;
void genAbbreviations(string str, string asf, int count) {
    // Base case here
    if(str.length() == 0) {
        if(count == 0) {
            cout << asf << endl;
            return;
        } else {
            cout << asf + char(count) << endl;
            return;
        }
    }

    char ch = str[0];
    string ros = str.substr(1);

    if(count > 0) {
        genAbbreviations(ros, asf + char(count) + ch, 0);
    } 
    else {
        genAbbreviations(ros, asf + ch, 0);
        genAbbreviations(ros, asf, count + 1);
    }
}

int main(){
genAbbreviations("pep","",0);
// string s = "";
// cout << s.substr(1);




}

