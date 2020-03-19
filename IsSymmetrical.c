/* 
问题描述：
请实现一个函数，用来判断一颗二叉树是不是对称的。注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。

解题思路:


*/

#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    struct 
}TreeNode;



bool isSymmetrical(TreeNode* pRoot){
    if(pRoot==NULL){
        return false;
    }


}

int main(){
    int m;
    for(int i=0;i<10;i++){

        printf("the n = %d : %d \n",i,m);
    }
    return 0;
}