#include <stdio.h>

void quickSort(int* arr,int x,int y){
    int i=x;
    int j=y;
    while(i<j){
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
    }
    int temp=arr[j];
    arr[j]=arr[x];
    arr[x]=temp;
    for(int k=0;k<8;k++){
        printf("%d",arr[k]);
    }
    printf("\n");
    if(x<i-1){
       quickSort(arr,x,j-1); 
    }
    if(j+1<y){
       quickSort(arr,j+1,y);  
    }
    
}

int main(){
    // int array[9]={4,1,5,2,7,3,9,8,6};
    int array[9]={4,5,1,6,2,7,3,8};
    quickSort(array,0,7);
    for(int i=0;i<8;i++){
        printf("%d",array[i]);
    }
    return 0;
}