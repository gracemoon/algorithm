/* 
问题描述：
给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。

解题思路:


*/

#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include "utils/List.h"

ListNode* EntryNodeOfLoop(ListNode* pHead)
{
    ListNode* p=pHead;
    while(p){
        ListNode* t=pHead;
        while(p!=t){
            if(p->next==t){
                return t;
            }else{
                t=t->next;
            }
        }
        p=p->next;
    }
    return NULL;
}

int main(){
    ListNode* head;
    ListNode* p;
    for(int i=0;i<10;i++){
        ListNode* node=(ListNode*)malloc(sizeof(ListNode));
        node->value=i;
        
        if(i==0){
           node->next=NULL; 
            head=p=node;
        }else if(i==9){
            node->next=head->next->next;
            p->next=node;
        }else{
            p->next=node;
            p=node;
        }
    }
    ListNode* entryNode=EntryNodeOfLoop(head);
    printf("%d",entryNode->value);
    return 0;
}