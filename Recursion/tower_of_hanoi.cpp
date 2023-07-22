#include<iostream>
using namespace std;

void toh(int n, char src, char des, char helperTower){
    if(n == 0) {
        cout << "invalid input";
        return;
    } else if(n == 1) {
        cout << n << " " << src << " -> " << des; 
        cout << endl;
        return;
    }
    toh(n-1, src, helperTower, des);
    cout << n << " " << src << " -> " << des;
        cout << endl;
    toh(n-1, helperTower, des, src);
}

int main(){
    toh(3, 'a', 'c', 'b');
}

