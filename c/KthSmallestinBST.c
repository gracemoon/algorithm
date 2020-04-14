/* 
问题描述：
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note:
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Example 1:

Input: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
Output: 1
Example 2:

Input: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
Output: 3
Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?

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

//        5
//       / \
//      3   6
//     / \
//    2   4
//   /
//  1

void findkth(struct TreeNode* root,int k,int* p,int* count){
    if(root!=NULL){
        findkth(root,k,p,count);
        *count=*count+1;
        if(*count==k){
            *p=root->val;
        }else{
            
        }
        findkth(root,k,p,count);
    }
}

int kthSmallest(struct TreeNode* root, int k){
    int* p=(int*)malloc(sizeof(int));
    int* count=(int*)malloc(sizeof(int));
    *count=0;
    findkth(root,k,p,count);
    return *p;
}

int main(){
    int m;
    for(int i=0;i<10;i++){

        printf("the n = %d : %d \n",i,m);
    }
    return 0;
}