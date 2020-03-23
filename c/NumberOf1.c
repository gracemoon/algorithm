/* 
问题描述：
输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。

解题思路
1、位运算,算数右移>>1,复数以补码形式表示，位运算是直接对二进制表示进行操作，不用手动求补码形式
2、考虑复数

*/

#include <stdio.h>
#include <string.h>

int  NumberOf1(int n) {
    int m=0;
    if (n<0){
        unsigned int b=n;
        while(b){
            if(b&1){
                m+=1;
            }
            b=b>>1;
        }
    }else{
       while(n){
            if(n&1){
                m+=1;
            }
            n=n>>1;
        } 
    }
    return m;
}

int main(){
    int m;
    for(int i=-10;i<10;i++){
        m=NumberOf1(i);
        printf("the n =%d : %d \n",i,m);
    }

    return 0;
}

