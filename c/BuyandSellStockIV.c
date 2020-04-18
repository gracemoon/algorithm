/* 
问题描述：
Say you have an array for which the i-th element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most k transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

Example 1:

Input: [2,4,1], k = 2
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
Example 2:

Input: [3,2,6,5,0,3], k = 2
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4.
             Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.

解题思路:


*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>

// int profit(int* prices,int x,int y){
//     int max=0;
//     int low;
//     for(int i=x;i<y;i++){
//         if(i==x){
//             low=prices[x];
//         }else{
//             if(prices[i]-low>max){
//                 max=prices[i]-low;
//             }
//             if(prices[i]<low){
//                 low=prices[i];
//             }
//         }
//     }
//     return max;
// }

// int maxProfit(int k, int* prices, int pricesSize){
int** record=(int**)malloc(sizeof(int*)*k);
for(int z=0;z<k;z++){
    record[z]=(int*)malloc(sizeof(int)*pricesSize);
}
return record[0];
//     int max=0;
//     for(int i=0;i<pricesSize;i++){
//         int max1=profit(prices,0,i);
//         int max2=profit(prices,i,pricesSize);
//         if(max1+max2>max){
//             max=max1+max2;
//         }
//     }

//     return max;
// }

int* profit(int* prices,int x,int y,int pricesSize){
    int* record=(int*)malloc(sizeof(int)*pricesSize);
    int max=0;
    int low;
    for(int i=x;i<y;i++){
        if(i==x){
            low=prices[x];
        }else{
            if(prices[i]-low>max){
                max=prices[i]-low;
            }
            if(prices[i]<low){
                low=prices[i];
            }
        }
        record[i]=max;
    }
    return record;
}

int** maxProfit(int k, int* prices, int pricesSize){
    if(k==0){
        return 0;
    }
    int** record=(int**)malloc(sizeof(int*)*pricesSize);
    for(int i=0;i<pricesSize;i++){
        record[i]=profit(prices,i,pricesSize-1,pricesSize);
    }
    return record;
}

int main(){
    int m[]={1,2,3,2,3,4};
    int** a=maxProfit(2,m,6);
    for(int i=0;i<6;i++){
        for(int j=i;j<6;j++){
            printf("%d\t",a);
        }
    }
    
    return 0;
}