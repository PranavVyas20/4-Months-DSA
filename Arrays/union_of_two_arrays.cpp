#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
Example vec1 = [2,4,1,5,3,6]
        vec2 = [2,2,4,1,5]

Union means - every element should only appear only once
final result array = [1,2,3,4,5,6];

Approach - we use a set and put every element in it. Since set only takes distinct elements
it will automatically filter out the duplicates

*/
vector<int> findUnion(vector<int> vec1, vector<int> vec2) {
    set<int> st;
    vector<int> result;

    for(int it: vec1) {
        st.insert(it);
    }

    for(int it: vec2) {
        st.insert(it);
    }

    for(int it: st) {
        result.push_back(it);
    }
    return result;
}

