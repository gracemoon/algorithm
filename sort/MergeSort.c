#include <stdio.h>
#include <malloc.h>


int MergeSort(int* nums,int* returnNums,int low,int high,int size){
    int* temp=(int*)malloc(sizeof(int)*size);
    if(high==low){
        returnNums[low]=nums[low];
    }else{
        int mid=(high+low)/2;
        MergeSort(nums,temp,low,mid,size);
        MergeSort(nums,temp,mid+1,high,size);
        int x=low;
        int y=mid+1;
        while(x<=mid && y<=high){
            if(temp[x]<temp[y]){
                returnNums[low++]=temp[x++];
            }else{
                returnNums[low++]=temp[y++];
            }
        }
        while(x<=mid){
            returnNums[low++]=temp[x++];
        }
        while(y<=high){
            returnNums[low++]=temp[y++];
        }
    }
    return 0;
}


int main(){
    int m[]={7,3,9,4,5,4,2,1,6,8};
    int a=MergeSort(m,m,0,9,10);
    for(int i=0;i<10;i++){
        printf("%d\t",m[i]);
    }
    return 0;
}