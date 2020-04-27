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
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize){
    int top=0;
    int* stack=(int*)malloc(sizeof(int)*numsSize);
    int* ans=(int*)malloc(sizeof(int)*(numsSize-k+1));
    int index=0;
    for(int i=0;i<numsSize;i++){
        int x=top;
        while(x>=0){
            if(stack[x]>nums[i]){
                stack[++x]=nums[i];
                top=x;
                break;
            }
            x--;
        }
        if(top-k>=0){
            ans[index++]=stack[top-k];
        }else{
            ans[index++]=stack[0];
        }
    }
    *returnSize=index;
    return ans;
}

int main(){
    int m;
    for(int i=0;i<10;i++){

        printf("the n = %d : %d \n",i,m);
    }
    return 0;
}