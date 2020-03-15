/* 
问题描述：
输入一棵二叉树，判断该二叉树是否是平衡二叉树。

解题思路:


*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "utils/Tree.h"

int TreeDepth(TreeNode* pRoot)
{
    if(pRoot==NULL){
        return 0;
    }
    int depth=1;
    int left_depth=TreeDepth(pRoot->left);
    int right_depth=TreeDepth(pRoot->right);
    if(left_depth>=right_depth){
        depth+=left_depth;
    }else{
        depth+=right_depth;
    }
    return depth;
}

bool IsBalanced_Solution(TreeNode* pRoot) {
    if(pRoot==NULL){
        return true;
    }
    int left_depth=TreeDepth(pRoot->left);
    int right_depth=TreeDepth(pRoot->right);
    bool center=false;
    if(abs(left_depth-right_depth)<=1){
        center=true;
    }
    bool left=IsBalanced_Solution(pRoot->left);
    bool right=IsBalanced_Solution(pRoot->right);

    if(left && right && center){
        return true;
    }
    return false;
}

int main(){
    int m;
    for(int i=0;i<10;i++){

        printf("the n = %d : %d \n",i,m);
    }
    return 0;
}