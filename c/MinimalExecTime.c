/* 
问题描述：





解题思路:


*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>

//  Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

double minimalExecTime(struct TreeNode* root){
    if(root==NULL){
        return 0;
    }
    int time_left=0;
    if(root->left){
        time_left=minimalExecTime(root->left);
    }
    int time_right=0;
    if(root->right){
        time_right=minimalExecTime(root->right);
    }
    
    
}

int main(){
    int m;
    for(int i=0;i<10;i++){

        printf("the n = %d : %d \n",i,m);
    }
    return 0;
}