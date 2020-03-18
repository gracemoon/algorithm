/* 
问题描述：
在一个长度为n的数组里的所有数字都在0到n-1的范围内。 
数组中某些数字是重复的，但不知道有几个数字是重复的。
也不知道每个数字重复几次。
请找出数组中任意一个重复的数字。 
例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是第一个重复的数字2。

解题思路:


*/

#include <stdio.h>
#include "utils/QuickSort.h"
#include <stdbool.h>

bool duplicate(int numbers[], int length, int* duplication) {
    quickSort(numbers,0,length-1);
    for(int i=0;i<length;i++){
        printf("%d",numbers[i]);
    }
}

int main(){
    int arr[10]={0,1,3,5,2,5,2,4,5,6};
    
    return 0;
}