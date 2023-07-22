#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> allIndicesArray(vector<int> arr, int data, int idx) {
    if(idx == arr.size()) {
        return { };
    }
    vector<int> foundInRestOfArray = allIndicesArray(arr, data, idx + 1);
    if (arr[idx] == data) {
        foundInRestOfArray.push_back(idx);
    }
    return foundInRestOfArray;
}
int main(){
vector<int> v1 = {1,2,4,3,3,3,7};
vector<int> ans = allIndicesArray(v1, 3, 0);
for(int x:ans){
    cout << x << " ";
}
}

