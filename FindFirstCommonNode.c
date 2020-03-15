/* 
问题描述：
输入两个链表，找出它们的第一个公共结点。
（注意因为传入数据是链表，所以错误测试数据的提示是用其他方式显示的，保证传入数据是正确的）

解题思路:


*/

#include <stdio.h>
#include "utils/List.h"

ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
    ListNode* p1=pHead1;
    
    while(p1){
        ListNode* p2=pHead2;
        while(p2){
            if(p1==p2){
                return p1;
            }else{
                p2=p2->next;
            }
        }
        p1=p1->next;
    }
    return NULL;
}

int main(){
    int m;
    for(int i=0;i<10;i++){

        printf("the n = %d : %d \n",i,m);
    }
    return 0;
}