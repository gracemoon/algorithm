/* 
问题描述：
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Example 1:

Input: [3,2,1,5,6,4] and k = 2
Output: 5
Example 2:

Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4
Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.

解题思路:


*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>


void quickSort(int* arr,int low,int high){
    int x=low;
    int y=high;
    x++;
    while(x<=y){
        if(arr[x]>arr[low] && arr[y]<arr[low]){
            // swap(&arr[x],&arr[y]);
            int temp=arr[x];
            arr[x]=arr[y];
            arr[y]=temp;
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
    int temp=arr[low];
    arr[low]=arr[y];
    arr[y]=temp;
    if(y-1>low){
        quickSort(arr,low,y-1);
    }
    if(high>x){
        quickSort(arr,x,high);
    }
}

int findKthLargest1(int* nums, int numsSize, int k){
    quickSort(nums,0,numsSize-1);
    int current;
    for(int i=numsSize-1;i>=0;i--){
        if(k==0){
            break;
        }
        current=nums[i];
        k--;
    }
    return current;
}

void BubbleSort(int* nums,int numsSize){
    for(int i=0;i<numsSize-1;i++){
        for(int j=0;j<numsSize-i-1;j++){
            if(nums[j]>nums[j+1]){
                int temp=nums[j];
                nums[j]=nums[j+1];
                nums[j+1]=temp;
            }
        }
    }
}

int findKthLargest2(int* nums, int numsSize, int k){
    for(int i=0;i<k;i++){
        for(int j=0;j<numsSize-i-1;j++){
            if(nums[j]>nums[j+1]){
                int temp=nums[j];
                nums[j]=nums[j+1];
                nums[j+1]=temp;
            }
        }
    }
    return nums[numsSize-k];
}


int main(){
    int m;
    for(int i=0;i<10;i++){

        printf("the n = %d : %d \n",i,m);
    }
    return 0;
}