/* 
问题描述：
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example 1:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:

Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]Given a matrix of m x n elements (m rows, n columns), 
return all elements of the matrix in spiral order.

Example 1:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:

Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]

解题思路:


*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    *returnSize=matrixSize*(matrixColSize[0]);
    int* p=(int*)malloc(sizeof(int)*(*returnSize));
    int index=0;
    int direct=0;
    int h=*matrixColSize;
    int v=matrixSize-1;
    int x=-1;
    int y=0;
    while(index<*returnSize){
        switch(direct){
            case 0:
{                int i=0;
                while(i<h){
                    x++;
                    p[index++]=matrix[y][x];
                    i++;
                }
                h--;
                break;}
            case 1:
{                int i=0;
                while(i<v){
                    y++;
                    p[index++]=matrix[y][x];
                    i++;
                }
                v--;
                break;}
            case 2:
{                int i=0;
                while(i<h){
                    x--;
                    p[index++]=matrix[y][x];
                    i++;
                }
                h--;
                break;}
            case 3:
{                int i=0;
                while(i<v){
                    y--;
                    p[index++]=matrix[y][x];
                    i++;
                }
                v--;
                break;}
        }
        direct=(direct+1)%4;
    }
    return p;
}

int main(){

    int** nums=(int**)malloc(sizeof(int*)*3);
    int index=1;
    for(int i=0;i<3;i++){
        int* a=(int*)malloc(sizeof(int)*3);
        for(int j=0;j<4;j++){
            a[j]=index;
            index++;
        }
        nums[i]=a;
    }
    int b=0;
    int *returnSize=&b;
    int columnSize[]={4,4,4};
    int* p=spiralOrder(nums,3,columnSize,returnSize);
    for(int i=0;i<index-1;i++){
        printf("%d\t",p[i]);
    }
    return 0;
}