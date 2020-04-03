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
}TreeNode;

typedef struct Queue{
    struct TreeNode* node;
    struct TreeNode* next;
}Queue;


TreeNode* mirror(TreeNode* pRoot){
    if(pRoot==NULL){
        return pRoot;
    }
    TreeNode* root=(TreeNode*)malloc(sizeof(TreeNode));
    root->val=pRoot->val;
    root->left=NULL;
    root->right=NULL;
    TreeNode* left=NULL;
    TreeNode* right=NULL;
    if(pRoot->left){
        left=mirror(pRoot->left);
    }
    if(pRoot->right){
        right=mirror(pRoot->right);
    }
    root->left=right;
    root->right=left;
    return root;
}

bool traveral(TreeNode* root,TreeNode* mirror){
    if(root->val==mirror->val){
        bool left_bool;
        bool right_bool;
        if(root->left && mirror->left){
            left_bool=traveral(root->left,mirror->left);
        }else if(root->left==NULL && mirror->left==NULL){
            left_bool=true;
        }else{
            return false;
        }
        if(root->right && mirror->right){
            right_bool=traveral(root->right,mirror->right);
        }else if(root->right==NULL && mirror->right==NULL){
            right_bool=true;
        }else{
            return false;
        }
        if(left_bool && right_bool){
            return true;
        }
    }
    return false;
}

bool isSymmetrical(TreeNode* pRoot){
    if(pRoot==NULL){
        return false;
    }
    TreeNode* mirror_root=mirror(pRoot);
    return traveral(pRoot,mirror_root);
}

TreeNode* createTreeNode(int value){
    TreeNode* node=(TreeNode*)malloc(sizeof(TreeNode));
    node->val=value;
    node->left=NULL;
    node->right=NULL;
    return node;
}

void traveralTree(TreeNode* root){
    if(root){
        printf("%d\t",root->val);
        traveralTree(root->left);
        traveralTree(root->right);
    }
}

int array[]={1,2,3,0,0,4,0,0,5,6,0,0,7,0,0};
int length=15;
int current=0;
TreeNode* createTree(){
    TreeNode* node;
    if(length>current){
        if(array[current]!=0){
            node=createTreeNode(array[current]); 
            current+=1;
            node->left=createTree();
            current+=1;
            node->right=createTree();
        }else{
            return NULL;
        }       
    }else{
        return NULL;
    }
    return node;
}


int main(){
    TreeNode* root=createTree();
    TreeNode* mirror_root=mirror(root);
    traveralTree(root);
    printf("-------------------------\n");
    traveralTree(mirror_root);
    bool b=isSymmetrical(root);
    if(b){
        printf("true");
    }else{
        printf("false");
    }
    return 0;
}