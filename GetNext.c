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
    TreeLinkNode* head=pNode;
    TreeLinkNode* left=GetNext(pNode->left);
    TreeLinkNode* p=left;
    if(p){
        head=left;
        while(p){
            if(p->next){
                p=p->next;
            }else{
                break;
            }
        }
    }
    p->next=pNode;
    TreeLinkNode* right=GetNext(pNode->right);
    pNode->next=right;
    return left
}


int main(){
    int m;
    for(int i=0;i<10;i++){

        printf("the n = %d : %d \n",i,m);
    }
    return 0;
}