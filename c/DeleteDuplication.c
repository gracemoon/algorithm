/* 
问题描述：
在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 
例如，链表1->2->3->3->4->4->5 处理后为 1->2->5

解题思路:


*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
}ListNode;

ListNode* deleteDuplication(ListNode* pHead){
    ListNode* head=NULL;
    ListNode* q=NULL;
    ListNode* p=pHead;
    int duplication=0;
    while(p){
        if(p->next!=NULL){
            if(p->next->val==p->val){
                duplication=1;
                p->next=p->next->next;
            }else{
                if(duplication==0){
                    if(head==NULL){
                        head=q=p;
                        p=p->next;
                    }else{
                        q->next=p;
                        q=p;
                        p=p->next;
                    }
                }else{
                    p=p->next;
                    duplication=0;
                }
            }
        }else{
            if(duplication==0){
                if(head==NULL){
                    head=q=p;
                    p=p->next;
                }else{
                    q->next=p;
                    q=p;
                    p=p->next;
                }
            }else{
                if(head!=NULL){
                    duplication=0;
                    q->next=p->next;
                    p=p->next;
                }else{
                    duplication=0;
                    p=p->next;
                }
                
            }
        }
    }
    return head;
}

int main(){
    int arr[]={1,1};
    ListNode* list=NULL;
    ListNode* p=NULL;
    for(int i=0;i<2;i++){
        ListNode* node=(ListNode*)malloc(sizeof(ListNode));
        node->val=arr[i];
        node->next=NULL;
        if(list==NULL){
            list=p=node;
        }else{
            p->next=node;
            p=node;
        }
    }
    ListNode* head=deleteDuplication(list);
    while(head){
        printf("%d",head->val);
        head=head->next;
    }
    return 0;
}