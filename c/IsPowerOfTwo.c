/* 
问题描述：
Given an integer, write a function to determine if it is a power of two.

Example 1:

Input: 1
Output: true 
Explanation: 20 = 1
Example 2:

Input: 16
Output: true
Explanation: 24 = 16
Example 3:

Input: 218
Output: false

解题思路:


*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>

bool isPowerOfTwo(int n){
    int base=1;
    bool result=false;
    while(base<=n){
        if(base==n){
            result=true;
            break;
        }else{
            base=base*2;
        }
    }
    return result;
}

int main(){
    int m;
    for(int i=0;i<10;i++){

        printf("the n = %d : %d \n",i,m);
    }
    return 0;
}