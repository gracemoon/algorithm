/* 
问题描述：
从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。

解题思路： 

*/

#include <iostream>
#include <vector>
#include <malloc.h>
#include "utils/Tree.h"
using namespace std;

// typedef struct TreeNode {
//     int val;
//     struct TreeNode *left;
//     struct TreeNode *right;
// }TreeNode;



class Solution{
public:
    typedef struct Queue{
        TreeNode* value;
        Queue* next;
        int level;
    }Queue;
    vector<vector<int>> Print(TreeNode* pRoot) {
        vector<vector<int>> m;
        if(pRoot==NULL){
            return m;
        }
        
        Queue* head=(Queue*)malloc(sizeof(Queue));
        head->value=pRoot;
        head->next=NULL;
        head->level=0;
        Queue* tail=head;
        while(head!=tail->next){
            if(head->level>=m.size()){
                vector<int> a;
                m.push_back(a);
            }
            m[head->level].push_back(head->value->val);
            if(head->value->left){
                Queue* node=(Queue*)malloc(sizeof(Queue));
                node->level=head->level+1;
                node->next=NULL;
                node->value=head->value->left;
                tail->next=node;
                tail=node;
            }
            if(head->value->right){
                Queue* node=(Queue*)malloc(sizeof(Queue));
                node->level=head->level+1;
                node->next=NULL;
                node->value=head->value->right;
                tail->next=node;
                tail=node;
            }
            head=head->next;
        }
        return m;
    }
};

int main(){
    Solution s;
    TreeNode* root=createTree();
    traveralTree(root);
    vector<vector<int>> m=s.Print(root);
    for(int i=0;i<m.size();i++){
        for(int j=0;j<m[i].size();j++){
            cout<<m[i][j]<<", ";
        }
        cout<<endl;
    }
    return 0;
}
