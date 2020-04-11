/* 
问题描述：
Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

解题思路:


*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int count=1;
    for(int i=0;i<numsSize;i++){
        count*=2;
    }
    *returnSize=count;
    int** p=(int**)malloc(sizeof(int*)*count);
    int* columnSize=(int*)malloc(sizeof(int));
    for(int i=0;i<=numsSize;i++){
        int* local_p=(int*)malloc(sizeof(int)*i);
        for(int j=0;j<i;j++){
            for(int k=j;k<numsSize-i-1;k++){
                local_p[j]=
            }
        }
        p[i]=local_p;
    }
}

int main(){
    int m;
    return 0;
}