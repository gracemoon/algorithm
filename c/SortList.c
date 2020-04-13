/* 
问题描述：
Sort a linked list in O(n log n) time using constant space complexity.

Example 1:

Input: 4->2->1->3
Output: 1->2->3->4
Example 2:

Input: -1->5->3->4->0
Output: -1->0->3->4->5

解题思路:


*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>

// Definition for singly-linked list.
typedef struct ListNode {
    int val;
    struct ListNode *next;
}ListNode;

void quickSort(int* arr,int low,int high){
    int x=low;
    int y=high;
    x++;
    while(x<=y){
        if(arr[x]>arr[low] && arr[y]<arr[low]){
            swap(&arr[x],&arr[y]);
            x++;
            y--;
        }
        if(arr[x]<=arr[low]){
            x++;
        }
        if(arr[y]>=arr[low]){
            y--;
        }
    }
    swap(&arr[low],&arr[y]);
    if(y-1>low){
        quickSort(arr,low,y-1);
    }
    if(high>x){
        quickSort(arr,x,high);
    }
}

struct ListNode* sortList(ListNode* head){
    int* p;
    ListNode* q=head;
    int length=0;
    while(q!=NULL){
        length++;
        q=q->next;
    }
    p=(int*)malloc(sizeof(int)*length);
    q=head;
    int i=0;
    while(q!=NULL){
        p[i++]=q->val;
        q=q->next;
    }
    quickSort(p,0,length-1);
    q=head;
    i=0;
    while(q!=NULL){
        q->val=p[i++];
        q=q->next;
    }
    return head;
}

ListNode* MergeSort(struct ListNode* head,int length){
    
    return head;
}

struct ListNode* sortList(struct ListNode* head){
    ListNode* q=head;
    int length=0;
    while(q!=NULL){
        length++;
        q=q->next;
    }

}


int main(){
    int m;
    for(int i=0;i<10;i++){

        printf("the n = %d : %d \n",i,m);
    }
    return 0;
}