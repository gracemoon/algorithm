#ifndef QUICKSORT
#define QUICKSORT

#include <stdio.h>

void quickSort(int* arr,int x,int y){
    int i=x;
    int j=y;
    while(i<=j){
        if(arr[i]>arr[x] && arr[j]<arr[x]){
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
        if(arr[i]<=arr[x]){
            i++;
        }
        if(arr[j]>=arr[x]){
            j--;
        }
        // printf("j --- %d\n",j);
    }
    
    int temp=arr[j];
    arr[j]=arr[x];
    arr[x]=temp;
    for(int k=0;k<y+1;k++){
        printf("%d",arr[k]);
    }
    printf("\n");
    if(x<j-1){
       quickSort(arr,x,j-1); 
    }
    if(j+1<y){
       quickSort(arr,j+1,y);  
    }
    
}

#endif