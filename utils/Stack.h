#ifndef STACK
#define STACK
#include <malloc.h>
typedef struct StackNode{
    int value;
    char c;
    struct StackNode* next;
    
}StackNode;

typedef struct Stack{

    struct StackNode* stack;

    void push(int value,char c) {
        StackNode* node=(StackNode*)malloc(sizeof(StackNode));
        node->value=value;
        node->c=c;
        node->next=stack;
        stack=node;
    }
    void pop() {
        if(stack!=NULL){
            stack=stack->next;
        }
    }

    StackNode* top(){
        if(stack){
            return stack;
        }
        return NULL;
    }

}Stack;




#endif