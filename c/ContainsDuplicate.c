/* 
问题描述：
Given an array of integers, find if the array contains any duplicates.

Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

Example 1:

Input: [1,2,3,1]
Output: true
Example 2:

Input: [1,2,3,4]
Output: false
Example 3:

Input: [1,1,1,3,3,4,3,2,4,2]
Output: true

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
        if(nums[x]>nums[low] && nums[y]<nums[x]){
            int t=nums[x];
            nums[x]=nums[y];
            nums[y]=t;
        }
        if(nums[x]<=nums[low]){
            x++;
        }
        if(nums[y]>=nums[low]){
            y--;
        }
    }
    int t=nums[y];
    nums[y]=nums[low];
    nums[low]=t;
    if(y-1>low){
        quickSort(nums,low,y-1);
    }
    if(high>x){
        quickSort(nums,x,high);
    }
}


int MergeSort(int* nums,int* returnNums,int low,int high,int size){
    int* temp=(int*)malloc(sizeof(int)*size);
    if(high==low){
        returnNums[low]=nums[low];
    }else{
        int mid=(high+low)/2;
        int a=MergeSort(nums,temp,low,mid,size);
        if(a==1){
            return 1;
        }
        int b=MergeSort(nums,temp,mid+1,high,size);
        if(b==1){
            return 1;
        }
        int x=low;
        int y=mid+1;
        while(x<=mid && y<=high){
            if(temp[x]==temp[y]){
                return 1;
            }else if(temp[x]<temp[y]){
                returnNums[low++]=temp[x++];
            }else{
                returnNums[low++]=temp[y++];
            }
        }
        while(x<=mid){
            returnNums[low++]=temp[x++];
        }
        while(y<=high){
            returnNums[low++]=temp[y++];
        }
    }
    return 0;
}

bool containsDuplicate(int* nums, int numsSize){
    if(numsSize==0){
        return false;
    }
    int flag=MergeSort(nums,nums,0,numsSize-1,numsSize);
    if(flag==1){
        return true;
    }
    return false;
}

bool containsDuplicate1(int* nums, int numsSize){
    if(numsSize==0){
        return false;
    }
    quickSort(nums,0,numsSize-1);
    for(int i=0;i<numsSize-1;i++){
        if(nums[i]==nums[i+1]){
            return true;
        }
    }
    return false;
}


int main(){
    int m[]={6,7,3,2,1,9,0,5,4,8};
    quickSort(m,0,9);
    for(int i=0;i<10;i++){
        printf("%d\t",m[i]);
    }
    return 0;
}