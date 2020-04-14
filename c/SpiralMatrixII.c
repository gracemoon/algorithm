/* 
问题描述：
Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

Example:

Input: 3
Output:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]

解题思路:


*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes){
    *returnSize=n;
    int* columnSize=(int*)malloc(sizeof(int)*n);
    int** matrix=(int**)malloc(sizeof(int*)*n);
    for(int i=0;i<n;i++){
        columnSize[i]=n;
        matrix[i]=(int*)malloc(sizeof(int)*n);
    }
    *returnColumnSizes=columnSize;
    int x=0;
    int y=-1;
    int h=n-1;
    int v=n;
    int direct=0;
    int index=1;
    while(index<=(n*n)){
        switch(direct){
            case 0:{
                int i=0;
                while(i<v){
                    y++;
                    matrix[x][y]=index;
                    index++;
                }
                v--;
                direct=(direct+1)%4;
                break;
            }
            case 1:{
                int i=0;
                while(i<h){
                    x++;
                    matrix[x][y]=index;
                    index++;
                }
                direct=(direct+1)%4;
                h--;
                break;
            }
            case 2:{
                int i=0;
                while(i<v){
                    y--;
                    matrix[x][y]=index;
                    index++;
                }
                direct=(direct+1)%4;
                v--;
                break;
            }
            case 3:{
                int i=0;
                while(i<h){
                    x--;
                    matrix[x][y]=index;
                    index++;
                }
                direct=(direct+1)%4;
                h--;
                break;
            }
        }
    }
    return matrix;
}

int main(){
    int n=3;
    int** returnColumnSize=(int**)malloc(sizeof(int*));
    int m=0;
    int** res=generateMatrix(n,&m,returnColumnSize);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d\t",res[i][j]);
        }
        printf("\n");
    }
    return 0;
}