/* 
问题描述：
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例:

输入: [-2,1,-3,4,-1,2,1,-5,4],
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
进阶:

如果你已经实现。复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解

解题思路:


*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>

int maxSubArray(int* nums, int numsSize){
    int max=0;
    for(int i=1;i<numsSize;i++){
        if(nums[i-1]+nums[i]>nums[i]){
            if(max<nums[i-1]+nums[i]){
                max=nums[i-1]+nums[i];
            }
        }else{
            if(max<nums[i]){
                max=nums[i];
            }
        }
    }
    return max;
}

int main(){
    int m;
    for(int i=0;i<10;i++){

        printf("the n = %d : %d \n",i,m);
    }
    return 0;
}