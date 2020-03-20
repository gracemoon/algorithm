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


char* str="abd##e##cf##g";
int array[13]={10,2,4,0,0,5,0,0,3,6,0,0,7};
int length=13;
int current=0;
TreeNode* createTree(){
    TreeNode* node;
    if(length>current){
        if(str[current]!='#'){
            node=createTreeNode(str[current],array[current]); 
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

#endif