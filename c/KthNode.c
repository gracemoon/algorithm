/* 
问题描述：
给定一棵二叉搜索树，请找出其中的第k小的结点。
例如， （5，3，7，2，4，6，8）    中，按结点数值大小顺序第三小结点的值为4。

解题思路:


*/

#include <stdio.h>
#include <stdbool.h>
#include "utils/Tree.h"
// typedef struct TreeNode {
//     int val;
//     struct TreeNode *left;
//     struct TreeNode *right;
// }TreeNode;


typedef struct TreeNodeList{
    struct TreeNode* value;
    struct TreeNodeList* next;
}TreeNodeList;

TreeNodeList* traveralTreeLocal(TreeNode* root){
    if(root==NULL){
        return NULL;
    }
    TreeNodeList* center=(TreeNodeList*)malloc(sizeof(TreeNodeList));
    center->value=root;
    center->next=NULL;
    TreeNodeList* head=center;
    TreeNodeList* left_node=traveralTreeLocal(root->left);
    if(left_node!=NULL){
        TreeNodeList* p=left_node;
        while(p->next){
            p=p->next;
        }
        p->next=center;
        head=left_node;
    }
    TreeNodeList* right_node=traveralTreeLocal(root->right);
    if(right_node!=NULL){
        center->next=right_node;
    }
    return head;
}

TreeNode* KthNode(TreeNode* pRoot, int k){
    TreeNodeList* list=traveralTreeLocal(pRoot);
    TreeNodeList* p=NULL;
    int i=1;
    while(list->next){
        if(i==k){
            p=list;
        }
        i++;
        list=list->next;
    }
    if(p){
        return p->value;
    }
    return NULL;
}

int main(){
    TreeNode* root=createTree();
    TreeNode* knode=KthNode(root,1);
    printf("%d",knode->val);
    return 0;
}