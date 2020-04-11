/* 
问题描述：
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?
Example 1:

Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Right -> Down
2. Right -> Down -> Right
3. Down -> Right -> Right
Example 2:

Input: m = 7, n = 3
Output: 28
 

Constraints:

1 <= m, n <= 100
It's guaranteed that the answer will be less than or equal to 2 * 10 ^ 9.

解题思路:


*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>

// int iterateWalk1(int m,int n,int x,int y){
//     int a=0;
//     if(x==m-1 && y==n-1){
//         a=1;
//     }
//     if(x<m-1){
//         a=a+iterateWalk1(m,n,x+1,y);
//     }
//     if(y<n-1){
//         a=a+iterateWalk1(m,n,x,y+1);
//     }
//     return a;
// }


// int index=0;
// void iterateWalk(int m,int n,int x,int y){
//     if(x==m-1 && y==n-1){
//         index++;
//     }
//     if(x<m-1){
//         iterateWalk(m,n,x+1,y);
//     }
//     if(y<n-1){
//         iterateWalk(m,n,x,y+1);
//     }
// }

int uniquePaths(int m, int n){
    int sum=m+n-2;
    int lower;
    if(m>n){
        lower=n-1;
    }else{
        lower=m-1;
    }
    int a=1;
    
    for(int i=0;i<lower;i++){
        a*=(i+1);
    }
    int flag=0;
    int count=1;
    for(int i=0;i<lower;i++){
        count*=(sum-i);
        if(count>=a && flag==0 && count%a==0){
            count/=a;
            flag=1;
        }
    }
    return count;
}


int main(){
    int m=5;
    int n=5;
    int sum=uniquePaths(m,n);
    printf("%d",sum);
    return 0;
}