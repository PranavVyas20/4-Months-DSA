#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*

arr = [7, 1, 5, 3, 6, 4]

Look from the end of the array, if we want to buy the stock at 5th day (idx = 4) - then we need to sell
it on the day on which its value becomes max, which basically means max number to its right array.

Initially keep last element as the globalRightMax = 4;
Start iterating on the array from the second last idx

-> if we buy the stock for 6rs, then we can sell it at a max of => max number to its right ie max(i+1, rightMax)
    6 -> 4

-> if we buy the stock for 3rs, then we can sell it at a max of => max(rightNextElement, globalRightMax)
                                                                   max(6, 4); 
    3 -> 6 
    also update the globalRightMax as well !!
    globalRightMax = 6;

-> if we buy the stock for rs 5, then we can sell it at a max of => max(3, 6)

-> if we buy the stock for rs 1, then we can sell it at a max of => max(5, 6)

-> if we buy the stock for rs 7, then we can sell it at a max of => max(1, 6)

# Even if the profit it -ve, no issues either we will get better profit (ie +ve profit) later on while
traversing in the array or if after the traversal if the profit is still -ve -> we cannot earn profit 
therefore return 0

*/
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int rightMax = prices[n - 1];
    int profit = -1;
    // starting loop form second last idx because the we cannot buy the stock on the last day
    // because then we wont be able to sell it 
    for(int i = n - 2; i >= 0; i--) {
        rightMax = max(rightMax, prices[i+1]);

        int currentProfit = rightMax - prices[i];

        profit = max(profit, currentProfit);
    }
    if(profit < 0) return 0;

    return profit;
}

int main(){





}

