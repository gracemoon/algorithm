/* 
问题描述：
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。

解题思路:
1、中序遍历

*/

#include <stdio.h>

typedef struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
}TreeNode;

TreeNode* Convert(TreeNode* pRootOfTree){
    if(pRootOfTree==NULL){
        return NULL;
    }
    TreeNode* left;
    
    left=Convert(pRootOfTree->left);
    if(left!=NULL){
        TreeNode* temp=left;
        while(temp->right){
            temp=temp->right;
        }
        temp->right=pRootOfTree;
        pRootOfTree->left=temp;
    }else{
        left=pRootOfTree;
    }
    TreeNode* right;
    if(pRootOfTree->right){
        right=Convert(pRootOfTree->right);
        pRootOfTree->right=right;
        right->left=pRootOfTree;
    }
    return left;
}

int main(){
    TreeNode* root=createTree();
    traveralTree(root);
    return 0;
}