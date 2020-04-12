/* 
问题描述：
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:

The number of elements initialized in nums1 and nums2 are m and n respectively.
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.
Example:

Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

Output: [1,2,2,3,5,6]


解题思路:


*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int index=m+n-1;
    int x=m-1;
    int y=n-1;
    while(index>=0){
        if(x<0){
            nums1[index--]=nums2[y--];
        }else if(y<0){
            nums1[index--]=nums1[x--];
        }else{
            if(nums1[x]>nums2[y]){
                nums1[index--]=nums1[x--];
            }else{
                nums1[index--]=nums2[y--];
            }
        }
    }
}

int main(){
    int m;
    for(int i=0;i<10;i++){

        printf("the n = %d : %d \n",i,m);
    }
    return 0;
}