/* 
问题描述：
输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。

解题思路:


*/

#include <stdio.h>

typedef struct TreeNode{
    int val;
	struct TreeNode *left;
	struct TreeNode *right;
}TreeNode;

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

int main(){
    int m;
    for(int i=0;i<10;i++){
        printf("the n = %d : %d \n",i,m);
    }
    return 0;
}