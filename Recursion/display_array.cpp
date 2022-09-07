#include<iostream>
#include<vector>
using namespace std;

void displayArray(vector<int> arr, int startIndex, int lastIndex){
    // base case here
    if(startIndex == lastIndex){
        cout << arr[lastIndex] <<  " ";
        return;
    }
    cout << arr[startIndex] << " ";
    displayArray(arr, startIndex + 1, lastIndex);

}
int main(){
vector<int> v1 = {1,2,3,4,5};
displayArray(v1,0,4);

}

