/* 
问题描述：
输入一颗二叉树的根节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
(注意: 在返回值的list中，数组长度大的数组靠前)

解题思路： 

*/

#include <iostream>
#include <vector>
using namespace std;

typedef struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
}TreeNode;

class Solution{
public:
    vector<vector<int>> path(TreeNode* root,vector<vector<int>> m,vector<int> a){
        a.push_back(root->val);
        if(root->left==NULL && root->right==NULL){
            m.push_back(a);
        }else{
            if(root->left){
                m=path(root->left,m,a);
            }
            if(root->right){
                m=path(root->right,m,a);
            }
        }
        return m;       
    }
    vector<vector<int>> FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int>> m;
        vector<int> a;
        if(root==NULL){
            return m;
        }
        m=path(root,m,a);
        for(int i=0;i<m.size();){
            int local=0;
            for(int j=0;j<m[i].size();j++){
                local+=m[i][j];
            }
            if(local!=expectNumber){
                m.erase(m.begin()+i);
            }else{
                i++;
            }
        }
        for(int i=0;i<m.size();i++){
            for(int j=0;j<m.size()-i-1;j++){
                if(m[j+1].size()>m[j].size()){
                    vector<int> temp=m[j+1];
                    m[j+1]=m[j];
                    m[j]=temp;
                }
            }
        }
        return m;
    }
};

int main(){
    Solution s;
    return 0;
}
