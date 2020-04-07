/* 
问题描述：
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:

Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6

解题思路:


*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode {
    int val;
    struct ListNode *next;
};
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
            if(l1->val<=l2->val){
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

struct ListNode* mergeLists(struct ListNode** lists, int low,int high){
    struct ListNode* p;
    if(high-low==1){
        p=mergeTwoLists(lists[low],lists[high]);
    }else if(high-low>1){
        int mid=(high+low)/2;
        struct ListNode* left;
        if(mid-low>0){
            left=mergeLists(lists,low,mid);
        }else{
            left=lists[mid];
        }
        struct ListNode* right;
        if(high-mid>1){
            right=mergeLists(lists,mid+1,high);
        }else{
            right=lists[mid+1];
        }
        p=mergeTwoLists(left,right);
    }
    return p;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    if(listsSize==0){
        return NULL;
    }else if(listsSize==1){
        return lists[0];
    }
    return mergeLists(lists,0,listsSize-1);
}

int main(){
    return 0;
}