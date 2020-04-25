/* 
问题描述：


解题思路:


*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>

int* recordFunction(int* time,int timeSize,int x){
    int* arr=(int*)malloc(sizeof(int)*timeSize);
    int local=x;
    int sum=0;
    for(int i=0;i<timeSize;i++){
        if(i<x){
            arr[i]=0;
        }else{
            if(time[i]>time[local]){
                local=i;
            }

            sum+=time[i];
            arr[i]=sum-time[local];
        }
    }
    return arr;
}

int minTime(int* time, int timeSize, int m){
    int** arr=(int**)malloc(sizeof(int)*timeSize);
    for(int i=0;i<timeSize;i++){
        arr[i]=recordFunction(time,timeSize,i);
    }
    int** record=(int**)malloc(sizeof(int*)*m);
    for(int i=0;i<m;i++){
        if(i==0){
            record[0]=arr[0];
            continue;
        }
        record[i]=(int*)malloc(sizeof(int)*timeSize);
        for(int j=0;j<timeSize;j++){
            int x=0;
            int local_min=record[i-1][j];
            while(x<=j){
                int pre;
                if(x==0){
                    pre=0;
                }else{
                    pre=record[i-1][x-1];
                }
                int temp=pre+arr[x][j];
                if(temp<local_min){
                    local_min=temp;
                }
                x++;
            }
            record[i][j]=local_min;
        }
        
    }
    return record[m-1][timeSize-1];
}

int main(){
    int arr[]={1,2,3,3};
    int m=2;
    int ans=minTime(arr,4,m);
    printf("%d",ans);

    return 0;
}