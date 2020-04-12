/* 
问题描述：
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its depth = 3.

解题思路:


*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>


// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


int depthCount(struct TreeNode* root,int depth){
    int local_depth;
    if(root==NULL){
        local_depth=depth;
    }else{
        int left_depth=depthCount(root->left,depth+1);
        int right_depth=depthCount(root->right,depth+1);
        if(left_depth>right_depth){
            depth=left_depth;
        }else{
            depth=right_depth;
        }
    }
    return depth;
}

int maxDepth(struct TreeNode* root){
    return depthCount(root,0);
}

int main(){
    int m;
    for(int i=0;i<10;i++){

        printf("the n = %d : %d \n",i,m);
    }
    return 0;
}