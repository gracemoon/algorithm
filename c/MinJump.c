#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>

/* 
问题描述：
示例 1：

输入：jump = [2, 5, 1, 1, 1, 1]

输出：3

解释：小 Z 最少需要按动 3 次弹簧，小球依次到达的顺序为 0 -> 2 -> 1 -> 6，最终小球弹出了机器。

解题思路:
*/

int jumpfunc(int* jump,int jumpSize,int index,int *step){
    *step=*step+1;
    for(int i=0;i<=index;i++){
        if(i+jump[i]>=jumpSize){
            return 1;
        }
        int ans=jumpfunc(jump,jumpSize,jump[i],);
        if(ans==1){
            break;
        }
    }
}

int minJump(int* jump, int jumpSize){
    int step=0;
    jumpfunc(jump,jumpSize,0,step);  
    return step;  
}

int main(){
    int m;
    for(int i=0;i<10;i++){

        printf("the n = %d : %d \n",i,m);
    }
    return 0;
}