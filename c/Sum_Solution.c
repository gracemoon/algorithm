/* 
问题描述：
求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。

解题思路:


*/

#include <stdio.h>

int Sum_Solution(int n) {
    
    int m=0;
    for(int i=1;i<=n;i++){
        m+=i;
    }
    printf("m : %d\n",m);
    n<<=2;
    n>>=2;
    return n;
}

int main(){
    int n=10;
    int m=Sum_Solution(n);
    printf("n : %d",(m>0));
    return 0;
}