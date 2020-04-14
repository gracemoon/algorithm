/* 
问题描述：
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3
Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2

解题思路:


*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>

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

int majorityElement(int* nums, int numsSize){
    quickSort(nums,0,numsSize-1);
    return nums[numsSize/2];
}

int majorityElement(int* nums, int numsSize){
    int current;
    int count=0;
    for(int i=1;i<numsSize;i++){
        if(count=0){
            current=nums[i];
            count++;
        }else{
            if(nums[i]==current){
                count++;
            }else{
                count--;
            }
        }
    }
    return current;
}

int main(){
    int m;
    for(int i=0;i<10;i++){

        printf("the n = %d : %d \n",i,m);
    }
    return 0;
}