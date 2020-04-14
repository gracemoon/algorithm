/* 
问题描述：
Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]
Constraint: It's guaranteed that the product of the elements of any prefix or suffix of the array (including the whole array) fits in a 32 bit integer.

Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)

解题思路:


*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize){
    *returnSize=numsSize;
    long sum=1;
    int zeros=0;
    for(int i=0;i<numsSize;i++){
        if(nums[i]!=0){
           sum*=nums[i]; 
        }else{
            zeros++;
        }
    }
    int* p=(int*)malloc(sizeof(int)*numsSize);
    if(zeros>1){
        for(int i=0;i<numsSize;i++){
            p[i]=0;
        }
    }else if(zeros==1){
        for(int i=0;i<numsSize;i++){
            if(nums[i]==0){
                p[i]=sum;
            }else{
                p[i]=0;
            }
        }
    }else{
        for(int i=0;i<numsSize;i++){
            p[i]=sum/nums[i];
        }
    }
    return p;
}


int main(){
    int m;
    for(int i=0;i<10;i++){

        printf("the n = %d : %d \n",i,m);
    }
    return 0;
}