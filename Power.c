/* 
问题描述：
给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。

保证base和exponent不同时为0

解题思路:
1、保证代码的完整性，需要考虑各种情况。

*/

#include <stdio.h>
#include <math.h>
double Power(double base, int exponent) {
    double m=base;
    if(exponent==0){
        m=1;
    }else{
      for(int i=1;i<exponent;i++){
            m*=m;
        }  
    }
    
    return m;
}

int main(){
    int m;
    for(int i=0,j=0;i<10,j<10;i++,j++){
        if(i==0 && j==0){
            continue;
        }
        m=Power(i,j);
        printf("the i = %d and j = %d: %.6lf \n",i,j,m);
    }
    return 0;
}