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
    int* columnSize=(int*)malloc(sizeof(int)*count);
    columnSize[0]=0;
    int* local_p;
    p[0]=local_p;
    int g=1;
    
    for(int i=1;i<=numsSize;i++){
        count=g;
        int j=0;
        while(j<count){
            local_p=(int*)malloc(sizeof(int)*(columnSize[j]+1));
            
            int k=0;
            for(;k<columnSize[j];k++){
                local_p[k]=p[j][k];
            }
            local_p[k]=nums[i-1];
            columnSize[g]=columnSize[j]+1;
            p[g++]=local_p;
            j++;
        }
        
    }
    *returnColumnSizes=columnSize;
    return p;
}

int main(){
    int m[]={1,2,3};
    int returnSize=0;
    int** returnColumnSize=(int**)malloc(sizeof(int*));
    int** res=subsets(m,3,&returnSize,returnColumnSize);
    for(int i=0;i<returnSize;i++){
        for(int j=0;j<returnColumnSize[0][i];j++){
            printf("%d\t",res[i][j]);
        }
        printf("\n");
    }
    return 0;
}