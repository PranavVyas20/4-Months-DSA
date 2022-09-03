#include<iostream>
using namespace std;

int printFactorial(int n){
    // Base condition here
    if(n <= 1){
        return n;
    }

    int fNo = printFactorial(n-1) + printFactorial(n-2);
    return fNo;

}

int main(){

cout << printFactorial(7);



}

