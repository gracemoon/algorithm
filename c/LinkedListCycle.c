/* 
问题描述：
Given a linked list, determine if it has a cycle in it.

To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.

 

Example 1:

Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where tail connects to the second node.


Example 2:

Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where tail connects to the first node.


Example 3:

Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.


 

Follow up:

Can you solve it using O(1) (i.e. constant) memory?

解题思路:


*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

bool hasCycle(struct ListNode *head) {
    if(head==NULL){
        return false;
    }
    bool flag=false;
    struct ListNode* p=head;
    struct ListNode* q;
    if(head->next!=NULL){
        q=head->next;
        while(q!=NULL){
            if(q==p){
                flag=true;
                break;
            }
            if(q->next){
                if(q->next->next){
                    q=q->next->next;
                    p=p->next;
                }else{
                    break;
                }
            }else{
                break;
            }
        }
    }
    return flag;
}

struct ListNode *detectCycle(struct ListNode *head) {
    if(head==NULL){
        return false;
    }
    bool flag=false;
    struct ListNode* p=head;
    struct ListNode* q;
    if(head->next!=NULL){
        q=head->next;
        while(q!=NULL){
            if(q==p){
                flag=true;
                break;
            }
            if(q->next){
                if(q->next->next){
                    q=q->next->next;
                    p=p->next;
                }else{
                    break;
                }
            }else{
                break;
            }
        }
    }
    if(flag){
        p=head;
        while(p!=q){
            p=p->next;
            q=q->next;
        }
    }else{
        return NULL;
    }
    return q;
}

int main(){
    int m;
    for(int i=0;i<10;i++){

        printf("the n = %d : %d \n",i,m);
    }
    return 0;
}