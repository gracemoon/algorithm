/* 
问题描述：
请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，
第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。

解题思路： 

*/

#include <iostream>
#include <vector>
using namespace std;

typedef struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

typedef struct QueueNode{
    struct TreeNode* value;
    struct QueueNode* next;
    int level;
}QueueNode;

typedef struct Queue{
    struct QueueNode* head;
    struct QueueNode* tail;
}Queue;

class Solution{
public:

    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> m;
        if(pRoot==NULL){
            return m;
        }
        Queue* queue;
        QueueNode* queueNode=(QueueNode*)malloc(sizeof(QueueNode));
        queueNode->value=pRoot;
        queueNode->next=NULL;
        queueNode->level=0;
        queue->head=queueNode;
        queue->tail=queueNode;
        while(queue->head!=queue->tail){
            if(queue->head->level>=m.size()){
                vector<int> level_m;
                m.push_back(level_m);
            }
            m[queue->head->level].push_back(queue->head->value->val);
            if(queue->head->value->left){
                QueueNode* queueNode=(QueueNode*)malloc(sizeof(QueueNode));
                queueNode->value=queue->head->value->left;
                queueNode->next=NULL;
                queueNode->level=queue->head->level+1;
                queue->tail->next=queueNode;
                queue->tail=queueNode;
            }
            if(queue->head->value->right){
                QueueNode* queueNode=(QueueNode*)malloc(sizeof(QueueNode));
                queueNode->value=queue->head->value->right;
                queueNode->next=NULL;
                queueNode->level=queue->head->level+1;
                queue->tail->next=queueNode;
                queue->tail=queueNode;
            }
            queue->head=queue->head->next;
        }
        for(int i=0;i<m.size();i++){
            if(i%2==1){
                for(int j=0,k=m[i].size()-1;j<k;j++,k--){
                    int temp=m[i][j];
                    m[i][j]=m[i][k];
                    m[i][k]=temp;
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
