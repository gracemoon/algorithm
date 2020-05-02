/* 
问题描述：


解题思路:


*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>

int longestConsecutive(int* nums, int numsSize){
    int max=0;
    for(int i=0;i<numsSize;i++){
        if(max<nums[i]){
            max=nums[i];
        }
    }
    int* arr=(int*)malloc(sizeof(int)*(max+1));
    for(int i=0;i<=max;i++){
        arr[i]=0;
    }
    for(int i=0;i<numsSize;i++){
        arr[nums[i]]=1;
    }
    int max_length=0;
    int count=0;
    for(int i=0;i<=max;i++){
        if(arr[i]==1){
            count++;
            if(max_length<count){
                max_length=count;
            }
        }else{
            if(max_length<count){
                max_length=count;
            }
            count=0;
        }
    }
    return max_length;
}

int main(){
    int m[]={0};
    int ans=longestConsecutive(m,1);
    printf("%d",ans);
    return 0;
}