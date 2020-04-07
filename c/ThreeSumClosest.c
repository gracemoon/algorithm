/* 
问题描述：
Given an array nums of n integers and an integer target, 
find three integers in nums such that the sum is closest to target. 
Return the sum of the three integers. 
You may assume that each input would have exactly one solution.

Example:

Given array nums = [-1, 2, 1, -4], and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

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


// int abs(int a,int b){
//     int m;
//     if(a>=b){
//         m=a-b;
//     }else{
//         m=b-a;
//     }
//     return m;
// }

int threeSumClosest(int* nums, int numsSize, int target){
    quickSort(nums,0,numsSize);
    int m;
    if(numsSize==0){
        return 0;
    }else if(numsSize<=3){
        for(int i=0;i<numsSize;i++){
            m+=nums[i];
        }
    }else{
        for(int i=0;i<3;i++){
            m+=nums[i];
            if(m-target==0){
                return m;
            }
        }
        for(int i=1;i<numsSize-1;i++){
            int x=i-1;
            int y=i+1;
            while(x>=0 && y<numsSize){
                int local_m=nums[x]+nums[y]+nums[i];
                if(abs(local_m-target)<abs(m-target)){
                    m=local_m;
                    if(m-target==0){
                        return m;
                    }
                }
                if(local_m-target>0){
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
                }else{
                    while(y<numsSize){
                        if(y==numsSize-1){
                            y=y+1;
                            break;
                        }
                        if(nums[y]==nums[y+1]){
                            y=y+1;
                        }else{
                            y=y+1;
                            break;
                        }
                    }
                }
            }
        }
    }
    return m;
}

int main(){
    int nums[]={-1, 2, 1, -4};
    int res=threeSumClosest(nums,4,1);
    printf("%d\n",res);
    return 0;
}