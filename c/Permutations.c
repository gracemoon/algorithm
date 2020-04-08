/* 
问题描述：
Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
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
int g;

void permuteIterate(int* nums,int* arr,int** vector,int numsSize,int local_index,int* local_vector){
    for(int i=0;i<numsSize;i++){
        if(arr[i]==0){
            local_vector[local_index++]=nums[i];
            arr[i]=1;
            if(local_index==numsSize){
                int* local_arr=(int*)malloc(sizeof(int)*(numsSize));
                for(int k=0;k<numsSize;k++){
                    local_arr[k]=local_vector[k];
                }
                vector[g++]=local_arr;
                arr[i]=0;
            }else{
                permuteIterate(nums,arr,vector,numsSize,local_index,local_vector); 
                arr[i]=0;
                local_index--;
            }            
        }
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int** vector;
    int length=1;
    int* arr=(int*)malloc(sizeof(int)*numsSize);
    for(int i=numsSize;i>0;i--){
        length=length*i;
        arr[i-1]=0;
    }
    vector=(int**)malloc(sizeof(int*)*length);
    int* local_vector=(int*)malloc(sizeof(int)*(numsSize));
    permuteIterate(nums,arr,vector,numsSize,0,local_vector);
    int* columnSizes=(int*)malloc(sizeof(int)*g);
    for(int i=0;i<g;i++){
        columnSizes[i]=numsSize;
    }
    returnColumnSizes[0]=columnSizes;
    *returnSize=g;
    return vector;
}

int main(){
    int nums[]={1};
    int **returnColumnSize=(int **)malloc(sizeof(int*));
    int a=0;
    g=0;
    int** vector=permute(nums,1,&a,returnColumnSize);
    for(int i=0;i<a;i++){
        for(int j=0;j<1;j++){
            printf("%d\t",vector[i][j]);
        }
        printf("\n");
    }
    return 0;
}