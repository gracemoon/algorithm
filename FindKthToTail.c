/* 
问题描述：
输入一个链表，输出该链表中倒数第k个结点。

解题思路:p
1、使用两个指针，p1和p2,p1先跑k-1步,p2跟上,当p1到链表结尾,那么p2也就是要求的倒数第k个节点
2、注意空指针nullptr
*/

#include <stdio.h>
#include <malloc.h>

typedef struct ListNode {
	int value;
	struct ListNode *next;
}ListNode;

ListNode* findKthToTail(ListNode* pListHead, unsigned int k) {
    int m=0;
    ListNode* temp=pListHead->next;
    m+=1;
    while(temp!=NULL){
        temp=temp->next;
        m+=1;
    }
    temp=pListHead;
    for(int i=0;i<m-k;i++){
        temp=temp->next;
    }
    return temp;
}

ListNode* findKthToTailII(ListNode* pListHead, unsigned int k) {
    ListNode* p1=pListHead;
    ListNode* p2=pListHead;
    for(int i=0;i<k;i++){
        p1=p1->next;
    }
    while(p1!=NULL){
        p1=p1->next;
        p2=p2->next;
    }
    return p2;
}

void traversalListNode(ListNode* head){
    ListNode* temp=head;
    while(temp!=NULL){
        printf("%d\n",temp->value);
        temp=temp->next;
    }
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
    traversalListNode(head);
    int k=3;
    ListNode* result=findKthToTailII(head,k);
    printf("the %d node : %d",k,result->value);
    return 0;
}