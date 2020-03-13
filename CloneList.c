/* 
问题描述：
输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），
返回结果为复制后复杂链表的head。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）

解题思路:
1、不要应用参数中的节点引用，是指对每个节点重新malloc出内存。

*/

#include <stdio.h>
#include <malloc.h>
typedef struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
}RandomListNode;

void traversalListNode(RandomListNode* head){
    RandomListNode* temp=head;
    while(temp!=NULL){
        printf("%d\n",temp->label);
        temp=temp->next;
    }
};

RandomListNode* Clone(RandomListNode* pHead){
    RandomListNode* p=pHead;
    while(p){
        RandomListNode* temp=(RandomListNode*)malloc(sizeof(RandomListNode));
        temp->label=p->label;
        temp->next=NULL;
        temp->random=NULL;
        temp->next=p->next;
        p->next=temp;
        p=temp->next;
    }

    p=pHead;
    while(p){
        if(p->random){
            p->next->random=p->random->next;
        }
        p=p->next->next;
    }
    
    p=pHead;
    RandomListNode* clone=pHead->next;
    while(p){
        RandomListNode* temp=p->next->next;
        if(temp!=NULL){
            p->next->next=temp->next;
        }else{
            p->next->next=NULL;
        }
        p->next=temp;
        p=temp;
    }
    
    return clone;
}

int main(){
    int a[5]={1,2,3,4,5};
    int b[5]={3,5,0,2,0};
    RandomListNode* head;
    RandomListNode* tail;
    for(int i=0;i<5;i++){
        
        RandomListNode* node=(RandomListNode*)malloc(sizeof(RandomListNode));
        node->label=a[i];
        node->next=NULL;
        node->random=NULL;
        if(i==0){
            head=node;
            tail=node;
        }else{
            tail->next=node;
            tail=node;
        }
    }
    tail=head;
    int j=0;
    while(tail){
        RandomListNode* temp=head;
        while(temp){
            if(b[j]==temp->label){
                tail->random=temp;
                break;
            }else{
                temp=temp->next;
            }
        }
        tail=tail->next;
        j++;
    }
    tail=head;
    while(tail){
        if(tail->random){
            printf("%d ---- %d \n",tail->label,tail->random->label); 
        }else{
            printf("%d ---- %d \n",tail->label,0); 
        }
        tail=tail->next;
    }
    RandomListNode* clone=Clone(head);
    tail=clone;
    while(tail){
        if(tail->random){
            printf("%d ---- %d \n",tail->label,tail->random->label); 
        }else{
            printf("%d ---- %d \n",tail->label,0); 
        }
        tail=tail->next;
    }
    return 0;
}