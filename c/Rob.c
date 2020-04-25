/* 
问题描述：
你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。

示例 1:

输入: [1,2,3,1]
输出: 4
解释: 偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
     偷窃到的最高金额 = 1 + 3 = 4 。
示例 2:

输入: [2,7,9,3,1]
输出: 12
解释: 偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
     偷窃到的最高金额 = 2 + 9 + 1 = 12 。

解题思路:


*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>

int tree(int* nums,int index,int numsSize,int flag){
    int a;
    int b;
    int current;
    if(flag==0){
        if(index==numsSize){
            current=1;
        }else{
            a=tree(nums,index+1,numsSize,flag);
            flag=1;
            b=tree(nums,index+1,numsSize,flag)+1;
            if(a<b){
                current=a;
            }else{
                current=b;
            }
            
        }
    }else{
        if(index==numsSize){
            current=0;
        }else{
            current=tree(nums,index+1,numsSize,flag);
        }
    }
    return current;
}

int rob(int* nums, int numsSize){
    if(numsSize==0){
        return 0;
    }
    int ans=tree(nums,0,numsSize,0);
    return ans;
}


int rob(int* nums, int numsSize){
    if(numsSize==0){
        return 0;
    }
    int** record=(int**)malloc(sizeof(int*)*2);
    for(int i=0;i<4;i++){
        record[i]=(int*)malloc(sizeof(int)*(numsSize+1));
    }
    record[1][0]=0;
    record[1][1]=0;
    record[1][2]=nums[0];
    record[1][3]=nums[0]; 
    for(int i=2;i<=numsSize;i++){
        if(i==numsSize){
            record[i][2]=record[i-1][2];
            record[i][3]=record[i-1][3];
        }else{
            record[i][3]=record[i-1][2]+nums[i-1];
            if(record[i-1][2]>record[i-1][3]){
                record[i][2]=record[i-1][2];
            }else{
                record[i][2]=record[i-1][3];
            }
        }
        record[i][1]=record[i-1][0]+nums[i-1];
        if(record[i-1][0]>record[i-1][1]){
            record[i][0]=record[i-1][0];
        }else{
            record[i][0]=record[i-1][1];
        }
    }
    int ans1;
    if(record[numsSize][0]>record[numsSize][1]){
        ans1=record[numsSize][0];
    }else{
        ans1=record[numsSize][1];
    }
    int ans2;
    if(record[numsSize][2]>record[numsSize][3]){
        ans2=record[numsSize][2];
    }else{
        ans2=record[numsSize][3];
    }
    if(ans1<ans2){
        ans1=ans2;
    }
    return ans1;
}

int main(){
    int m;
    for(int i=0;i<10;i++){

        printf("the n = %d : %d \n",i,m);
    }
    return 0;
}