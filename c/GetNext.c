/* 
问题描述：


解题思路:


*/

#include <stdio.h>
#include <stdbool.h>

typedef struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
}TreeLinkNode;

TreeLinkNode* GetNext(TreeLinkNode* pNode){
    if(pNode==NULL){
        return NULL;
    }
    if(pNode->right!=NULL){
        TreeLinkNode* local_node=pNode->right;
        while(local_node->left){
            local_node=local_node->left;
        }
        return local_node;
    }else{
        if(pNode->next!=NULL){
            TreeLinkNode* parent=pNode->next;
            //左子节点
            if(parent->left==pNode){
                return parent; 
            }
            //右子节点
            if(parent->right==pNode){
                if(parent->next!=NULL){
                    TreeLinkNode* grand_parent=parent->next;
                    if(grand_parent->left==parent){
                        return parent->next;
                    }
                    if(grand_parent->right==parent){
                        return NULL;
                    }
                }else{
                    return NULL;
                }
            }
        }else{
            return NULL;
        }
        
    }
    return NULL;
}


int main(){
    int m;
    for(int i=0;i<10;i++){

        printf("the n = %d : %d \n",i,m);
    }
    return 0;
}