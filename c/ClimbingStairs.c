/* 
问题描述：


解题思路:


*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>

int climbStairs1(int n){
    int a=0;
    if(n==0){
        return 0;
    }else if(n==1){
        return 1;
    }else if(n==2){
        return 2;
    }else{
        a=climbStairs1(n-1)+climbStairs1(n-2);
    }
    return a;
}

int climbStairs(int n){
    int F_1=1;
    int F_2=2;
    int i=3;
    int a=0;
    if(n==0){
        return 0;
    }else if(n==1){
        return 1;
    }else if(n==2){
        return 2;
    }else{
        while(i<=n){
            a=F_1+F_2;
            F_1=F_2;
            F_2=a;
            i++;
        }
        
    }
    return a;    
}

int main(){
    int a=climbStairs(45);
    printf("%d",a);
    return 0;
}