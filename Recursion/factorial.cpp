#include<iostream>
using namespace std;

int printFactorial(int n){
    if(n <= 1){
        return n;
    }
    return printFactorial(n-1) * n;
}
int main(){

cout << printFactorial(5);



}

