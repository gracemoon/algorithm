/* 
问题描述：
给你一个整数数组 nums 和一个整数 k ，请你返回 非空 子序列元素和的最大值，子序列需要满足：子序列中每两个 相邻 的整数 nums[i] 和 nums[j] ，它们在原数组中的下标 i 和 j 满足 i < j 且 j - i <= k 。

数组的子序列定义为：将数组中的若干个数字删除（可以删除 0 个数字），剩下的数字按照原本的顺序排布。

 

示例 1：

输入：nums = [10,2,-10,5,20], k = 2
输出：37
解释：子序列为 [10, 2, 5, 20] 。
示例 2：

输入：nums = [-1,-2,-3], k = 1
输出：-1
解释：子序列必须是非空的，所以我们选择最大的数字。
示例 3：

输入：nums = [10,-2,-10,-5,20], k = 2
输出：23
解释：子序列为 [10, -2, -5, 20] 。
 

提示：

1 <= k <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4

解题思路:


*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>

int constrainedSubsetSum(int* nums, int numsSize, int k){
    int** record=(int**)malloc(sizeof(int*)*2);
    int** arr=(int**)malloc(sizeof(int*)*2);
    record[0]=(int*)malloc(sizeof(int)*numsSize);
    record[1]=(int*)malloc(sizeof(int)*numsSize);
    arr[0]=(int*)malloc(sizeof(int)*numsSize);
    arr[1]=(int*)malloc(sizeof(int)*numsSize);
    record[0]=0;
    record[0]=-1;
    record[0]=nums[0];
    record[0]=0;
    for(int i=1;i<numsSize;i++){
        if(record[0][i-1]>record[1][i-1]){
            record[0][i]=record[0][i-1];
            arr[0][i]=arr[0][i-1];
            if(arr[0][i-1]==-1){
                record[1][i]=record[0][i-1]+nums[i];
                arr[1][i]=i;
            }else{
                if(i-arr[0][i-1]<=k){
                    record[1][i]=record[0][i-1]+nums[i];
                    arr[1][i]=i;
                }else{
                    record[1][i]=record[1][i-1]+nums[i];
                    arr[1][i]=i;
                }
            }
        }else{
            record[0][i]=record[1][i-1];
            arr[0][i]=arr[1][i-1];
            record[1][i]=record[1][i-1]+nums[i];
            arr[1][i]=i;
        }
    }
    int ans;
    if(record[0][numsSize-1]>record[1][numsSize-1]){
        ans=record[0][numsSize-1];
    }else{
        ans=record[1][numsSize-1];
    }
    return ans;
}

int constrainedSubsetSum(int* nums, int numsSize, int k){
    int* record=(int*)malloc(sizeof(int)*numsSize);
    record[0]=nums[0];
    for(int i=1;i<numsSize;i++){
        int x=i;
        int local_max=nums[i];
        while(x>=0 && x>=i-k){
            if(record[x]+nums[i]>local_max){
                local_max=record[x]+nums[i];
            }
            x--;
        }
        record[i]=local_max;
    }
    return record[numsSize-1];
}

int constrainedSubsetSum(int* nums, int numsSize, int k){
    int* record=(int*)malloc(sizeof(int)*numsSize+1);
    int* stack=(int*)malloc(sizeof(int)*numsSize);
    int top=-1;
    int bottom=0;
    record[0]=0;
    stack[++top]=0;
    for(int i=1;i<=numsSize;i++){
        if(stack[top]-stack[bottom]>=k-1){
            bottom++;
        }
        if(record[stack[bottom]]>0){
            record[i]=record[stack[bottom]]+nums[i-1];
        }
        while(top>=bottom-1){
            if(top==bottom-1 || record[stack[top]]>record[i]){
                stack[++top]=i;
                break;
            }
            top--;
        }

    }
    return record[numsSize];
}

int main(){
    int m;
    for(int i=0;i<10;i++){
        printf("the n = %d : %d \n",i,m);
    }
    return 0;
}