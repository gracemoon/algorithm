/* 
问题描述：
我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？

比如n=3时，2*3的矩形块有3种覆盖方法：

解题思路：
递归和循环，F(n)=F(n-1)+F(n-2) 
*/


#include <stdio.h>

int rectCover(int number) {
    int m=0;
    if(number>2){
        m=rectCover(number-1)+rectCover(number-2);
    }else{
        m=number;
    }
    return m;
}


int main(){
    int m;
    for(int i=0;i<10;i++){
        m=rectCover(i);
        printf("the n =%d : %d \n",i,m);
    }
    return 0;
}