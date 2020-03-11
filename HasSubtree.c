/* 
问题描述：
输入两棵二叉树A，B，判断B是不是A的子结构。(ps：我们约定空树不是任意一个树的子结构)
如果是返回true,否则false

解题思路:
遍历A节点，找到与B根节点值相同的节点，然后同步遍历子节点，看所有节点的值是否都相同。

*/

#include <stdio.h>

int main(){
    int m;
    for(int i=0;i<10;i++){

        printf("the n = %d : %d \n",i,m);
    }
    return 0;
}