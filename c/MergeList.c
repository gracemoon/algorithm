/* 
问题描述：
输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。

解题思路:
1、遍历两个链表，比较大小，找到小的先插入，大的待选。
2、需要head和tail两个指针。
*/

#include <stdio.h>
#include <malloc.h>
#include "utils/List.h"

ListNode* mergeList(ListNode* pHead1, ListNode* pHead2)
{
    ListNode* m;
    ListNode* p;
    ListNode* temp;
    if(pHead1==NULL && pHead2==NULL){
        return NULL;
    }else{
        if(pHead1==NULL){
            p=pHead2;
        }else if(pHead2==NULL){
            p=pHead1;
        }else{
            if(pHead1->value<=pHead2->value){
                p=pHead1;
                pHead1=pHead1->next;
            }else{
                p=pHead2;
                pHead2=pHead2->next;
            }
        }
        
        temp=p;
        m=temp;
    }
    
    while(pHead1!=NULL || pHead2!=NULL){
        if(pHead1==NULL){
            p=pHead2;
            pHead2=pHead2->next;
        }else if(pHead2==NULL){
            p=pHead1;
            pHead1=pHead1->next;
        }else{
            if(pHead1->value<=pHead2->value){
                p=pHead1;
                pHead1=pHead1->next;
            }else{
                p=pHead2;
                pHead2=pHead2->next;
            }
        }
        temp->next=p;
        temp=p;

    }
    return m;
}


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* p;
    struct ListNode* head=(struct ListNode*)malloc(sizeof(struct ListNode));
    p=head;
    while(l1!=NULL || l2!=NULL){
        if(l1==NULL){
            p->next=l2;
            break;
        }else if(l2==NULL){
            p->next=l1;
            break;
        }else{
            if(l1->value<=l2->value){
                p->next=l1;
                p=p->next;
                l1=l1->next;
            }else{
                p->next=l2;
                p=p->next;
                l2=l2->next;
            }
        }
    }
    return head->next;
}



int main(){
    ListNode* head;
    ListNode* temp;
    for(int i=0;i<10;){
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
        i+=2;
    }
    ListNode* head1;
    for(int i=1;i<=10;){
        ListNode* node=(ListNode*)malloc(sizeof(ListNode));
        node->value=i+1;
        node->next=NULL;
        if(i==1){
            head1=node;
            temp=node;
        }else{
            temp->next=node;
            temp=node;
        }
        i+=2;
    }
    traversalListNode(head);
    traversalListNode(head1);
    ListNode* all=mergeList(head,head1);
    traversalListNode(all);
    return 0;
}