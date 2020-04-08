/* 
问题描述：
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

解题思路:


*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int BinarySearch(int* nums,int size,int target){
    int low=0;
    int high=size-1;
    int index=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]==target){
            index=mid;
            break;
        }else if(target>nums[mid]){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return index;
}

int search(int* nums, int numsSize, int target){
    int low=0;
    int high=numsSize-1;
    int index=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]==target){
            index=mid;
            break;
        }else{
            if(nums[mid]>nums[low]){
                if(target>=nums[low] && target<=nums[mid-1]){
                    high=mid-1;
                }else{
                    low=mid+1;
                }
            }else if(nums[mid]==nums[low]){
                if(mid<high){
                    if(target>=nums[mid+1] && target<=nums[high]){
                        low=mid-1;
                    }else{
                        break;
                    }
                }else{
                    break;
                }
            }else{
                if(mid<high){
                    if(target>=nums[mid+1] && target<=nums[high]){
                        low=mid+1;
                    }else{
                        high=mid-1;
                    }
                }else{
                    if(target>=nums[low] || target <=nums[mid-1]){
                        high=mid-1;
                    }else{
                        break;
                    }
                }
            }
        }
    }
    return index;
}

int main(){
    int arr[]={5,1,2,3,4};
    int index=search(arr,5,4);
    printf("%d",index);
    return 0;
}