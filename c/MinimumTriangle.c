/* 
问题描述：
给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。

例如，给定三角形：

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。

说明：

如果你可以只使用 O(n) 的额外空间（n 为三角形的总行数）来解决这个问题，那么你的算法会很加分。

解题思路:


*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>

int minimumTotal(int** triangle, int triangleSize, int* triangleColSize){
    if(triangleSize==0){
        return 0;
    }
    for(int i=1;i<triangleSize;i++){
        for(int j=0;j<triangleColSize[i];j++){
            int local_max;
            if(j>0){
                if(j<triangleColSize[i-1]){
                    if(triangle[i-1][j-1]>triangle[i-1][j]){
                        local_max=triangle[i-1][j];
                    }else{
                        local_max=triangle[i-1][j-1];
                    }
                }else{
                    local_max=triangle[i-1][j-1];
                }
            }else{
                if(j<triangleColSize[i-1]){
                    local_max=triangle[i-1][j];
                }
            }
            triangle[i][j]+=local_max;
        }
    }
    int max=triangle[triangleSize-1][0];
    for(int i=1;i<triangleColSize[triangleSize-1];i++){
        if(max>triangle[triangleSize-1][i]){
            max=triangle[triangleSize-1][i];
        }
    }
    return max;
}

int main(){
    int m;
    for(int i=0;i<10;i++){

        printf("the n = %d : %d \n",i,m);
    }
    return 0;
}