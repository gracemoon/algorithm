#ifndef TREE
#define TREE
#include <malloc.h> 
typedef struct TreeNode{
    int val;
    char value;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

TreeNode* createTreeNode(char c,int value){
    TreeNode* node=(TreeNode*)malloc(sizeof(TreeNode));
    node->value=c;
    node->val=value;
    node->left=NULL;
    node->right=NULL;
    return node;
}

void traveralTree(TreeNode* root){
    if(root){
        printf("%c---%d\n",root->value,root->val);
        traveralTree(root->left);
        traveralTree(root->right);
    }
}

#endif