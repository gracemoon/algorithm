#include <stdio.h>
void BubbleSort(int* nums,int numsSize){
    for(int i=0;i<numsSize-1;i++){
        for(int j=0;j<numsSize-i-1;j++){
            if(nums[j]>nums[j+1]){
                int temp=nums[j];
                nums[j]=nums[j+1];
                nums[j+1]=temp;
            }
        }
    }
}

int main(){
    int nums[]={2,5,3,6,1,9,8,7,4};
    BubbleSort(nums,9);
    for(int i=0;i<9;i++){
        printf("%d\t",nums[i]);
    }
    return 0;
}