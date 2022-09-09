#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<string> codes = {
                         "",
                        "abc",
                        "def",
                        "ghi",
                        "jkl",
                        "mno",
                        "pqrs",
                        "tuv",
                        "wxyz"
                    };

vector<string> letterCombination(string digits) {
    if(digits.length() == 0) {
        return {""};
    }
    char ch = digits[0];
    vector<string> ros = letterCombination(digits.substr(1));
    vector<string> ans;

    string digitCodes = codes[ch - '0'];

    for(int i = 0; i < digitCodes.size(); i++) {
        char chCode = digitCodes[i];

        for(int j = 0; j < ros.size(); j++) {
            cout << ros[j] << " " << endl;
            ans.push_back(ros[j] + chCode);
        }
    }
    return ans;
}
int main(){

string str = "23";
vector<string> myans = letterCombination(str);
cout << str.size();
for(int i = 0; i < myans.size(); i++) {
    cout << myans[i] << " ";
}


}

