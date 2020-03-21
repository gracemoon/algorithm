/* 
问题描述：
给你一根长度为n的绳子，请把绳子剪成整数长的m段（m、n都是整数，n>1并且m>1），
每段绳子的长度记为k[0],k[1],...,k[m]。请问k[0]xk[1]x...xk[m]可能的最大乘积是多少？
例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。

解题思路:


*/

#include <stdio.h>
#include <stdbool.h>


int g;

int cutRope1(int number) {
    int max=1;

    for(int i=1;i<=number;i++){
        if(i!=g){
            int local_max;
            if(i==number){
                local_max=i;
            }else{
                local_max=i*cutRope1(number-i);
            }
            if(max<local_max){
                max=local_max;
            } 
        }
        
    }
    return max;
}

int cutRope2(int number) {
    g=number;
    int max=cutRope1(number);
    return max;
}

int cutRope(int number){
    int max[number];
    for(int i=1;i<=number;i++){
        max[i]=1;
        for(int j=1;j<=i;j++){
            if(j==number){
                continue;
            }
            int local;
            if(i==j){
                local=j;
            }else{
                local=max[j]*(i-j);
            }
            if(local>max[i]){ 
                max[i]=local;
            }
        }
    }
    return max[number];
}


int main(){
    int m=cutRope(8);
    printf("%d",m);
    return 0;
}