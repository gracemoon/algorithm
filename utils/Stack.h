#ifndef STACK
#define STACK
#include <malloc.h>
typedef struct StackNode{
    int value;
    struct StackNode* next;
    
}StackNode;

typedef struct Stack{

    struct StackNode* stack;

    void push(int value) {
        StackNode* node=(StackNode*)malloc(sizeof(StackNode));
        node->value=value;
        node->next=stack;
        stack=node;
    }
    void pop() {
        if(stack!=NULL){
            stack=stack->next;
        }
    }
    int top() {
        if(stack){
            return stack->value;
        }
        return -1;
    }

}Stack;




#endif