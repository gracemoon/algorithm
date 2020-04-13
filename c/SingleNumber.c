/* 
问题描述：
Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,1]
Output: 1
Example 2:

Input: [4,1,2,1,2]
Output: 4

解题思路:


*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>

void quickSort(int* nums,int low,int high){
    int x=low+1;
    int y=high;
    while(x<=y){
        if(nums[x]>nums[low] && nums[y]<nums[low]){
            int temp=nums[x];
            nums[x]=nums[y];
            nums[y]=temp;
        }
        if(nums[x]<=nums[low]){
            x++;
        }
        if(nums[y]>=nums[low]){
            y--;
        }

    }
    int temp=nums[low];
    nums[low]=nums[y];
    nums[y]=temp;
    if(y-1>low){
        quickSort(nums,low,y-1);
    }
    if(x<high){
        quickSort(nums,x,high);
    }
}

int singleNumber(int* nums, int numsSize){
    quickSort(nums,0,numsSize-1);
    for(int i=0;i<numsSize;){
        if(i==numsSize-1 || nums[i]!=nums[i+1]){
            return nums[i];
        }else{
            i+=2;
        }
    }
    return 0;
}

int main(){
    int m[]={4,1,2,1,2};
    quickSort(m,0,4);
    for(int i=0;i<5;i++){
        printf("%d\t",m[i]);
    }
    return 0;
}