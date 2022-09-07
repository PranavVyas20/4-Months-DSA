#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int findLastOccurence(vector<int> arr, int idx, int data) {
    if(idx < 0) {
        return -1;
    }
    if(arr[idx] == data) {
        return idx;
    } else {
        int foundInRestOfArray = findLastOccurence(arr, idx - 1, data);
        return foundInRestOfArray;
    }
}

int main() {
vector<int> v1 = { 1, 3, 3, 2, 5};
cout << findLastOccurence(v1, v1.size() - 1, 7);

}


