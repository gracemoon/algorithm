/* 
问题描述：
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
Note:
Assume we are dealing with an environment 
which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. 
For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

解题思路:
1、可以不使用long,m等于当天数字,判断m与MAX/10的大小,或者m与MIN/10的大小。

*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int reverse(int x){
    int m=0;
    int Max=2147483647;
    int Min=-2147483648;
    while(x!=0){
        int y=x%10;
        if(m>Max/10 || (m==Max/10 && y>7)){
            return 0;
        }else if(m<Min/10 || (m==Min/10 && y<-8)){
            return 0;
        }else{
            m=m*10+y;
            x=x/10;
        }
    }
    // if(m>2147483647 || m<-2147483648){
    //     return 0;
    // }
    return m;
}


int main(){
    int m;
    for(int i=0;i<10;i++){

        printf("the n = %d : %d \n",i,m);
    }
    return 0;
}