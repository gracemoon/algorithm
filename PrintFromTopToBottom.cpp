/* 
问题描述：
从上往下打印出二叉树的每个节点，同层节点从左至右打印。

解题思路:
1、层次遍历，需要一个队列辅助。

*/

#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdbool.h>
#include "utils/Tree.h"
using namespace std;

char* str="abd##e##cf##g";
int array[13]={1,2,4,0,0,5,0,0,3,6,0,0,7};
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

vector<int> PrintFromTopToBottom(TreeNode* root) {
    vector<int> result;
    vector<TreeNode*> sequence;
    if(root!=NULL){
        sequence.push_back(root);
    }
    int x=0;
    while(x<sequence.size()){
        TreeNode* temp=sequence[x];
        result.push_back(temp->val);
        x++;
        if(temp->left!=NULL){
            sequence.push_back(temp->left);
        }
        if(temp->right!=NULL){
            sequence.push_back(temp->right);
        }
    }
    return result;
}

int main(){
    TreeNode* root=createTree();
    traveralTree(root);
    vector<int> result=PrintFromTopToBottom(root);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<endl;
    }
    return 0;
}