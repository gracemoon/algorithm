/* 
数组去重复
 */
/* 
问题描述：
Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Example 1:

Given nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.

It doesn't matter what you leave beyond the returned length.
Example 2:

Given nums = [0,0,1,1,1,2,2,3,3,4],

Your function should return length = 5, with the first five elements of nums being modified to 0, 1, 2, 3, and 4 respectively.

It doesn't matter what values are set beyond the returned length.

解题思路:


*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int* unique(int* arr,int size,int* returnSize){
    int* p=(int*)malloc(sizeof(int)*size);
    int index=0;
    for(int i=0;i<size;i++){
        if(i==size-1){
            p[i]=1;
            index++;
        }else if(arr[i]==arr[i+1]){
            p[i]=0;
        }else{
            p[i]=1;
            index++;
        }
    }
    *returnSize=index;
    int* q=(int*)malloc(sizeof(int)*index);
    int x=0;
    for(int i=0;i<size;i++){
        if(p[i]==1){
            q[x]=arr[i];
            x++;
        }
    }
    return q;
}

//不适用额外的空间，在原始组数上进行去重。
int removeDuplicates(int* nums, int numsSize){
    int index=0;
    for(int i=0;i<numsSize;i++){
        if(i==numsSize-1){
            nums[index]=nums[i];
            index++;
        }else if(nums[i]==nums[i+1]){
            continue;
        }else{
            nums[index]=nums[i];
            index++;
        }
    }
    return index;
}