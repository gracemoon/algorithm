/* 
问题描述：
Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

Example 1:

Input: [1,2,3]

       1
      / \
     2   3

Output: 6
Example 2:

Input: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

Output: 42

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

// int maxPath(struct TreeNode* root,int pre){
//     int max=root->val;
//     int next=0;
//     if(root->val>=0 && pre+root->val>0){
//         next=pre+root->val;
//     }
//     if(root->val+pre>root->val){
//         max=root->val+pre;
//     }
//     if(root->left!=NULL){
//         int left=maxPath(root->left,next);
//         if(left>max){
//             max=left;
//         }
//     }
//     if(root->right!=NULL){
//         int right=maxPath(root->right,next);
//         if(right>max){
//             max=right;
//         }
//     }
//     return max;
// }

int m;
int maxPath(struct TreeNode* root){
    int max;
    int center;
    int left;
    int pre=0;
    if(root->left!=NULL){
        left=maxPath(root->left);
        if(root->val>root->val+left){
            center=root->val;
        }else{
            center=root->val+left;
        }
        if(left>root->val){
            if(left>(left+root->val)){ 
                max=left;
            }else{
                max=left+root->val;
                pre=max;
            }
        }else{
            if(root->val>(left+root->val)){
                max=root->val;
            }else{
                max=left+root->val;
                pre=max;
            }
        }
    }else{
        center=root->val;
        max=root->val;
        pre=max;
    }
    int right;
    if(root->right!=NULL){
        right=maxPath(root->right);
        if(right>max){
            if(right>(right+center)){ 
                max=right;
                pre=0;
            }else{
                max=right+center;
                pre=max;
            }
        }else{
            if(right+center>max){
                max=right+center;
                pre=max;
            }
        }
    }
    if(max>m){
       m=max; 
    }    
    return pre;
}
int maxPathSum(struct TreeNode* root){
    m=root->val;
    maxPath(root);
    return m;
}

int main(){
    return 0;
}