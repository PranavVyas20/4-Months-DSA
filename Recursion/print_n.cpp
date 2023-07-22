#include<iostream>
using namespace std;

void printOneToN(int n){
    if(n == 0){
        return;
    }
    printOneToN(n-1);
    cout << n << " ";
}

void printNToOne(int n){
    if(n == 1){
        cout << n;
        return;
    }
    cout << n << " ";
    printNToOne(n-1);
}
int main(){
    printNToOne(7);
    printOneToN(7);
}