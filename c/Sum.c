/* 
问题描述：
求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。

解题思路:


*/

#include <stdio.h>

int Sum_Solution(int n) {
    int sum=n;
    sum && (sum+=Sum_Solution(n-1));
    return sum;
}

int main(){
    int n=10;
    int m=Sum_Solution(n);
    printf("n : %d",(m>0));
    return 0;
}