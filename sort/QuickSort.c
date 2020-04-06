#include <stdio.h>

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
        if(arr[x]<arr[low]){
            x++;
        }
        if(arr[y]>arr[low]){
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


int main(){
    int arr[]={9,8,7,6,5,4,3,2,1,0};
    quickSort(arr,0,9);
    for(int i=0;i<10;i++){
        printf("%d\t",arr[i]);
    }
    return 0; 
}