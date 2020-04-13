/* 
问题描述：
输入一个链表，反转链表后，输出新链表的表头。

解题思路:
对于链表而言，表头即代表整个链表，输出表头就是输出整个链表，不是表头结点

*/

#include <stdio.h>
#include <malloc.h>
#include "utils/List.h"

// ListNode* reverseList(ListNode* pHead) {
//         if(pHead==NULL){
//             return NULL;
//         }
//         ListNode* p=pHead;
        
//         ListNode* p1=pHead->next;
//         p->next=NULL;
//         while(p1){
//             ListNode* temp=p;
//             p=p1;
//             p1=p1->next;
//             p->next=temp;
//         }
//         return p;
//     }



//Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* reverseList(struct ListNode* head){
    struct ListNode* p=head;
    while(p!=NULL){
        if(p!=head){
            struct ListNode* q=p->next;
            p->next=head;
            head=p;
            p=q;
        }
        p=p->next;
    }
    return head;
}


int main(){
    ListNode* head;
    ListNode* temp;
    for(int i=0;i<10;i++){
        ListNode* node=(ListNode*)malloc(sizeof(ListNode));
        node->value=i+1;
        node->next=NULL;
        if(i==0){
            head=node;
            temp=node;
        }else{
            temp->next=node;
            temp=node;
        }
    }
    ListNode* tail= reverseList(head);
    traversalListNode(tail);

    return 0;
}