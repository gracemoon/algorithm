/* 
问题描述：
输入两棵二叉树A，B，判断B是不是A的子结构。(ps：我们约定空树不是任意一个树的子结构)
如果是返回true,否则false

解题思路:
遍历A节点，找到与B根节点值相同的节点，然后同步遍历子节点，看所有节点的值是否都相同。

*/

#include <stdio.h>
#include <stdbool.h>
#include "utils/Tree.h"

/* 
C语言中数组作为形参，如果是多维数组，第一维的长度可以省略。
C语言中数组其实是一个地址，传递实参的时候，并不检测长度，而是传递地址指针。
 */
char* str="abcdefghij";
int array[10]={1,2,3,4,5,6,7,8,9,10};
int length=10;
int current=0;
TreeNode* createTree(){
    TreeNode* node;
    if(length>current){
       node=createTreeNode(str[current],array[current]); 
       current+=1;
       node->left=createTree();
       current+=1;
       node->right=createTree();
       
    }else{
        return NULL;
    }
    
    return node;
}

bool Subtree(TreeNode* pRoot1, TreeNode* pRoot2){
    if(pRoot1!=NULL && pRoot2!=NULL){
        bool flag_left;
        bool flag_right;
        if(pRoot1->val==pRoot2->val){
            flag_left=Subtree(pRoot1->left,pRoot2->left);
            flag_right=Subtree(pRoot1->right,pRoot2->right);
            if(flag_left==true && flag_right==true){
                return true;
            }
        }
    }else if(pRoot1==NULL && pRoot2==NULL){
        return true;
    }
    
    return false;
    
}

bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2){
    if(pRoot1==NULL || pRoot2==NULL){
        return false;
    }
    bool left;
    bool right;
    if(pRoot1->val==pRoot2->val){
        left=Subtree(pRoot1->left,pRoot2->left);
        right=Subtree(pRoot1->right,pRoot2->right);
        if(left==true && right==true){
            return true;
        }
    }
    left=HasSubtree(pRoot1->left,pRoot2);
    right=HasSubtree(pRoot1->right,pRoot2);
    if(left==true || right==true){
        return true;
    }
    
    
    return false;

}



int main(){
    TreeNode* root=createTree();
    current=0;
    TreeNode* root1=createTree();
    traveralTree(root);
    traveralTree(root1);
    if(HasSubtree(root,root1)){
        printf("yes");
    }else{
        printf("no");
    }
    return 0;
}
