/* 
题目描述
一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。

解题思路
递归和循环 F(n)=F(n-1)+F(n-2)......+F(1)
 */

#include <stdio.h>
/*一次可以跳1，2个台阶*/
int jumpFloor(int number){
    int m=0;
    if(number>2){
        m=jumpFloor(number-1)+jumpFloor(number-2); 
    }else{
        m=number;
    }
    return m;
}

/*一次可以跳1，2，，，，，，n个台阶*/
int jumpFloorII(int number){
    int m=0;
    if(number>0){
        for(int i=1;i<number;i++){
            m+=jumpFloorII(number-i);
        }
        m+=1;
    }
    return m;
}

int main(){
    int m;
    for(int i=0;i<10;i++){
        m=jumpFloor(i);
        printf("n=%i : %d\n",i,m);
    }
    for(int i=0;i<10;i++){
        m=jumpFloorII(i);
        printf("n=%i : %d\n",i,m);
    }
    return 0;
}