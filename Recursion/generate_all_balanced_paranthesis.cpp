#include<iostream>
#include<bits/stdc++.h>
using namespace std;


vector<string> ans;
void genParanthesis(int n, string asf, int openingBrackets, int closingBrackets) {
    if(openingBrackets == 0 && closingBrackets == 0) {
        ans.push_back(asf);
        return;
    }
    if(openingBrackets > 0) {
        genParanthesis(n, asf + "(", openingBrackets - 1, closingBrackets);
    }
    if(closingBrackets > 0 && closingBrackets > openingBrackets) {
        genParanthesis(n, asf + ")", openingBrackets, closingBrackets - 1);
    }
}
int main(){
genParanthesis(3, "", 3, 3);
for(int i = 0; i < ans.size(); i++) {
    cout << ans[i] << endl;
}

}

