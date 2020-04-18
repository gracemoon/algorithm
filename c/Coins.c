/* 
问题描述：


解题思路:


*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>

int minCount(int* coins, int coinsSize){
    int sum=0;
    for(int i=0;i<coinsSize;i++){
        int count=coins[i];
        while(count>0){
            sum++;
            count-=2;
        }
    }
    return sum;
}

int main(){
    int m;
    for(int i=0;i<10;i++){

        printf("the n = %d : %d \n",i,m);
    }
    return 0;
}