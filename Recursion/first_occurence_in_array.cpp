#include<iostream>
#include<vector>
using namespace std;

// Recursion will work on the rest of the array 
// and I will just check for the first element

int firstOccurence(vector<int> arr, int idx, int data){
    if(idx == arr.size()){
        return -1;
    }

    // Here we are making the recursive call first and then
    // comparing the elements, which is not the efficient way
    // First compare, if found then no need to go further in the array

//    int restOfArray = firstOccurence(arr, idx + 1, data);

    if(arr[idx] == data) {
        return idx;
    } else {
        //
        int restOfArray = firstOccurence(arr, idx + 1, data);
        //
        return restOfArray;
    }
}
int main(){

vector<int> v1 = { 1, 3, 3, 2, 5};
cout << firstOccurence(v1,0,3);
}

