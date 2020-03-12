/* 
问题描述：
定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。
注意：保证测试中不会当栈为空的时候，对栈调用pop()或者min()或者top()方法。

解题思路:
1、时间复杂度为O(1),有一个index,一直指向min。

*/

#include <stdio.h>
#include <malloc.h>

typedef struct StackNode{
    int value;
    struct StackNode* next;
}StackNode;


StackNode* stack=NULL;
StackNode* minNode=NULL;
void push(int value) {
    StackNode* node=(StackNode*)malloc(sizeof(StackNode));
    node->value=value;
    node->next=stack;
    stack=node;
    if(minNode==NULL){
        minNode=node;
    }else if(minNode->value>node->value){
        minNode=node;
    }
}

void traversalStack(){
    StackNode* temp=stack;
    minNode=stack;
    while(temp){
        if(minNode->value>temp->value){
            minNode=temp;
        }
        temp=temp->next;
    }
}

void pop() {
    if(stack!=NULL){
        stack=stack->next;
        traversalStack();
    }
}
int top() {
    if(stack){
        return stack->value;
    }
    return -1;
}
int min() {
    if(stack!=NULL){
        return minNode->value;
    }
    return -1;
}

int main(){
    for(int i=0;i<10;i++){
        push(i);
    }
    printf("%d",min());

    return 0;
}