/* 
问题描述：


解题思路:


*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDiagonalOrder(int** nums, int numsSize, int* numsColSize, int* returnSize){
    int* ans=(int*)malloc(sizeof(int)*10000);
    int count=0;
    int sum=0;
    int* longest=(int*)malloc(sizeof(int)*numsSize);
    for(int i=0;i<numsSize;i++){
        longest[i]=0;
        sum+=numsColSize[i];
    }
    for(int i=0;i<numsSize && count<sum;){
        int x=i;
        while(x>=0){
            ans[count++]=nums[x][longest[x]];
            longest[x]++;
        }
        if(i<numsSize-1){
            i++;
        }
    }
    *returnSize=count;
    return ans;
}

int* findDiagonalOrder(int** nums, int numsSize, int* numsColSize, int* returnSize){
    int* ans=(int*)malloc(sizeof(int)*10000);
    int count=0;
    int sum=0;
    int* longest=(int*)malloc(sizeof(int)*numsSize);
    for(int i=0;i<numsSize;i++){
        longest[i]=0;
        sum+=numsColSize[i];
    }
    for(int i=0;i<numsSize && count<sum;){
        int x=i;
        while(x>=0){
            ans[count++]=nums[x][longest[x]];
            longest[x]++;
        }
        if(i<numsSize-1){
            i++;
        }
    }
    *returnSize=count;
    return ans;
}

int main(){
    int m;
    for(int i=0;i<10;i++){

        printf("the n = %d : %d \n",i,m);
    }
    return 0;
}