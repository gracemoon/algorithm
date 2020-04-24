/* 
问题描述：
给你一个整数数组 nums ，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字）。

 

示例 1:

输入: [2,3,-2,4]
输出: 6
解释: 子数组 [2,3] 有最大乘积 6。
示例 2:

输入: [-2,0,-1]
输出: 0
解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。

解题思路:


*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>

int maxProduct(int* nums, int numsSize){
    if(numsSize==0){
        return 0;
    }
    int* lows=(int*)malloc(sizeof(int)*numsSize);
    int max=nums[0];
    lows[0]=nums[0];
    for(int i=1;i<numsSize;i++){
        int temp=nums[i];
        int low=temp;
        if(temp<nums[i]*nums[i-1]){
            temp=nums[i]*nums[i-1];
        }
        if(temp<nums[i]*lows[i-1]){
            temp=nums[i]*lows[i-1];
        }
        if(low>nums[i]*nums[i-1]){
            low=nums[i]*nums[i-1];
        }
        if(low>nums[i]*lows[i-1]){
            low=nums[i]*lows[i-1];
        }
        nums[i]=temp;
        lows[i]=low;
        if(max<nums[i]){
            max=nums[i];
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