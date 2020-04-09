/* 
问题描述：
Given an integer array nums, find the contiguous subarray (containing at least one number) 
which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

解题思路:


*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>


int maxSubArray(int* nums, int numsSize){
    int max=nums[0];
    int local_max=0;
    for(int i=0;i<numsSize;i++){
        if(local_max+nums[i]>=local_max){
            local_max+=nums[i];
            if(max<local_max){
                max=local_max;
            }
        }else{
            local_max+=nums[i];
            if(max<local_max){
                max=local_max;
            }
            if(local_max<0){
                local_max=0;
            }
            
        }
    }
    return max;
}

int main(){
    int m[]={-2,1,-3,4,-1,2,1,-5,4};
    int res=maxSubArray(m,9);
    printf("%d",res);
    return 0;
}