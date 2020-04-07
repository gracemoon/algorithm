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
    int** p=(int**)malloc(sizeof(int*)*numsSize*10);
    if(numsSize==0){
        *returnSize=0;
        return p;
    }
    quickSort(nums,0,numsSize-1);
    int index=0;
    int pre=0;
    for(int i=1;i<numsSize-1;i++){
        if(i>1 && nums[i]==nums[i-1] && nums[i-2]==nums[i-1]){
            continue;
        }else if(i>1 && nums[i]==nums[i-1] && nums[i-2]!=nums[i-1]){
            int x=i-1;
            int y=i+1;
            while(y<numsSize){
                int a=nums[i]+nums[x]+nums[y];
                if(a==0){
                    int* local_p=(int*)malloc(sizeof(int)*3);
                    local_p[0]=nums[x];
                    local_p[1]=nums[i];
                    local_p[2]=nums[y];
                    p[index++]=local_p;
                    if(y==numsSize-1){
                        break;
                    }
                    while(y<numsSize){
                        if(y==numsSize-1){
                            y=numsSize;
                            break;
                        }
                        if(nums[y]==nums[y+1]){
                            y=y+1;
                        }else{
                            y=y+1;
                            break;
                        }
                    }
                }else{
                    y=y+1;
                }
            }
        }else{
            int x=i-1;
            int y=i+1;
            while(x>=0 && y<numsSize){
                int a=nums[i]+nums[x]+nums[y];
                if(a==0){
                    int* local_p=(int*)malloc(sizeof(int)*3);
                    local_p[0]=nums[x];
                    local_p[1]=nums[i];
                    local_p[2]=nums[y];
                    p[index++]=local_p;
                    if(x==0 || y==numsSize-1){
                        break;
                    }
                    while(x>=0){
                        if(x==0){
                            x=x-1;
                            break;
                        }
                        if(nums[x]==nums[x-1]){
                            x=x-1;
                        }else{
                            x=x-1;
                            break;
                        }
                    }
                    while(y<numsSize){
                        if(y==numsSize-1){
                            y=numsSize;
                            break;
                        }
                        if(nums[y]==nums[y+1]){
                            y=y+1;
                        }else{
                            y=y+1;
                            break;
                        }
                    }
                }else if(a>0){
                    x=x-1;
                }else{
                    y=y+1;
                }
            }
        }
    }
    *returnSize=index;
    *returnColumnSizes=(int*)malloc(sizeof(int)*index);
    for(int i=0;i<index;i++){
        (*returnColumnSizes)[i]=3;
    }
    return p;
}

int main(){
    // int arr[]={-7,-4,-6,6,4,-6,-9,-10,-7,5,3,-1,-5,8,-1,-2,-8,-1,5,-3,-5,4,2,-5,-4,4,7};
    int arr[]={-1,0,1,2,-1,-4};
    int a=0;
    int* numSize=&a;
    int** returnColumnSizes=(int**)malloc(sizeof(int*));
    int** res=threeSum(arr,27,numSize,returnColumnSizes);
    for(int i=0;i<*numSize;i++){
        for(int j=0;j<(*returnColumnSizes)[i];j++){
            printf("%d\t",res[i][j]);
        }
        printf("\n");
    }
    return 0;
}