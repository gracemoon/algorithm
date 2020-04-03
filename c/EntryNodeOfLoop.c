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
    if(pHead==NULL){
        return NULL;
    }
    ListNode* p1=pHead;
    ListNode* p2;
    if(pHead->next){
        p2=pHead->next;
    }else{
        return NULL;
    }
    
    while(p1 && p2){
        if(p1==p2){
            break;
        }
        if(p2->next){
            if(p2->next->next){
                p2=p2->next->next;
            }else{
                return NULL;
            }
        }else{
            return NULL;
        }
        if(p1->next){
            p1=p1->next;
        }else{
            return NULL;
        }
    }
    return NULL ;
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