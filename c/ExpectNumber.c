/* 
问题描述：


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

int expectNumber(int* scores, int scoresSize){
    quickSort(scores,0,scoresSize-1);
    int index=scoresSize-1;
    int sum=9;
    int local_same=0;
    while(index>0){
        if(scores[index]!=scores[index-1]){
            index--;
            sum+=1;
        }else{
            index--;
            local_same+=1;
        }
    }
    return sum;
}

int main(){
    int m;
    for(int i=0;i<10;i++){

        printf("the n = %d : %d \n",i,m);
    }
    return 0;
}