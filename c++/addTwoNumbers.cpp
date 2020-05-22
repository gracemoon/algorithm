/* 
问题描述：


解题思路： 

*/

#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p1=l1;
        ListNode* p2=l2;
        int index=0;
        ListNode* head=NULL;
        ListNode* p=NULL;
        int left;
        int right;
        while(p1!=NULL || p2!=NULL || index==1){
            if(p1!=NULL){
                left=p1->val;
            }else{
                left=0;
            }
            if(p2!=NULL){
                right=p2->val;
            }else{
                right=0;
            }
            int local=right+left+index;
            if(local>=10){
                local=local-10;
                index=1;
            }else{
                index=0;
            }
            ListNode* node=new ListNode(local);
            if(head==NULL){
                p=node;
                head=node;
            }else{
                p->next=node;
                p=node;
            }
            if(p1!=NULL){
                p1=p1->next;
            }
            if(p2!=NULL){
                p2=p2->next;
            }
        }
        return head;
    }
};

int main(){
    Solution s;
    return 0;
}
