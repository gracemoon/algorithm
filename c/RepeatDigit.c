/* 
问题描述：
//找出重复数字

解题思路:


*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>

void digit(int* arr,int length,int* returnSize,int* ans){
    int* record=(int*)malloc(sizeof(int)*100);
    for(int i=0;i<100;i++){
        record[i]=0;
    }
    int* ans=(int*)malloc(sizeof(int)*100);  
    for(int i=0;i<length;i++){
        record[arr[i]]++;
    }
    int index=0;
    for(int i=0;i<100;i++){
        if(record[i]>1){
            ans[index]=i;
            index++;
        }
    }
    *returnSize=index;
}

int main(){
    
    return 0;
}