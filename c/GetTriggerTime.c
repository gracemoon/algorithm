/* 
问题描述：


解题思路:


*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getTriggerTime(int** increase, int increaseSize, int* increaseColSize, int** requirements, int requirementsSize, int* requirementsColSize, int* returnSize){
    int* trigger=(int*)malloc(sizeof(int)*requirementsSize);
    for(int i=0;i<requirementsSize;i++){
        trigger[i]=-1;
    }
    int** score=(int**)malloc(sizeof(int)*(increaseSize+1));
    score[0]=(int*)malloc(sizeof(int)*3);
    score[0][0]=0;
    score[0][1]=0;
    score[0][2]=0;
    for(int i=1;i<=increaseSize;i++){
        score[i][0]+=score[i-1][0];
        score[i][1]+=score[i-1][1];
        score[i][2]+=score[i-1][2];
    }
    for(int j=0;j<requirementsSize;j++){
        for(int i=increaseSize;i>=0;i--){
            if(requirements[j][0]>=score[i][0] && requirements[j][1]>=score[i][1]  && requirements[j][2]>=score[i][2] ){
                trigger[j]=i;
                break;
            }
        }
    }
    *returnSize=requirementsSize;
    return trigger;
}

int main(){
    int m;
    for(int i=0;i<10;i++){

        printf("the n = %d : %d \n",i,m);
    }
    return 0;
}