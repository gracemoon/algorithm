/* 
问题描述：
Given a linked list, rotate the list to the right by k places, where k is non-negative.

Example 1:

Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL
Example 2:

Input: 0->1->2->NULL, k = 4
Output: 2->0->1->NULL
Explanation:
rotate 1 steps to the right: 2->0->1->NULL
rotate 2 steps to the right: 1->2->0->NULL
rotate 3 steps to the right: 0->1->2->NULL
rotate 4 steps to the right: 2->0->1->NULL

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


struct ListNode* rotateRight(struct ListNode* head, int k){
    if(head==NULL){
        return head;
    }
    struct ListNode* p=head;
    struct ListNode* t=head->next;
    int length=1;
    while(t!=NULL){
        p=p->next;
        t=t->next;
        length++;
    }
    k=length-k%length;
    p->next=head;
    t=head;
    while(k>0){
        p=p->next;
        t=t->next;
        k--;
    }
    head=t;
    p->next=NULL;
    return head;
}

int main(){
    struct ListNode* head=NULL;
    struct ListNode* p=NULL;
    for(int i=0;i<5;i++){
        struct ListNode* node=(struct ListNode*)malloc(sizeof(struct ListNode));
        node->val=i+1;
        node->next=NULL;
        if(head==NULL){
            head=p=node;
        }else{
            p->next=node;
            p=node;
        }
    }
    head=rotateRight(head,2);
    for(int j=0;j<5;j++){
        printf("%d\t",head->val);
        head=head->next;
    }
    return 0;
}