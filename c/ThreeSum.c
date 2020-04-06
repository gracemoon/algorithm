/* 
问题描述：
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
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

void swap(int* x,int* y){
    int temp=*x;
    *x=*y;
    *y=temp;
}

void quickSort(int* arr,int low,int high){
    int x=low;
    int y=high;
    x++;
    while(x<=y){
        if(arr[x]>arr[low] && arr[y]<arr[low]){
            swap(&arr[x],&arr[y]);
            x++;
            y--;
        }
        if(arr[x]<=arr[low]){
            x++;
        }
        if(arr[y]>=arr[low]){
            y--;
        }

    }
    swap(&arr[low],&arr[y]);
    if(y-1>low){
        quickSort(arr,low,y-1);
    }
    if(high>x){
        quickSort(arr,x,high);
    }
}


int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int** q=(int**)malloc(sizeof(int*)*numsSize);
    quickSort(nums,0,numsSize-1);
    // int* uniqueSize=(int*)malloc(sizeof(int));
    // int* p=unique(nums,numsSize,uniqueSize);
    int index;
    for(int i=0;i<numsSize;i++){
        // printf("%d\t",nums[i]);
        if(nums[i]>=0){
            index=i;
            break;
        }
    }
    int x=0;
    int y=numsSize;
    while(x<y){
        int a=nums[x]+nums[y];
        if(a>0){
            int z=x+1;
            while(nums[z]<0){
                if(a+nums[z]==0){

                }else if(){}
            }
        }else{

        }
    }
    return q;
}


void test(int* a){
    *a=1;
}
int main(){
    int arr[]={-1, 0, 1, 2, -1, -4};
    int* numSize;
    int** returnColumnSizes;
    int** res=threeSum(arr,6,numSize,returnColumnSizes);
    return 0;
}