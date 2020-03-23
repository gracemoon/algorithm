/* 
问题描述：
操作给定的二叉树，将其变换为源二叉树的镜像。

解题思路:
1、二叉树左右子树交换。

*/

#include <stdio.h>
#include "utils/Tree.h"

char* str="abcdefghij";
int array[10]={1,2,3,4,5,6,7,8,9,10};
int length=10;
int current=0;
TreeNode* createTree(){
    TreeNode* node;
    if(length>current){
       node=createTreeNode(str[current],array[current]); 
       current+=1;
       node->left=createTree();
       current+=1;
       node->right=createTree();
       
    }else{
        return NULL;
    }
    
    return node;
}

void Mirror(TreeNode *pRoot) {
    if(pRoot!=NULL){
        TreeNode* temp=pRoot->left;
        pRoot->left=pRoot->right;
        pRoot->right=temp;
        Mirror(pRoot->left);
        Mirror(pRoot->right);
    }
}


int main(){
    TreeNode* root=createTree();
    traveralTree(root);
    Mirror(root);
    traveralTree(root);
    return 0;
}