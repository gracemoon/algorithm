/* 
问题描述：
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Given the following binary tree:  root = [3,5,1,6,2,0,8,null,null,7,4]


Example 1:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.
Example 2:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
 

Note:

All of the nodes' values will be unique.
p and q are different and both values will exist in the binary tree.

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

bool find(struct TreeNode* root,struct TreeNode* p, struct TreeNode* q,struct TreeNode* returnNode){
    if(root==NULL){
        return false;
    }
    bool left=false;
    if(root->left){
        left=find(root,p,q,returnNode);
    }
    bool right=false;
    if(root->right){
        right=find(root,p,q,returnNode);
    }
    if(left && right){
        returnNode=root;
        return false;
    }else if(left || right){
        if(root->val==p->val || root->val==q->val){
            returnNode=root;
            return false;
        }else{
            if(left){
                root->val=root->left->val;
                return true;
            }else{
                root->val=root->right->val;
                return true;
            }
        }
    }else{
        if(root->val==p->val || root->val==q->val){
            return true;
        }
    } 
    return false;
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    struct TreeNode* returnNode;
    find(root,p,q,returnNode);
    return returnNode;
}

int main(){
    int m;
    for(int i=0;i<10;i++){

        printf("the n = %d : %d \n",i,m);
    }
    return 0;
}