/* 
问题描述：
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。

解题思路:


*/

#include <iostream>
#include <vector>
#include "utils/Tree.h"
using namespace std;

TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
    TreeNode* node=createTreeNode('a',pre[0]);
    vector<int> pre_left;
    vector<int> vin_left;
    vector<int> pre_right;
    vector<int> vin_right;
    int flag=0;
    for(int i=0;i<vin.size();i++){
        if(vin[i]==pre[0]){
            flag=1;
        }else{
            if(flag==0){
                pre_left.push_back(pre[i+1]);
                vin_left.push_back(vin[i]);
            }else{
                pre_right.push_back(pre[i]);
                vin_right.push_back(vin[i]);
            }
        }
    }
    if(pre_left.size()>0){
        node->left=reConstructBinaryTree(pre_left,vin_left);
    }
    if(pre_right.size()>0){
        node->right=reConstructBinaryTree(pre_right,vin_right);
    }
    
    return node;
}

int main(){
    vector<int> pre={1,2,4,7,3,5,6,8};
    vector<int> vin={4,7,2,1,5,3,8,6};

    TreeNode* tree=reConstructBinaryTree(pre,vin);
    traveralTree(tree);
    return 0;
}