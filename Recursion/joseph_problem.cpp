#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int ans = 0;

int josephProblemHelper(vector<int> ppl, int k, int currentIdx) {
    int killIdx = k + currentIdx;

    if(ppl.size() == 1) {
        // ans = ppl[0];
        return ppl[0]; 
    }
    if(k + currentIdx > ppl.size() - 1) {
        killIdx = killIdx % ppl.size();
    }
    
    ppl.erase(ppl.begin() + killIdx);
    int answerRov = josephProblemHelper(ppl, k, killIdx);
    return answerRov;
}



int main(){
vector<int> v1  = {1,2,3,4,5};
cout << josephProblemHelper(v1, 3 -1 , 0);
// cout << ,ans;




}

