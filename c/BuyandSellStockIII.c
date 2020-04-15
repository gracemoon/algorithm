/* 
问题描述：
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

Example 1:

Input: [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
             Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
Example 2:

Input: [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
             Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
             engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.

解题思路:


*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>

int Profit(int* prices, int x,int y){
    int max=0;
    int low=x;
    for(int i=x+1;i<=y;i++){
        if(prices[i]>prices[low]){
            int local=prices[i]-prices[low];
            if(max<local){
                max=local;
            }
        }else{
            low=i;
        }
    }
    return max;
}
int maxProfit(int* prices, int pricesSize){
    int max=0;
    for(int i=0;i<pricesSize;i++){
        int a=0,b=0;
        if(i>0){
            a=Profit(prices,0,i);
        }
        if(i<pricesSize-1){
            b=Profit(prices,i+1,pricesSize-1);
        }
        if(max<a+b){
            max=a+b;
        }
    }
    return max;
}


int main(){
    int m[]={3,3,5,0,0,3,1,4};
    // int m[]={7,6,5,4,3,2,7};
    int profit=maxProfit(m,8);
    printf("%d",profit);
    return 0;
}