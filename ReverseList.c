/* 
问题描述：
输入一个链表，反转链表后，输出新链表的表头。

解题思路:


*/

#include <stdio.h>
#include <malloc.h>
#include "utils/List.h"

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
    traversalListNode(head);

    return 0;
}