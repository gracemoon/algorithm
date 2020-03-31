/* 
问题描述：
Given a list of daily temperatures T, return a list such that, for each day in the input, 
tells you how many days you would have to wait until a warmer temperature. 
If there is no future day for which this is possible, put 0 instead.

For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76, 73], 
your output should be [1, 1, 4, 2, 1, 1, 0, 0].

Note: The length of temperatures will be in the range [1, 30000]. 
Each temperature will be an integer in the range [30, 100].

解题思路:


*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* dailyTemperatures(int* T, int TSize, int* returnSize){
    *returnSize=TSize;
    int* t=(int*)malloc(sizeof(int)*TSize);
    for(int i=0;i<TSize;i++){
        if(i==TSize-1){
            t[i]=0;
        }else{
            int j=i+1;
            for(;j<TSize;j++){
                if(T[j]>T[i]){
                    break;
                }
            }
            if(j==TSize){
                t[i]=0;
            }else{
                t[i]=j-i;
            }
        }
        
    }
    return t;
}

int main(){
    int Tsize=8;
    int a[] = {73, 74, 75, 71, 69, 72, 76, 73};
    int *T=a;
    int* returnSize=malloc(sizeof(int));
    int *t=dailyTemperatures(T,Tsize,returnSize);
    for(int i=0;i<(*returnSize);i++){
        printf("%d\t",t[i]);
    }
    return 0;
}